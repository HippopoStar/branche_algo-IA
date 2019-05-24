/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_liberate_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:03:41 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/24 17:16:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 'ps_liberate_stacks' libere la memoire alloue
** dans 'ps_init_stacks' du fichier 'ps_parse.c'
*/

void	ps_liberate_stacks_and_sorted(t_ps *data)
{
	t_nb	*tmp_stack;

	while (*(data->stacks + 0) != NULL)
	{
		tmp_stack = (*(data->stacks + 0))->next;
		free(*(data->stacks + 0));
		*(data->stacks + 0) = tmp_stack;
	}
	while (*(data->stacks + 1) != NULL)
	{
		tmp_stack = (*(data->stacks + 1))->next;
		free(*(data->stacks + 1));
		*(data->stacks + 1) = tmp_stack;
	}
	if (data->sorted != NULL)
	{
		free(data->sorted);
	}
}

/*
** OBSOLETE
** (car memoire liberee au fur et a mesure)
**
** 'ps_liberate_argv' libere la memoire alloue
** dans 'ps_parse' du fichier 'ps_parse.c'
** (dans le cas de l'emploi de 'ft_strsplit' <-> argv == 2)
**
** / ! \ Si une allocation de ligne echoue dans 'ft_strsplit'
** la fonction renvoie 'NULL' sans liberer au prealable la
** memoire des lignes precedentes
*/

void	ps_liberate_splited_argv(char **splited_argv)
{
	size_t	i;

	if (splited_argv != NULL)
	{
		i = 0;
		while (*(splited_argv + i) != NULL)
		{
			free(*(splited_argv + i));
			i++;
		}
		free(splited_argv);
	}
}

/*
** OBSOLETE
** (car memoire liberee a la lecture)
**
** 'ps_liberate_input' libere d'une part la memoire alloue
** dans 'ps_shorten' du fichier 'ps_shorten.c'
** et d'autre part la memoire alloue
** dans 'ps_get_input' du fichier 'ps_get_input'
*/

void	ps_liberate_input(t_input *input)
{
	t_input	*tmp_input;

	while (input != NULL)
	{
		tmp_input = input->next;
		free(input);
		input = tmp_input;
	}
}
