/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:35:54 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/20 17:35:57 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/* Headers for libraries and preprocessor macros */
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>

/* Usage */
# define USAGE "Usage: ./corewar [-a] [-dump N] [-d N] [-v N] <[-n N] champion1.cor> <...>\n\
\t############### TEXT OUTPUT MODE ################\n\
\t-a\t: Print aff operation output\n\
\t-dump N\t: Dumps memory to standard output (32 octets per line) after N cycles and \
quits the game\n\
\t-d N\t: Same as -dump, but prints 64 octets per line\n\
\t-v N\t: Set verbose printing options, can be added together:\n\
\t\t  0: Print only essentials\n\
\t\t  1: Print lives\n\
\t\t  2: Print cycles\n\
\t\t  4: Print operations\n\
\t\t  8: Print deaths\n\
\t\t  16: Print PC movements\n\
\t############### CHAMPION OPTIONS ################\n\
\t-n N\t: Sets the champions player number to N"

/* System call related error prefixes (perror emulation) */
# define READ_PREFIX "read(): %s"
# define OPEN_PREFIX "open(): %s"
# define CLOSE_PREFIX "close(): %s"
# define LSEEK_PREFIX "lseek(): %s"
# define MALLOC_PREFIX "malloc(): %s"

/* Champion related errors */
# define PLAYER_NB_TOO_SMALL "Player number too small (%s <= 0)"
# define PLAYER_NB_TOO_BIG "Player number too big (%s > %d)"
# define DUPLICATE_PLAYER_ID "Trying to create champion with duplicate number"
# define TOO_MANY_PLAYERS "Too many champions"
# define NON_SEQUENTIAL_NUMBERS "Player numbers are not sequential"

/* File related errors */
# define FILE_TOO_SMALL "File %s is too small to be a champion"
# define CHAMP_TOO_BIG "File %s has too large a code (%u bytes > %u bytes)"
# define CODE_SIZE_DIFF "File %s has a code size that \
differs from what its header says"
# define HEADER_ERROR "File %s has an invalid header"

/* Option macros, struct, functions and the jump table implemented for them */
# define OPTIONS "dnva"
# define OPTION_COUNT 4

/* Verbose print macros */
# define SHOW_ALIVE 1
# define SHOW_CYCLE 2
# define SHOW_OP 4
# define SHOW_DEATH 8
# define SHOW_MOVE 16

/* Macros describing .cor file standard */
# define HEADER_SIZE 4		/* sizeof(unsigned int) */
# define CODE_SIZE 4		/* sizeof(unsigned int) */
# define NULL_TERM 4		/* the size of null terminators in .cor files */

/* Statement description macros */
# define ARG_COUNT 0
# define WAIT_TIME 1
# define OP_DIR 2
# define C_BYTE 3

/* General macros */
# define BITS_IN_BYTE 8
# define CRUMBS_IN_BYTE 4
# define MAX_UINT 0xFFFFFFFF

typedef struct s_options
{
	int		next_id;
	int		dump;
	int		octets_in_line;
	int		verbose_flags;
	int		aff_flag;
}	t_options;

int				set_player_number(t_options *opts, char *nbr);
int				set_dump(t_options *opts, char *nbr);
int				set_verbose_flag(t_options *opts, char *nbr);
int				set_aff(t_options *opts, char *nbr);

typedef int					(*t_jump_opts)(t_options *, char *);

static const t_jump_opts	g_jump_table[OPTION_COUNT] = {
	set_dump,
	set_player_number,
	set_verbose_flag,
	set_aff
};

/* 0 = number of arguments
1 = wait time */
static const unsigned int	g_op[17][4] = {
{0, 0, 0, 0}, {1, 10, 4, 0}, {2, 5, 4, 1}, {2, 5, 4, 1}, {3, 10, 4, 1},
{3, 10, 4, 1}, {3, 6, 4, 1}, {3, 6, 4, 1}, {3, 6, 4, 1}, {1, 20, 2, 0},
{3, 25, 2, 1}, {3, 25, 2, 1}, {1, 800, 2, 0}, {2, 10, 4, 1},
{3, 50, 2, 1}, {1, 1000, 2, 0}, {1, 2, 4, 1}
};

