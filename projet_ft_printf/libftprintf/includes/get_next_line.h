/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 06:30:14 by lcabanes          #+#    #+#             */
/*   Updated: 2018/03/22 00:21:36 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 24

typedef struct		s_gnl
{
	int				fd;
	char			buff[BUFF_SIZE];
	ssize_t			bs_p;
	ssize_t			r_v;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
int					aux_1_gnl(const int fd, char **line, t_gnl *maillon);
int					aux_2_gnl(const int fd, char **line, t_gnl *maillon);
int					aux_3_gnl(const int fd, char **line, t_gnl *mai,\
																ssize_t tab[3]);

#endif
