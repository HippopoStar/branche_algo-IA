#include "lem_in.h"

void	li_bhandari_max_iterations(t_data *data)
{
	int		beg;
	int		end;
	size_t	i;

	beg = 0;
	end = 0;
	i = 0;
	while (i < data->size)
	{
		if (*((*(data->map + 0))->pipes + i) == 1)
		{
			beg++;
		}
		if (*((*(data->map + data->size - 1))->pipes + i) == 1)
		{
			end++;
		}
		i++;
	}
	if (data->ants < beg && data->ants < end)
	{
		data->max_paths = (size_t)data->ants;
	}
	else
	{
		data->max_paths = (size_t)(beg < end ? beg : end);
	}
}

void	li_initialise_weights(t_data *data)
{
	size_t	i;

	(*(data->map + 0))->ancestor = 0;
	(*(data->map + 0))->weight = 0;
	i = 1;
	while (i < data->size)
	{
		(*(data->map + i))->ancestor = data->size;
		(*(data->map + i))->weight = (int)data->size;
		i++;
	}
}

int		li_reverse_path(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	pos;

	j = data->size - 1;
	if ((i = (*(data->map + j))->ancestor) == data->size)
	{
		return (0);
	}
	pos = data->size - 1;
	while (i != 0)
	{
		i = (*(data->map + j))->ancestor;
		*((*(data->map + i))->pipes + j) = 0;
		*((*(data->map + j))->pipes + i) = -1;
		*(*(data->paths + data->path_nb) + pos) = j;
		pos--;
		j = i;
	}
	return (1);
}

int		li_allocate_paths(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	*tmp;

	if (!(tmp = (size_t *)malloc(data->max_paths * (data->size + 1) * sizeof(size_t))))
		return (0);
	if (!(data->paths = (size_t **)malloc(data->max_paths * sizeof(size_t *))))
		return (0);
	i = 0;
	while (i < data->max_paths)
	{
		*(data->paths + i) = &(*(tmp + (i * (data->size + 1))));
		j = 0;
		while (j < data->size + 1)
		{
			*(*(data->paths + i) + j) = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		li_bhandari(t_data *data)
{
	size_t	i;
	int		ret_val;

	li_bhandari_max_iterations(data);
	if (!li_allocate_paths(data))
		return (0);
	ret_val = 1;
	i = 0;
	while (i < data->max_paths && ret_val == 1)
	{
		li_initialise_weights(data);
		li_bellman_ford(data);
		ret_val = li_reverse_path(data);
		data->path_nb++;
		i++;
	}
	return (!(i == 1 && ret_val == 0) ? 1 : 0);
}
