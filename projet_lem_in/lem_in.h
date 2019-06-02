/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:48:27 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/02 18:31:06 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
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

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_input;

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
	int				*pipes;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int				ants;
	size_t			size;
	size_t			max_paths;
	size_t			**paths;
	size_t			path_nb;
	size_t			***routes;
	size_t			best_steps;
	size_t			best_route;
	t_ant			*ant_tab;
	t_room			*rooms;
	t_room			**map;
	t_input			*input;
	t_input			*read;
	t_output		output;
	int				color;
}					t_data;

/*
** Dans le fichier 'main_lem_in.c'
*/

/*
** Dans le fichier 'li_error.c'
*/
void				li_error(void);
/*
** Dans le fichier 'li_print.c'
*/
void				li_get_output(t_data *data, const char *str);
void				li_print_output(t_data *data);
/*
** Dans le fichier 'li_parse_input.c'
*/
int					li_get_input(t_data *data, t_input **input);
int					li_parse_input(t_data *data);
/*
** Dans le fichier 'ft_is_int.c'
*/
int					ft_is_int(char *str, size_t *i, int *n);
/*
** Dans le fichier 'li_match_ants.c'
*/
int					li_match_ants(t_input **read, t_data *data);
/*
** Dans le fichier 'li_match_rooms.c'
*/
int					li_match_rooms(t_input **read, t_data *data);
int					li_match_room(t_room *room, char *str);
int					li_deal_sharp_marks(t_room *room, t_input **read);
int					li_allocate_room(t_room **room);
/*
** Dans le fichier 'li_allocate_map.c'
*/
int					li_allocate_map(t_data *data);
int					aux_li_allocate_map(t_data *data, int *set_map);
/*
** Dans le fichier 'li_match_pipes.c'
*/
int					li_match_pipes(t_input **read, t_data *data);
int					li_match_pipe(t_data *data, char *str);
/*
** Dans le fichier 'li_print_map.c'
*/
void				li_print_map(t_data *data);
void				li_print_paths(t_data *data);
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
int					li_allocate_routes(t_data *data);
void				aux_li_build_routes(t_data *data, size_t **field, size_t n);
void				li_copy_previous_route(t_data *data, size_t index);
int					li_build_routes(t_data *data);
/*
** Dans le fichier 'li_get_routes_lengths'
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
** / ! \ Penser a securiser le 'malloc' de 'ft_itoa' !
*/
int					li_allocate_ant_tab(t_data *data);
void				li_ants_distribution(t_data *data);
void				aux_li_move_ants(t_data *data, size_t step);
int					li_move_ants(t_data *data);

#endif
