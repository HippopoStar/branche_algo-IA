/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 02:46:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 00:26:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf		*from_stock_to_string(t_pn *stock)
{
	t_pf	*nou;
	size_t	i;
	t_pn	*tmp;

	if (!(nou = (t_pf *)malloc(sizeof(t_pf))))
		error_code("Erreur d'alloc'");
	nou->len = 0;
	tmp = stock;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		(nou->len)++;
	}
	if (!(nou->str = (char *)malloc((nou->len + 1) * sizeof(char))))
		error_code("Erreur d'alloc'");
	(nou->str)[nou->len] = '\0';
	i = 0;
	while (stock != NULL)
	{
		(nou->str)[i] = stock->c;
		stock = stock->next;
		i++;
	}
	nou->next = NULL;
	return (nou);
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

void		fill_nbr_base(long int l_n, t_pn *stock, t_pf *mai, ssize_t mnod)
{
	t_pn		tmp;

	if (l_n == 0)
	{
		if (mnod > 0)
		{
			tmp.c = (mai->next)->str[0];
			tmp.next = stock;
			fill_nbr_base(l_n, &tmp, mai, mnod - 1);
		}
		else
		{
			mai->next = from_stock_to_string(stock);
		}
	}
	else
	{
		tmp.c = ((mai->next)->str)[l_n % (long int)((mai->next)->len)];
		tmp.next = stock;
		fill_nbr_base(l_n / (long int)((mai->next)->len), &tmp, mai, mnod - 1);
	}
}

/*
** mnod : minimum_number_of_digits
*/

void		ft_putnbr_base(int nbr, char *base, t_pf *mai, ssize_t mnod)
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
			fill_nbr_base(0, NULL, mai, 1);
		else
		{
			if (long_nbr < 0)
			{
				ft_putchar('-');
				fill_nbr_base(-long_nbr, NULL, mai, mnod);
			}
			else
				fill_nbr_base(long_nbr, NULL, mai, mnod);
		}
		ft_putstr((mai->next)->str);
		ft_putchar('\n');
	}
}
