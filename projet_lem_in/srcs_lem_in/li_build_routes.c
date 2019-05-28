/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_build_routes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:59:03 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/28 19:47:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_allocate_routes(t_data *data)
{
	size_t	n;
	size_t	i;
	size_t	j;

	n = 0;
	i = 0;
	while (i <= data->path_nb)
	{
		n = n + i;
		i++;
	}
	if (!(data->routes = (size_t ***)malloc(data->path_nb * sizeof(size_t **)))
			|| !(*(data->routes + 0) = (size_t **)malloc(n * sizeof(size_t *)))
			|| !(*(*(data->routes + 0) + 0) = (size_t *)malloc(n * (data->size + 2) * sizeof(size_t))))
		return (0);
	n = 0;
	i = 1;
	while (i < data->path_nb)
	{
		n = n + i;
		*(data->routes + i) = &(*(*(data->routes + 0) + n));
		j = 0;
		while (j <= i)
		{
			*(*(data->routes + i) + j) = &(*(*(*(data->routes + 0) + 0) + ((n + j) * (data->size + 2))));
			j++;
		}
		i++;
	}
	return (1);
}

/*
** A->E->D->H               donne   A->E->F->G->H   D devient F
** A->B->C->D->E->F->G->H     et    A->B->C->D->H   E devient H
*/

void	aux_li_build_routes(t_data *data, size_t **field, size_t n)
{
	size_t	a;
	size_t	b;
	size_t	i;
	size_t	j;
	size_t	tmp_b;

	a = n;
	b = 1;
	while (b + 2 < data->size)
	{
		i = 0;
		while (i <= n)
		{
			j = 1;
			while (j < data->size)
			{
				if (!(*(*(field + i) + j) == 0 || *(*(field + i) + j) == data->size - 1)
						&& *(*(field + i) + j) == *(*(field + a) + b)
						&& !(a == i && b == j))
				{
					tmp_b = b;
					while (j < data->size && tmp_b + 2 < data->size)
					{
						*(*(field + i) + j) = *(*(field + a) + tmp_b + 2);
						*(*(field + a) + tmp_b + 1) = *(*(field + i) + j + 1);
						tmp_b++;
						j++;
					}
					*(*(field + a) + tmp_b + 1) = *(*(field + i) + j + 1);
					*(*(field + a) + data->size) = *(*(field + a) + data->size) - 3;
					*(*(field + i) + data->size) = *(*(field + i) + data->size) + 1;
					a = i;
					i = n;
				}
				j++;
			}
			i++;
		}
		b++;
	}
}

/*
** Rappel :
** Dans la fonction 'li_reverse_path' du fichier 'li_bhandari.c'
** assigne a la variable '*(*(data->paths + i) + data->size)'
** l'index de depart de l'itineraire
**
** Ainsi l'assignation
** *(*(*(data->routes + i) + i) + data->size)
**		= data->size - *(*(data->paths + i) + data->size)
** correspont a la longueur de l'itineraire
*/

int		li_build_routes(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!li_allocate_routes(data))
		return (0);
	i = 0;
	while (i < data->path_nb)
	{
		j = 0;
		while (j + *(*(data->paths + i) + data->size) < data->size)
		{
			if (i > 0)
			{
				k = 0;
				while (k < i)
				{
					*(*(*(data->routes + i) + k) + j) = *(*(*(data->routes + i - 1) + k) + j);
					k++;
				}
			}
			*(*(*(data->routes + i) + i) + j) = *(*(data->paths + i) + j + *(*(data->paths + i) + data->size));
			j++;
		}
		while (j < data->size)
		{
			*(*(*(data->routes + i) + i) + j) = 0;
			j++;
		}
		*(*(*(data->routes + i) + i) + data->size) = data->size - *(*(data->paths + i) + data->size);
		aux_li_build_routes(data, *(data->routes + i), i);
		i++;
	}
	return (1);
}
