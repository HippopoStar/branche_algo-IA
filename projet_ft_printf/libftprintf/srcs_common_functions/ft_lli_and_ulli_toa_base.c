/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lli_and_ulli_toa_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 06:06:55 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 06:10:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common_functions.h"

char	*ft_ullitoa_base(unsigned long long int n, const char *base,\
													size_t prec, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;

	l_n.content_size = 0;
	l_n.content = (void *)(&n);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
	{
		return (NULL);
	}
	l_base.next = &l_length;
	if (prec == 0)
	{
		prec = 1;
	}
	l_length.content = (void *)(&prec);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}

char	*ft_llitoa_base(long long int n, const char *base,\
													size_t prec, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;
	unsigned long long int	nb;

	l_n.content_size = (n < 0) ? 1 : 0;
	if (n != LONG_MIN)
		nb = (unsigned long long int)((n < 0) ? -n : n);
	else
		nb = (unsigned long long int)LONG_MAX + 1;
	l_n.content = (void *)(&nb);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
		return (NULL);
	l_base.next = &l_length;
	if (prec == 0)
	{
		prec = 1;
	}
	l_length.content = (void *)(&prec);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}
