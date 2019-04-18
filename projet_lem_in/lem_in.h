/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:48:27 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/26 12:57:27 by lcabanes         ###   ########.fr       */
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
	struct s_input			*next;
}					t_input;

typedef struct		s_room
{	char			*name;
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
	t_room			*rooms;
	t_room			*map;
	t_input		*input;
	t_input		*read;
	t_output	*output;
}					t_data;

/*
** Dans le fichier 'main_lem_in.c'
*/

/*
** Dans le fichier 'li_error.c'
*/
void	li_error(void);
/*
** Dans le fichier 'li_parse_input.c'
*/
int		li_get_input(t_input **input);
int		li_parse_input(t_data *data);
/*
** Dans le fichier 'ft_is_int.c'
*/
int		ft_is_int(char *str, size_t *i, int *n);
/*
** Dans le fichier 'li_match_ants.c'
*/
int		li_match_ants(t_input **read, t_data *data);
/*
** Dans le fichier 'li_match_rooms.c'
*/
int		li_match_rooms(t_input **read, t_data *data);
int		li_match_room(t_room *room, char *str);
int		li_allocate_room(t_room **room);
/*
** Dans le fichier 'li_allocate_map.c'
*/
int		li_allocate_map(t_data *data);
int		aux_li_allocate_map(t_data *data, int *set_map);
/*
** Dans le fichier 'li_match_pipes.c'
*/
int		li_match_pipes(t_input **read, t_data *data);
/*
**
*/

/*
**
*/

/*
**
*/

/*
**
*/

#endif
