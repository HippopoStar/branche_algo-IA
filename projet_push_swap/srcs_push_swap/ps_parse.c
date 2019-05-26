/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 02:13:56 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/26 13:49:14 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** La fonction 'ps_integer_format' profite de devoir parcourir les elements
** a parser pour renseigner le champ 'length' de 'data'
*/

int		ps_integer_format(t_ps *data, char **to_parse)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(to_parse + i))
	{
		j = 0;
		if ((*(*(to_parse + i) + 0) == '-' || *(*(to_parse + i) + 0) == '+')
				&& *(*(to_parse + i) + 1) != '\0')
		{
			j++;
		}
		while (*(*(to_parse + i) + j) != '\0')
		{
			if (!ft_strchr("0123456789", (int)(*(*(to_parse + i) + j))))
				return (0);
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	data->length = i;
	return (i > 0 ? 1 : 0);
}

int		ps_zero_format(char *str)
{
	size_t	i;

	i = 0;
	if ((*(str + 0) == '-' || *(str + 0) == '+') && *(str + 1) != '\0')
	{
		i++;
	}
	while (*(str + i) != '\0')
	{
		if (*(str + i) != '0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
** La fonction 'ps_sort_wit' va trier la pile temoin, en en profitant
** pour verifier l'absence de doublons
*/

int		ps_sort_wit(int *sorted, size_t length)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < length - 1)
	{
		if (*(sorted + i) > *(sorted + i + 1))
		{
			tmp = *(sorted + i);
			*(sorted + i) = *(sorted + i + 1);
			*(sorted + i + 1) = tmp;
			if (i != 0)
			{
				i--;
			}
		}
		else if (*(sorted + i) == *(sorted + i + 1))
			return (0);
		else
		{
			i++;
		}
	}
	return (1);
}

/*
** La fonction 'ps_init_stacks' va allouer la memoire pour les 3 piles,
** verifier la coherence des nombres grace a 'ps_zero_format', et appeler
** 'ps_sort_wit'
*/
/*
** Allocation dynamique de memoire dans 'ps_init_stacks' ('malloc')
*/

int		ps_init_stacks(t_ps *data, char **to_parse)
{
	size_t	i;
	t_nb	**ptr;

	if (!(data->sorted = (int *)malloc(data->length * sizeof(int))))
		return (0);
	ptr = &(*(data->stacks + 0));
	i = 0;
	while (i < data->length)
	{
		if (!(*ptr = (t_nb *)malloc(sizeof(t_nb))))
		{
			return (0);
		}
		(*ptr)->nb = ft_atoi(*(to_parse + i));
		(*ptr)->next = NULL;
		*(data->sorted + i) = (*ptr)->nb;
		if ((*ptr)->nb == 0 && !ps_zero_format(*(to_parse + i)))
		{
			return (0);
		}
		ptr = &((*ptr)->next);
		i++;
	}
	return (ps_sort_wit(data->sorted, data->length));
}

/*
** Un message d'erreur etant envoye dans la fonction appelant 'ps_parse'
** dans le cas ou celle-ci renverrait '0', nul besoin de l'afficher ici-meme
*/
/*
** Allocation dynamique de memoire dans 'ps_parse' ('ft_strsplit')
*/

int		ps_parse(t_ps *data, int argc, char **argv)
{
	char	**to_parse;
	size_t	i;
	int		ret;

	to_parse = (argc == 2) ? ft_strsplit(*(argv + 1), ' ') : argv + 1;
	ret = (!to_parse || !ps_integer_format(data, to_parse)) ? 0
		: ps_init_stacks(data, to_parse);
	if (argc == 2 && to_parse)
	{
		i = 0;
		while (*(to_parse + i))
		{
			free(*(to_parse + i));
			i++;
		}
		free(to_parse);
	}
	return (ret);
}
