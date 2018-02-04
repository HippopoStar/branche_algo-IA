/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int_mai.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 01:54:10 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 05:25:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		from_stock_to_string(t_pn *stock, t_pf *mai)
{
	size_t	i;
	t_pn	*tmp;

	mai->len = 0;
	tmp = stock;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		(mai->len)++;
	}
	if (!(mai->str = (char *)malloc((mai->len + 1) * sizeof(char))))
		error_code("Erreur d'alloc'");
	(mai->str)[mai->len] = '\0';
	i = 0;
	while (stock != NULL)
	{
		(mai->str)[i] = stock->c;
		stock = stock->next;
		i++;
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
*/

void		fill_nb_bas(long int l_n, t_pn *stock, t_pf *mai, ssize_t mnod)
{
	t_pn		tmp;

	if (l_n == 0)
	{
		if (mnod > 0)
		{
			tmp.c = (mai->next)->str[0];
			tmp.next = stock;
			fill_nb_bas(l_n, &tmp, mai, mnod - 1);
		}
		else
		{
			mai->next = NULL;
			from_stock_to_string(stock, mai);
		}
	}
	else
	{
		tmp.c = ((mai->next)->str)[l_n % (long int)((mai->next)->len)];
		tmp.next = stock;
		fill_nb_bas(l_n / (long int)((mai->next)->len), &tmp, mai, mnod - 1);
	}
}

/*
** mnod : minimum_number_of_digits
*/

void		add_int_mai(int nbr, char *base, t_pf *mai, ssize_t mnod)
{
	long int	long_nbr;
	t_pf		aux;

	long_nbr = (long int)nbr;
	is_base_valid(base, &aux);
	if (aux.len == 0)
		mai->next = NULL;
	else
	{
		mai->next = &aux;
		if (long_nbr == 0)
			fill_nb_bas(0, NULL, mai, 1);
		else
		{
			if (long_nbr < 0)
			{
				ft_putchar('-');
				fill_nb_bas(-long_nbr, NULL, mai, mnod);
			}
			else
				fill_nb_bas(long_nbr, NULL, mai, mnod);
		}
	}
}
