/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_backslash_zero.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 06:32:41 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/20 15:02:34 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BACKSLASH_ZERO_H
# define GET_NEXT_LINE_BACKSLASH_ZERO_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
** Pour heriter de la variable 'BUFF_SIZE'
*/
# include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	char			buff[BUFF_SIZE];
	ssize_t			bs_p;
	ssize_t			r_v;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line_backslash_zero(const int fd, char **line);
int					aux_1_gnl_bsz(const int fd, char **line, t_gnl *maillon);
int					aux_2_gnl_bsz(const int fd, char **line, t_gnl *maillon);
int					aux_3_gnl_bsz(const int fd, char **line, t_gnl *mai,\
																ssize_t tab[3]);

#endif
