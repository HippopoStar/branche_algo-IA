/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:28:56 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 19:40:15 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static void	asm_initialize_header_struct(t_header *h)
{
	size_t	i;

	i = 0;
	while (i <= PROG_NAME_LENGTH)
	{
		*(h->prog_name + i) = '\0';
		i++;
	}
	i = 0;
	while (i <= COMMENT_LENGTH)
	{
		*(h->comment + i) = '\0';
		i++;
	}
}

/*
** Ajout de l'argument (size_t *)j pour l'appel de 'asm_'[...]'_does_not_fit
*/

static int	asm_get_quote(char *line, char *to_fill, int size, size_t *j)
{
	if (*(line + 0) == '"')
	{
		line++;
		*j = 0;
		while ((*j) < (size_t)size\
				&& !(*(line + (*j)) == '"' || *(line + (*j)) == '\0'))
		{
			*(to_fill + (*j)) = *(line + (*j));
			(*j)++;
		}
		*(to_fill + (*j)) = '\0';
		if (*(line + (*j)) == '"')
		{
			(*j)++;
			asm_skip_spacing_chars(line, j);
			if (*(line + (*j)) == '\0' || *(line + (*j)) == COMMENT_CHAR)
			{
				return (1);
			}
		}
	}
	return (0);
}

static int	asm_parse_name(t_asm_data *data, t_header *h, char **line)
{
	int		ret_gnl;
	size_t	i;
	size_t	j;

	j = 0;
	ret_gnl = asm_gn_pertinent_l(data, line, &i);
	if (ret_gnl == 1 && !ft_strncmp(NAME_CMD_STRING, &(*((*line) + i)), 5))
	{
		i = i + 5;
		asm_skip_spacing_chars(*line, &i);
		if (asm_get_quote(&(*((*line) + i)), h->prog_name, PROG_NAME_LENGTH,\
					&j))
		{
			return (1);
		}
	}
	return (j == PROG_NAME_LENGTH ? asm_name_does_not_fit()\
			: asm_failed_to_get_prog_name(data));
}

static int	asm_parse_comment(t_asm_data *data, t_header *h, char **line)
{
	int		ret_gnl;
	size_t	i;
	size_t	j;

	j = 0;
	ret_gnl = asm_gn_pertinent_l(data, line, &i);
	if (ret_gnl == 1 && !ft_strncmp(COMMENT_CMD_STRING, &(*((*line) + i)), 8))
	{
		i = i + 8;
		asm_skip_spacing_chars(*line, &i);
		if (asm_get_quote(&(*((*line) + i)), h->comment, COMMENT_LENGTH, &j))
		{
			return (1);
		}
	}
	return (j == COMMENT_LENGTH ? asm_comment_does_not_fit()\
			: asm_failed_to_get_comment(data));
}

/*
** Auparavant :
** L'assignation
**	h->prog_size = (unsigned int)FT_CHAMP_LENGTH;
** n'a aucun interet dans le programme,
** mais est tres jolie
*/

int			asm_parse_header(t_asm_data *data, t_header *h, char **line)
{
	h->magic = (unsigned int)COREWAR_EXEC_MAGIC;
	asm_initialize_header_struct(h);
	if (asm_parse_name(data, h, line)
			&& asm_parse_comment(data, h, line))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
