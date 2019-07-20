/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:35:01 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 16:44:42 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ecrit le caractère c sur le descripteur de fichier fd.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
