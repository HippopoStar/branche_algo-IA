/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_build_routes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:59:03 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/20 22:17:35 by lcabanes         ###   ########.fr       */
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
			|| !(*(*(data->routes + 0) + 0) = (size_t *)malloc(n * data->size * sizeof(size_t))))
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
			*(*(data->routes + i) + j) = &(*(*(*(data->routes + 0) + 0) + ((n + j) * data->size)));
			j++;
		}
		i++;
	}
	return (1);
}

void	li_aux_build_routes(t_data *data, size_t **field, size_t n)
{
	(void)data;
	(void)field;
	(void)n;
}

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
		while (j < data->size)
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
			*(*(*(data->routes + i) + i) + j) = *(*(data->paths + i) + j);
			j++;
		}
		i++;
		li_aux_build_routes(data, *(data->routes + i), i);
	}
	return (1);
}
