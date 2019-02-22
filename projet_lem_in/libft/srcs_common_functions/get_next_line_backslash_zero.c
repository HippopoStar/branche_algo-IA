/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_backslash_zero.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 06:30:23 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 06:30:58 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_backslash_zero.h"

/*
** bs_p : backspace_place
** r_v  : read_value
*/

static t_gnl	*creer_maillon(const int fd)
{
	t_gnl			*maillon;

	if (!(maillon = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	maillon->fd = fd;
	maillon->bs_p = 0;
	if ((maillon->r_v = read(fd, maillon->buff, BUFF_SIZE)) == -1)
	{
		free(maillon);
		return (NULL);
	}
	maillon->next = NULL;
	return (maillon);
}

/*
** tab[0] : previous_length
** tab[1] : to_add
** tab[2] : i
*/

int				aux_3_gnl_bsz(const int fd, char **line,\
													t_gnl *mai, ssize_t tab[3])
{
	char			*tmp;
	int				retour;

	tab[0] = 0;
	while (*((*line) + tab[0]) != '\0' || (tab[1] = 0) != 0)
		tab[0]++;
	while ((*(tmp = mai->buff + mai->bs_p + tab[1]) != '\n' && *tmp != '\0'
				&& mai->bs_p + tab[1] < mai->r_v) || (tab[2] = 0) != 0)
		tab[1]++;
	if (!(tmp = (char *)malloc((tab[0] + tab[1] + 1) * sizeof(char))))
		return (-1);
	while (tab[2]++ < tab[0] || (tab[2] = 0) != 0)
		*(tmp + (tab[2] - 1)) = *((*line) + (tab[2] - 1));
	free(*line);
	while (tab[2] < tab[1])
		*(tmp + tab[0] + tab[2]++) = *(mai->buff + (mai->bs_p)++);
	*(tmp + tab[0] + tab[1]) = '\0';
	*line = tmp;
	if (mai->bs_p == mai->r_v)
		return ((retour = aux_2_gnl_bsz(fd, line, mai)) == 0 ? 1 : retour);
	mai->bs_p++;
	return (1);
}

int				aux_2_gnl_bsz(const int fd, char **line, t_gnl *maillon)
{
	ssize_t			p_l__t_a[3];

	if (maillon->bs_p == maillon->r_v)
	{
		if ((maillon->r_v = read(fd, maillon->buff, BUFF_SIZE)) == -1)
			return (-1);
		maillon->bs_p = 0;
		return (maillon->r_v == 0 ? 0
								: aux_3_gnl_bsz(fd, line, maillon, p_l__t_a));
	}
	else
	{
		return (aux_3_gnl_bsz(fd, line, maillon, p_l__t_a));
	}
}

int				aux_1_gnl_bsz(const int fd, char **line, t_gnl *maillon)
{
	int				retour;
	t_gnl			*tmp;

	if (maillon->fd != fd)
	{
		if (maillon->next != NULL && (maillon->next)->fd == fd)
		{
			if ((retour = aux_2_gnl_bsz(fd, line, maillon->next)) == 0)
			{
				tmp = maillon->next;
				maillon->next = (maillon->next)->next;
				free(tmp);
			}
			return (retour);
		}
		if (maillon->next == NULL)
		{
			if (!(maillon->next = creer_maillon(fd)))
				return (-1);
			return (aux_1_gnl_bsz(fd, line, maillon));
		}
		return (aux_1_gnl_bsz(fd, line, maillon->next));
	}
	else
		return (aux_2_gnl_bsz(fd, line, maillon));
}

/*
** Remarque :
** En raison de la condition employee pour determiner de la liberation du
** premier maillon, dans le cas ou le nombre de caracteres du fichier
** correspondant au premier file_descriptor est exactement un multiple
** de BUFF_SIZE, 'get_next_line' va effectuer un 'malloc' et un 'free' de plus
** que necessaire
*/

int				get_next_line_backslash_zero(const int fd, char **line)
{
	int				retour;
	t_gnl			*tmp;
	static t_gnl	*chaine;

	if (line == NULL || !((*line) = (char *)malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (chaine == NULL && !(chaine = creer_maillon(fd)))
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if ((retour = aux_1_gnl_bsz(fd, line, chaine)) == -1)
	{
		free(*line);
		*line = NULL;
	}
	if (chaine->r_v == 0)
	{
		tmp = chaine->next;
		free(chaine);
		chaine = tmp;
	}
	return (retour);
}
