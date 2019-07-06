#include "ft_asm.h"

static int	asm_get_quote(char *line, char *to_fill, int size)
{
	size_t	i;

	if (*(line + 0) == '"')
	{
		line++;
		i = 0;
		while (i < (size_t)size && !(*(line + i) == '"' || *(line + i) == '\0'))
		{
			*(to_fill + i) = *(line + i);
			i++;
		}
		*(to_fill + i) = '\0';
		if (*(line + i) == '"')
		{
			i++;
			asm_skip_spacing_chars(line, &i);
			if (*(line + i) == '\0' || *(line + i) == COMMENT_CHAR)
			{
				return (1);
			}
		}
	}
	return (0);
}

static int	asm_parse_name(t_asm_data *data, t_header *h, char **line)
{
	size_t	i;

	asm_gn_pertinent_l(data, line, &i);
	if (!ft_strncmp(".name", &(*((*line) + i)), 5))
	{
		i = i + 5;
		asm_skip_spacing_chars(*line, &i);
		if (asm_get_quote(&(*((*line) + i)), h->prog_name, PROG_NAME_LENGTH))
		{
			return (1);
		}
	}
	return (asm_failed_to_get_prog_name(data));
}

static int	asm_parse_comment(t_asm_data *data, t_header *h, char **line)
{
	size_t	i;

	asm_gn_pertinent_l(data, line, &i);
	if (!ft_strncmp(".comment", &(*((*line) + i)), 8))
	{
		i = i + 8;
		asm_skip_spacing_chars(*line, &i);
		if (asm_get_quote(&(*((*line) + i)), h->comment, COMMENT_LENGTH))
		{
			return (1);
		}
	}
	return (asm_failed_to_get_comment(data));
}

/*
** Auparavant :
** L'assignation
**	h->prog_size = (unsigned int)FT_CHAMP_LENGTH;
** n'a aucun interet dans le programme,
** mais est tres jolie
*/

int		asm_parse_header(t_asm_data *data, t_header *h, char **line)
{
	h->magic = (unsigned int)COREWAR_EXEC_MAGIC;
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
