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
# define BUF		1000
# define ROOM_BUF	6400
# define FD			0
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_ant
{
	int				index;
	struct s_room	*room;
	struct s_ant	*next;
	int				complete;
	char			*colour;
	char			*shape;
}	t_ant;

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
	int				connection_count;
	t_edge			*edges_out[BUF];
	int				i_out;
	t_edge			*edges_in[BUF];
	int				i_in;
	int				index;
	int				reserve;
	int				pos;
}	t_room;

typedef struct s_route
{
	t_room			*route[BUF];
	struct s_route	*next;
	int				len;
	int				index;
	int				complete;
	t_room			*current;
	t_room			*previous;
}	t_route;

typedef struct s_parsed_data
{
	int					ants;
	t_room				*liststart;
	t_route				*routestart;
	t_ant				*antstart;
	t_room				*start;
	t_room				*terminus;
	int					longest_route;
	int					rooms;
	int					min_bottleneck;
	int					max_turns;
	int					group[ROOM_BUF][ROOM_BUF];
	int					complete_routes;
	int					linecount;
	t_route				*solution_routes[BUF];
	int					solution_i;
	int					verbose;
	int					visual;
	int					quiet;
	int					r;
	t_room				*temp_room;
	int					i_queue;
	int					queue_len;
	t_room				*room_queue[BUF];
	t_route				*route_queue[ROOM_BUF];
	int					exp_res;
	int					buffer;
	int					colour_fd;
	int					shape_fd;
	FILE				*dotfile;
	int					rowstart;
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
void		free_routes(t_parsed_data *data);
void		free_room(t_room *room);
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
void		new_edge_in(t_room *start, t_room *end, t_edge *corr);
t_edge		*new_edge_out(t_room *start, t_room *end);
void		copy_edges(t_room *src, t_room *dest);
int			parse_next_connection(char *line, t_room *room, t_parsed_data *data,
				int flag);
/* algorithm */
void		run_algorithm(t_parsed_data *data);
t_route		*find_augmenting_path(t_parsed_data *data);
void		convert_route_to_flow(t_route *route, t_room *start);
void		check_all_pos(t_room *start);
void		format_map(t_parsed_data *data);
int			calculate_expected_result(t_parsed_data *data, t_room *start);
void		convert_route_to_flow(t_route *route, t_room *start);
void		format_map(t_parsed_data *data);
void		add_to_route_queue(t_parsed_data *data, t_route *temp);
void		clean_unconfirmed_flow(t_room *room);
void		create_solution_map(t_parsed_data *data, t_room *start,
				t_route *route, int exp);
/* route tools */
void		extend_routes(t_room *room, t_parsed_data *data);
t_route		*new_route(t_route *routestart, t_room *current_room,
				t_room *previous_room);
void		copy_route(t_route *src, t_route *dest);
/* printing */
void		print_solution(t_parsed_data *data, t_room *start);
void		refresh_distances(t_parsed_data *data);
void		hand_tickets(t_parsed_data *data);
int			round_of_ants(t_parsed_data *data);
void		move_ant(t_ant *ant, t_parsed_data *data);
int			create_new_ant(t_parsed_data *data, t_room *room);
void		refresh_distances(t_parsed_data *data);
void		bubblesort_starting_edges(t_parsed_data *data, int i, int j);
void		calculate_route_len(t_room *start, t_parsed_data *data,
				t_room *previous, int ret);
/* debugging and bonus*/
void		write_visual_data(t_room *room, t_parsed_data *data);
void		quiet_mode(t_parsed_data *data, int argv, char **argc);
void		read_additional_arguments(int argv, char **argc,
				t_parsed_data *data);
void		write_dot(t_room *room, FILE *fp);
void		write_movement_index_i(int i, t_parsed_data *data);
void		write_movement_to_dot(t_ant *ant, t_parsed_data *data);
void		print_out_routes(t_room *start);
#endif
