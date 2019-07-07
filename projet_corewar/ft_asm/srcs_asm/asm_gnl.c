#include "ft_asm.h"

/*
** Note :
** Il est important que la variable (char *)line,
** a la suite de sa declaration, soit initialisee a NULL
*/

static int		asm_gnl(t_asm_data *data, char **line)
{
	int		ret_gnl;

	if (!((*line) == NULL))
	{
		free(*line);
		(*line) = NULL;
	}
	if ((ret_gnl = get_next_line_backslash_zero(data->input_fd, line)) == 0
			&& !((*line) == NULL))
	{
		free(*line);
		(*line) = NULL;
	}
	(data->current_line_nb)++;
	return (ret_gnl);
}

/*
** asm_gn_pertinent_l
** skips empty lines and lines consisting of a comment only
**
** Tel quel, en raison de la nature de gnl_backslash_zero,
** ca foire si le fichier d'entree est /dev/zero
** En revanche, mecaniquement, le nom de fichier /dev/zero
** ne se termine pas par l'extension '.s'
** Que se passe-t'il dans le cas
** ln -s /dev/zero my_champ.s ?
** Ajouter un flag a open pour ne pas qu'il ouvre les fichiers
** se referant a des pseudo peripheriques ?
** Ajouter le flag O_NOFOLLOW afin qu'il ne suive pas les liens symboliques ?
*/

static int		aux_asm_gn_pertinent_l(t_asm_data *data, char **line, size_t *i)
{
	int		ret_gnl;

	if ((ret_gnl = asm_gnl(data, line)) == 1)
	{
		*i = 0;
		asm_skip_spacing_chars(*line, i);
	}
	return (ret_gnl);
}

int		asm_gn_pertinent_l(t_asm_data *data, char **line, size_t *i)
{
	int		ret_gnl;

	while ((ret_gnl = aux_asm_gn_pertinent_l(data, line, i)) == 1
			&& (*((*line) + (*i)) == '\0' || *((*line) + (*i)) == COMMENT_CHAR))
		;
	return (ret_gnl);
}
