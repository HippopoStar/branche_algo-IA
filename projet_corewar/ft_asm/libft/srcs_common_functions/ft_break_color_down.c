/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_color_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:05:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 05:05:34 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_break_color_down(int *red, int *green, int *blue, int color)
{
	color = color % 0x1000000;
	*red = color / 0x010000;
	color = color % 0x010000;
	*green = color / 0x000100;
	color = color % 0x000100;
	*blue = color;
}
