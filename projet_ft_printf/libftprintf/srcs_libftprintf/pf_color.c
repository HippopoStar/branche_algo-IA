/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:23:22 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 12:23:40 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_color\"\n");
*/

int	pf_color(const char *format, t_list *mai)
{
	if (!(mai->content = (void *)malloc(6 * sizeof(char))))
		return (-1);
	if (!ft_strncmp(format, "{eoc}", 5))
		ft_strcpy((char *)(mai->content), END_OF_COLOR);
	else if (!ft_strncmp(format, "{black}", 7))
		ft_strcpy((char *)(mai->content), BLACK);
	else if (!ft_strncmp(format, "{red}", 5))
		ft_strcpy((char *)(mai->content), RED);
	else if (!ft_strncmp(format, "{green}", 7))
		ft_strcpy((char *)(mai->content), GREEN);
	else if (!ft_strncmp(format, "{yellow}", 8))
		ft_strcpy((char *)(mai->content), YELLOW);
	else if (!ft_strncmp(format, "{blue}", 6))
		ft_strcpy((char *)(mai->content), BLUE);
	else if (!ft_strncmp(format, "{magenta}", 9))
		ft_strcpy((char *)(mai->content), MAGENTA);
	else if (!ft_strncmp(format, "{cyan}", 6))
		ft_strcpy((char *)(mai->content), CYAN);
	else if (!ft_strncmp(format, "{white}", 7))
		ft_strcpy((char *)(mai->content), WHITE);
	else
		return (-1);
	return (0);
}
