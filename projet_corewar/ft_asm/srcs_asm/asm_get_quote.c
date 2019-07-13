#include "ft_asm.h"

static int	aux_asm_get_quote(t_asm_data *data, size_t *i, char *to_fill,\
																	size_t size)
{
	char	**line;
	int		ret_gnl;
	size_t	j;

	ret_gnl = 1;
	line = &(data->current_line);
	j = 0;
	while (ret_gnl == 1 && j < size && !(*((*line) + (*i)) == '"'))
	{
		if (*((*line) + (*i)) == '\0')
		{
			ret_gnl = get_next_line_backslash_zero(data->input_fd, line);
			*i = 0;
			*(to_fill + j) = '\n';
		}
		else
		{
			*(to_fill + j) = *((*line) + (*i));
			(*i)++;
		}
		j++;
	}
	*(to_fill + j) = '\0';
	return (ret_gnl == 1 ? 1 : 0);
}

/*
** Ajout de l'argument (size_t *)j pour l'appel de 'asm_'[...]'_does_not_fit
**
** Le fait de typer la variable 'size' en 'size_t' dans le prototype permet
** de caster automatiquement la macro passee en parametre
**
** Garder en tete qu'on peut avoir un commentaire de taille '0'
**
** Anciennement :
**	size_t	remnant_size;
*/

int		asm_get_quote(t_asm_data *data, size_t i, char *to_fill,\
																	size_t size)
{
	char	**line;

	line = &(data->current_line);
	if (*((*line) + i) == '"')
	{
		i++;
		if (aux_asm_get_quote(data, &i, to_fill, size) && *((*line) + i) == '"')
		{
			i++;
			asm_skip_spacing_chars(*line, &i);
			if (*((*line) + i) == '\0' || *((*line) + i) == COMMENT_CHAR)
			{
				return (1);
			}
		}
	}
	return (0);
}
