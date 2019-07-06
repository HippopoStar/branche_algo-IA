/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hypotenuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:05:43 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 04:48:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common_functions.h"

int	ft_hypotenuse(int base, int hauteur)
{
	return (ft_sqrt((base * base) + (hauteur * hauteur)));
}
