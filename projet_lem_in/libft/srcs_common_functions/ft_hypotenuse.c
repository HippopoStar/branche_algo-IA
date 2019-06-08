/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hypotenuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:05:43 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/25 14:53:00 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common_functions.h"

/*
** "common_functions.h" : 'ft_sqrt'
*/

int	ft_hypotenuse(int base, int hauteur)
{
	return (ft_sqrt((base * base) + (hauteur * hauteur)));
}
