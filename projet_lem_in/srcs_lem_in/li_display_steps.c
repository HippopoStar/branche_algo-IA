/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:34:32 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/07 22:34:33 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 'stdint.h' :
** # define SIZE_MAX (18446744073709551615UL)
**
** 20 digits
** 'Step (size_t): \0' : 28 char
*/
/*
** Se referer a l'emploi de 'li_steps_length' dans le fichier
** 'li_options.c'
** (La valeur de retour sera assignee a la variable 'data->steps_length'
** si l'option '-l' est presente)
*/

size_t	li_steps_length(t_data *data)
{
	size_t	tmp;
	size_t	i;

	if (data->display_steps == 0)
	{
		return (0);
	}
	else
	{
		tmp = data->best_steps;
		i = 5;
		while ((tmp = (tmp / 10)) > 0)
		{
			i++;
		}
		return (i);
	}
}

void	li_prepare_steps_str(t_data *data, char to_display[28])
{
	if (data->display_steps == 0 || data->display_steps > 24)
	{
		*(to_display + 0) = '\0';
	}
	else
	{
		*(to_display + 0) = 'S';
		*(to_display + 1) = 't';
		*(to_display + 2) = 'e';
		*(to_display + 3) = 'p';
		*(to_display + 4) = ' ';
		*(to_display + data->display_steps + 1) = ':';
		*(to_display + data->display_steps + 2) = ' ';
		*(to_display + data->display_steps + 3) = '\0';
	}
}

void	li_display_steps(t_data *data, size_t step, char to_display[28])
{
	size_t	i;

	if (data->display_steps == 0 || data->display_steps > 24)
	{
		*(to_display + 0) = '\0';
	}
	else
	{
		i = data->display_steps;
		while (i > 4)
		{
			*(to_display + i) = '0' + (step % 10);
			step = step / 10;
			i--;
		}
	}
}
