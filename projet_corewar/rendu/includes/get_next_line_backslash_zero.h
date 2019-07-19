/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_backslash_zero.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 06:32:41 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 06:44:55 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BACKSLASH_ZERO_H
# define GET_NEXT_LINE_BACKSLASH_ZERO_H

# include "get_next_line.h"

int					get_next_line_backslash_zero(const int fd, char **line);
int					aux_1_gnl_bsz(const int fd, char **line, t_gnl *maillon);
int					aux_2_gnl_bsz(const int fd, char **line, t_gnl *maillon);
int					aux_3_gnl_bsz(const int fd, char **line, t_gnl *mai,\
																ssize_t tab[3]);

#endif
