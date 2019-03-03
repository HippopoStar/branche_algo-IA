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
	s_input			*next;
}					t_input;

typedef struct		s_room
{	char			*name;
	int				pos_x;
	int				pos_y;
	int				role;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int				ants;
	size_t			size;
	t_room			*rooms;
	int				**map;
	t_input		*input;
	t_output	*output;
}					t_data;

int		li_get_input(t_input **input);
int		li_parse_input(t_data *data);

#endif
