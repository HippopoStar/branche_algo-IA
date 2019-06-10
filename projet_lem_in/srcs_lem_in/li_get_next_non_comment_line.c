/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_next_non_comment_line.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:27:44 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/10 21:07:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_is_command(char *line)
{
	return ((!ft_strcmp("##start", line) || !ft_strcmp("##end", line)) ? 1 : 0);
}

int		li_is_comment(char *line)
{
	return ((*(line + 0) == '#' && !li_is_command(line)) ? 1 : 0);
}

/*
** La fonction 'li_get_next_non_comment_line' recupere les lignes passees dans
** dans l'entree standard du programme en les liberant immediatement tant que
** celles-ci correspondent a des commentaires, et s'arrete a la premiere ligne
** n'etant pas un commentaire
**
** Elle ajoute egalement systematiquement la ligne dans le buffer d'ecriture,
** ainsi qu'un retour a la ligne
** (y compris dans le cas de la lecture
** d'une ligne vide correspondant a la fin de la lecture)
*/
/*
** Allocation dynamique de memoire dans 'li_get_next_non_comment_line'
*/

int		li_get_next_non_comment_line(t_data *data, char **line)
{
	int		ret_gnl;

	while ((ret_gnl = get_next_line_backslash_zero(0, line)) == 1
			&& li_is_comment(*line))
	{
		li_get_output(data, *line);
		li_get_output(data, "\n");
		free(*line);
	}
	if (ret_gnl == 1)
	{
		li_get_output(data, *line);
	}
	else if (ret_gnl == 0 && (*line))
	{
		free(*line);
	}
	li_get_output(data, "\n");
	return (ret_gnl);
}
