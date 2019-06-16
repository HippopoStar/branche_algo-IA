/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:48:27 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/16 16:30:37 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "common_functions.h"
# include <stdio.h>

/*
** Le header <stdio.h> est importe car la fonction autorisee 'perror' appartient
** a la librairie correspondante
*/

# define LI_BUFF 4096

typedef struct		s_output
{
	char			buff[LI_BUFF];
	size_t			index;
}					t_output;

typedef struct		s_ant
{
	char			to_print[24];
	size_t			pos_y;
	size_t			wait;
}					t_ant;

typedef struct		s_room
{
	char			*name;
	int				weight;
	size_t			ancestor;
	int				pos_x;
	int				pos_y;
	int				role;
	size_t			nb_of_bonds;
	size_t			*bond_sum;
	signed char		*pipes;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int				ants;
	size_t			size;
	size_t			bonds;
	size_t			max_paths;
	size_t			**paths;
	size_t			path_nb;
	size_t			***routes;
	size_t			best_steps;
	size_t			best_route;
	t_ant			*ant_tab;
	t_room			*rooms;
	t_room			**map;
	t_output		output;
	int				options;
	int				help;
	int				color;
	size_t			display_steps;
}					t_data;

typedef struct		s_route
{
	size_t			width;
	size_t			height;
	size_t			**field;
	t_data			*data_ptr;
}					t_route;

/*
** Dans le fichier 'main_lem_in.c'
*/
int					lem_in(t_data *data);
/*
** Dans le fichier 'li_options.c'
*/
int					li_options(t_data *data, int argc, char **argv);
/*
** Dans le fichier 'li_error.c'
*/
void				li_help(void);
void				li_usage(void);
void				li_error(void);
/*
** Dans le fichier 'li_print.c'
*/
void				li_get_output(t_data *data, const char *str);
void				li_print_output(t_data *data);
/*
** Dans le fichier 'li_get_next_non_comment_line.c'
*/
int					li_is_command(char *line);
int					li_is_comment(char *line);
int					li_get_next_non_comment_line(t_data *data, char **line);
/*
** Dans le fichier 'li_parse_input.c'
*/
int					li_parse_ants(t_data *data, char **line, int *ret_gnl);
int					li_parse_rooms(t_data *data, char **line, int *ret_gnl);
int					li_parse_pipes(t_data *data, char **line, int *ret_gnl);
int					li_parse_input(t_data *data);
/*
** Dans le fichier 'li_match_ants.c'
*/
int					li_match_ants(t_data *data, char *line);
/*
** Dans le fichier 'li_match_rooms.c'
*/
int					li_allocate_room(t_room **room);
int					li_is_name_available(t_room *current, t_data *data);
void				li_deal_sharp_marks(t_room **current, char *line, int *wit);
int					aux_li_match_room(t_room *current, char *line, int *wit);
void				li_match_room(t_data *data, char *line,\
												t_room ***current, int *wit);
/*
** Dans le fichier 'li_allocate_map.c'
*/
int					li_allocate_map(t_data *data);
int					aux_li_allocate_map(t_data *data, signed char *set_map);
/*
** Dans le fichier 'li_match_pipes.c'
*/
int					li_actualise_map(t_data *data, size_t i, size_t j);
int					li_match_pipe(t_data *data, char *line);
/*
** Dans le fichier 'li_shorten_map_pipes.c'
*/
void				li_fill_bond_summary(t_room *current);
int					li_shorten_map_pipes(t_data *data);
/*
** Dans le fichier 'li_print_map.c' (implementer options ?)
*/
void				li_print_rooms(t_data *data);
void				li_print_map(t_data *data);
void				li_print_paths(t_data *data);
void				li_print_route(t_route *current, size_t i);
void				li_print_routes(t_data *data);
/*
** Dans le fichier 'li_bellman_ford.c'
*/
void				li_bellman_ford(t_data *data);
void				aux_li_bellman_ford(t_data *data);
/*
** Dans le fichier 'li_bhandari.c'
*/
void				li_bhandari_max_iterations(t_data *data);
void				li_initialise_weights(t_data *data);
int					li_reverse_path(t_data *data);
int					li_allocate_paths(t_data *data);
int					li_bhandari(t_data *data);
/*
** Dans le fichier 'li_build_routes.c'
*/
void				aux_li_allocate_outes(t_data *data);
int					li_allocate_routes(t_data *data);
void				li_copy_previous_route(t_data *data, size_t index);
void				li_copy_last_path(t_data *data, size_t i);
int					li_build_routes(t_data *data);
/*
** Dans le fichier 'li_order_paths'
*/
void				li_swap_paths(t_route *route, size_t i, size_t j);
void				li_order_paths(t_route *route);
/*
** Dans le fichier 'li_remove_edges'
*/
size_t				li_edge_len(t_route *route, size_t i, size_t j, size_t k);
void				li_melt_paths(t_route *route, size_t i, size_t j, size_t k);
void				aux_li_remove_edges(t_route *route, size_t *i, size_t *j,\
																	size_t *k);
void				li_remove_edges(t_route *route);
/*
** Dans le fichier 'li_get_routes_lengths' (caduque)
*/
void				li_get_routes_lengths(t_data *data);
/*
** Dans le fichier 'li_eval_routes.c'
*/
size_t				li_eval_meanwhile(t_data *data, size_t index);
size_t				li_eval_steps(t_data *data, size_t index);
void				li_eval_routes(t_data *data);
/*
** Dans le fichier 'li_size_ttoa.c'
*/
void				li_color_ants(size_t ant, char to_print[24], size_t gap);
void				li_size_ttoa(size_t ant, char to_print[24], int color);
/*
** Dans le fichier 'li_move_ants.c'
** / ! \ Penser a securiser le 'malloc' de 'ft_itoa' ! (OBSOLETE)
** ('ft_itoa' -> 'li_size_ttoa')
*/
int					li_allocate_ant_tab(t_data *data);
void				li_ants_distribution(t_data *data);
int					li_move_ants(t_data *data);
/*
** Dans le fichier 'li_display_steps.c'
*/
size_t				li_steps_length(t_data *data);
void				li_prepare_steps_str(t_data *data, char to_display[27]);
void				li_display_steps(t_data *data, size_t step,\
														char to_display[27]);
/*
** Dans le fichier 'li_memory_liberator.c'
*/
void				li_liberate_rooms_map_and_bonds(t_data *data);
void				li_liberate_paths_and_routes(t_data *data);
void				li_memory_liberator(t_data *data);

#endif
