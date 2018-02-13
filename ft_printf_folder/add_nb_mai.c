/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nb_mai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 07:35:46 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 08:26:00 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		from_stock_to_string(t_pn *stock, t_pf *mai)
{
	size_t	i;
	t_pn	*tmp;
	int		p_o_n;

	p_o_n = mai->len;
	tmp = stock;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		(mai->len)++;
	}
	if (!(mai->str = (char *)malloc((mai->len + 1) * sizeof(char))))
		error_code("Erreur d'alloc'");
	(mai->str)[mai->len] = '\0';
	i = p_o_n;
	while (stock != NULL)
	{
		(mai->str)[i] = stock->c;
		stock = stock->next;
		i++;
	}
	if (p_o_n == 1)
	{
		(mai->str)[0] = '-';
	}
}

size_t		is_base_valid(char *base, t_pf *aux)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 33 || base[i] == 127 || base[i] == '-' || base[i] == '+')
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	aux->len = ((i < 2) ? 0 : i);
	aux->str = base;
	aux->next = NULL;
	return (aux->len);
}

/*
** l_n : long_nbr
** l_b : length_base
**
** Astuce : mnoz > mai->len
**          une place en moins lorsqu'il y a un '-' a placer
*/

void		fill_nb_bas(ULLI l_n, t_pn *stock, t_pf *mai, ssize_t mnoz)
{
	t_pn		tmp;

	if (l_n == 0)
	{
		if (mnoz > (ssize_t)mai->len)
		{
			tmp.c = (mai->next)->str[0];
			tmp.next = stock;
			fill_nb_bas(l_n, &tmp, mai, mnoz - 1);
		}
		else
		{
			from_stock_to_string(stock, mai);
			mai->next = NULL;
		}
	}
	else
	{
		tmp.c = ((mai->next)->str)[l_n % (ULLI)((mai->next)->len)];
		tmp.next = stock;
		fill_nb_bas(l_n / (ULLI)((mai->next)->len), &tmp, mai, mnoz - 1);
	}
}

/*
** mnod : minimum_number_of_zeros
*/

void		add_nb_mai(ULLI nb, char *base, t_pf *mai, ssize_t mnoz)
{
	t_pf		aux;

	is_base_valid(base, &aux);
	if (aux.len == 0)
		mai->next = NULL;
	else
	{
		mai->next = &aux;
		if (nb == 0)
		{
			fill_nb_bas(0, NULL, mai, 1);
		}
		else
		{
			fill_nb_bas(nb, NULL, mai, mnoz);
		}
	}
}
