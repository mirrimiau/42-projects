/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:53:56 by mapostol          #+#    #+#             */
/*   Updated: 2022/07/14 15:53:59 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define TRUE		1
# define FALSE		0
# define BUF		100
# define ROOM_BUF	6400
# define MARGIN		0
# define MARGIN_CAP	12
# define CAP		0
# define FD			0
# include "../libft/sources/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_edge
{
	struct s_room	*start;
	struct s_room	*end;
	int				flow_out;
	int				flow_in;
	struct s_edge	*corr_edge;
}	t_edge;

typedef struct s_room
{
	char			*name;
	char			*x;
	char			*y;
	int				start;
	int				terminus;
	int				d;
	struct s_room	*next;
	struct s_room	**connections;
	t_edge			*edges_out[BUF];
	int				i_out;
	t_edge			*edges_in[BUF];
	int				i_in;
	int				connection_count;
	int				index;
	int				reserve;
	struct s_room	*corr_room;
	int				in;
	int				out;
	int				pos;
	int				token;
}	t_room;

typedef struct s_route
{
	unsigned long long	route[BUF];
	struct s_route		*next;
	int					len;
	int					index;
	int					complete;
}	t_route;

typedef struct s_parsed_data
{
	int					ants;
	t_room				*liststart;
	t_route				*routestart;
	int					longest_route;
	int					rooms;
	int					min_bottleneck;
	int					max_turns;
	int					group[ROOM_BUF][ROOM_BUF];
	int					complete_routes;
	int					margin;
	int					linecount;
	t_route				**solution_routes;
	int					solution_i;
	int					margin_cap;
	int					bypass;
	int					verbose;
	int					visual;
	int					quiet;
	t_room				*temp_room;
	t_room				*queue[ROOM_BUF];
	int					queue_len;
	int					i_queue;
}	t_parsed_data;

typedef struct s_foundpath
{
	t_room				*room;
	struct s_foundpath	*next;
	struct s_foundpath	*previous;
	struct s_foundpath	*initial;
	int					len;
}	t_foundpath;
/* error handling: */
void		ft_nuke(char **array);
int			memsafe_gnl(char **line);
void		clean_connectionless_rooms(t_room *first);
void		error_kill(char *reason);
/* initial data reading and parsing */
int			parse_ants(t_parsed_data *data);
int			parse_rooms(t_parsed_data *data, int commentdata, t_room *first);
void		parse_indices(t_parsed_data *data);
t_room		*parse_next_room(char *line, t_room *first,
				int commentdata, t_parsed_data *data);
int			parse_legal_room(t_parsed_data *data,
				int commentdata, t_room *first, char *line);
int			parse_next_connection_mirror(char *name,
				t_room *connection, t_room *room);
void		parse_groups(t_parsed_data *data);
int			parse_data(t_parsed_data *data);
void		parse_distance(t_parsed_data *data);
int			add_connection(t_room *room, char *connection, t_room *first);
void		check_validity(t_parsed_data *data);
int			is_line_comment(char *line);
void		copy_room_array_and_add(t_room **src, t_room **dest, t_room *new);
int			is_room_legal(char *line, t_room *first);
void		connection_validity(t_room *room, t_room *first, char **array);
/* algorithm */
void		find_solution(t_parsed_data *data,
				t_route **solution_routes, t_route *solution);
int			compare_route_to_index(t_route *route, int index);
void		parse_routes(t_parsed_data *data);
void		combine_routes(t_route *src, t_route *dest);
void		calculate_path(t_route *route, t_room *start, t_parsed_data *data);
/* route tools */
int			force_movement(t_parsed_data *data, t_room *src, t_room *dest);
void		extend_routes(t_room *room, t_parsed_data *data);
void		add_state(t_route *route, t_room *room);
int			compare_route_to_index(t_route *route, int index);
t_room		*find_corresponding_room(t_route *route, t_room *start,
				t_room *previous);
t_foundpath	*path_to_linked_list(t_route *route, t_room *start, t_room *terminus);
t_route		*new_route(t_route *routestart);
void		copy_route(t_route *src, t_route *dest);

/* printing */
void		print_solution(t_parsed_data *data);
t_foundpath	*new_foundpath(t_room *room, t_foundpath *next,
				t_foundpath *previous, t_foundpath *initial);
/* debugging and bonus*/
void		write_debug_data(t_room *room, t_parsed_data *data);
void		quiet_mode(t_parsed_data *data, int argv, char **argc);
void		read_additional_arguments(int argv, char **argc,
				t_parsed_data *data);


int		calculate_route_len_ds(t_room *src);
#endif