static const unsigned char	g_arg_types[17][4] = {
{0, 0, 0, 0},
{T_DIR, 0, 0, 0},
{T_DIR | T_IND, T_REG, 0, 0},
{T_REG, T_IND | T_REG, 0, 0},
{T_REG, T_REG, T_REG, 0},
{T_REG, T_REG, T_REG, 0},
{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG, 0},
{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0},
{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0},
{T_DIR, 0, 0, 0},
{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0},
{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG, 0},
{T_DIR, 0, 0, 0},
{T_DIR | T_IND, T_REG, 0, 0},
{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0},
{T_DIR, 0, 0, 0},
{T_REG, 0, 0, 0}
};

/* Struct for champion information */
typedef struct s_champion
{
	int					id;
	unsigned char		name[PROG_NAME_LENGTH + 1];
	unsigned char		comment[COMMENT_LENGTH + 1];
	unsigned int		code_size;
	unsigned char		code[CHAMP_MAX_SIZE];
	struct s_champion	*next;
}	t_champion;

/* Carriage i.e. the offset that "plays the game", moving around memory
	and executing instructions */
typedef struct s_car
{
	unsigned int	index;
	unsigned int	reg[REG_NUMBER + 1];
	unsigned int	pc;
	bool			carry;
	unsigned char	op;
	unsigned int	last_live;
	unsigned int	wait;
	unsigned int	jump;
	bool			alive;
	struct s_car	*next;
}	t_car;

/* Head struct which includes all relevant information for the VM */
typedef struct s_info
{
	unsigned char	memory[MEM_SIZE];
	int				dump_cycles;
	int				dump_line_len;
	int				aff_flag;
	int				champion_count;
	t_champion		champions[MAX_PLAYERS];
	unsigned int	cycle;
	unsigned int	next_check_cycle;
	int				cycles_to_die;
	t_car			*liststart;
	unsigned int	lives_this_check;
	unsigned int	checks_after_mod;
	int				verbose_opts;
	unsigned int	last_live_champ;
	unsigned int	next_car_index;
}				t_info;

/* VM functions */
int				read_arguments(int argc, char **argv, t_info *info);
int				set_player_id(int *id, t_champion ch_list[]);
unsigned int	big_endian_converter(unsigned int src, int size);
void			check_champions(t_champion ch_list[], int ch_count);
void			deploy_champions(unsigned char memory[],
					t_champion ch_list[], int count);
void			error_handler(char *message, char *arg1,
					unsigned int arg2, unsigned int arg3);
void			parse_champion(t_info *info, char *file, int *id);
void			print_usage(char *usage);
void			save_champion(int fd, t_champion *champion, char *file);
void			usage_exit(void);
void			error_kill(char *reason);

/* VM tools */
unsigned char	get_crumb(unsigned char c_byte, int c_number);
unsigned int	get_argument(t_info *info, unsigned char n, t_car *car);
unsigned int	cast_arg_type_to_bytes(unsigned char arg_type,
					unsigned char op);
unsigned int	cat_n_bytes(unsigned char *offset,
					unsigned int bytes, unsigned char memory[]);

/* Game functions */
int				no_cars_alive(t_info *info);
int				run_game(t_info *info);
void			check_aliveness(t_info *info);
void			init_pregame_cars(t_info *info);
void			push_new_car(t_info *info, t_car *parent, int forkjump);

/* Carriage functions */
int				calculate_jump(unsigned char c_byte, unsigned char op);
void			run_all_cars(t_info *info);

/* Print functions */
void			print_memory(unsigned char memory[], int line_len);
void			print_process_id(unsigned int id);

#endif
