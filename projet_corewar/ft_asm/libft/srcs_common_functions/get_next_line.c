/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 06:34:10 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/30 20:53:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** bs_p : backspace_place (correspond parfois a l'index dans le buffer
**                         du premier caractere a traiter davantage qu'a
**                         celui du dernier 'retour a la ligne' rencontre)
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
** La fonction 'aux_3_gnl'
** - Determine la longueur prealable de la chaine (~ ft_strlen)
** ( > 0 : cas dans lequel une ligne est a cheval entre 2 buffers de 'read')
** - Determine le nombre de carateres a ajouter a la chaine prealable
** lors de l'appel courant
** (~ max(index premier '\n' rencontre, nombre de caracteres lu par 'read')
**     - index de depart lors de l'appel)
** - Alloue dynamiquement de la memoire pour une nouvelle chaine de carateres
** contenant la concatenation de la chaine prealable et des autres caracteres
** - Copie dans la nouvelle chaine la chaine prealable
** - Libere la memoire attribuee a la chaine prealable ('*line')
** - Copie dans la nouvelle chaine les autres caracteres
** Note : lors de cette etape, la post-incrementation de la variable 'mai->bs_p'
**        a pour effet d'attribuer a cette derniere en fin de boucle la valeur
**        de 'mai->r_v' dans le cas ou on n'a pas rencontre de '\n'
** - Attribue au pointeur ('*line') l'adresse de la chaine obtenue
** - Si l'emplacement du dernier caratere a traite
** (contenu alors dans la variable 'mai->bs_p') correspond au nombre de
** carateres que le dernier appel de 'read' en date a lu,
** appel 'aux_2_gnl' en conservant sa valeur de retour et renvoie :
**     - '1' si cette derniere vaut '0'
**     (la prochaine valeur de retour de 'read' vaut '0',
**     le fichier a dors et deja ete lu integralement)
**     - cette valeur elle-meme sinon ('1' ou '-1')
** - Sinon, si l'emplacement du dernier caractere traite
** (contenu alors dans la variable 'mai->bs_p') ne correspond pas au nombre de
** carateres que le dernier appel de 'read' en date a lu,
** (on a alors ne-ce-ssaire-ment rencontre un '\n')
**     - Incremente la valeur de la variable 'mai->bs_p' indiquant alors
**     la position du dernier 'retour a la ligne' rencontre, afin qu'elle
**     corresponde a l'index du premier caractere de la ligne suivante
**     - Renvoie '1' (car la ligne est integralement retranscrite dans '*line')
**
**
** tab[0] : previous_length
** tab[1] : to_add
** tab[2] : i
*/

int				aux_3_gnl(const int fd, char **line, t_gnl *mai, ssize_t tab[3])
{
	char			*tmp;
	int				retour;

	tab[0] = 0;
	while (*((*line) + tab[0]) != '\0' || (tab[1] = 0) != 0)
		tab[0]++;
	while ((mai->bs_p + tab[1] < mai->r_v
				&& *(mai->buff + mai->bs_p + tab[1]) != '\n')
			|| (tab[2] = 0) != 0)
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
		return ((retour = aux_2_gnl(fd, line, mai)) == 0 ? 1 : retour);
	mai->bs_p++;
	return (1);
}

/*
** La fonction 'aux_2_gnl'
** - Si l'emplacement du dernier 'retour a la ligne' traite correspond
** au dernier caratere lu par 'read', rappelle 'read'
**     - Si 'read' ne lit pas davantage de caracteres, renvoie '0'
**     - Sinon, remet la variable indiquant l'emplacement du dernier
**     'retour a la ligne' traite a '0', et renvoie le retour de 'aux_3_gnl'
** - Sinon, renvoie le retour de 'aux_3_gnl'
*/

int				aux_2_gnl(const int fd, char **line, t_gnl *maillon)
{
	ssize_t			p_l__t_a[3];

	if (maillon->bs_p == maillon->r_v)
	{
		if ((maillon->r_v = read(fd, maillon->buff, BUFF_SIZE)) == -1)
			return (-1);
		maillon->bs_p = 0;
		return (maillon->r_v == 0 ? 0 : aux_3_gnl(fd, line, maillon, p_l__t_a));
	}
	else
	{
		return (aux_3_gnl(fd, line, maillon, p_l__t_a));
	}
}

/*
** Remarque :
** Peut-etre serait-il pertinent dans le cas d'une valeur de retour
** de 'aux_2_gnl' valant '-1' (echec d'un 'malloc' de '*line' ou d'un 'read')
** de liberer la memoire attribuee au maillon correspondant ?
*/

int				aux_1_gnl(const int fd, char **line, t_gnl *maillon)
{
	int				retour;
	t_gnl			*tmp;

	if (maillon->fd != fd)
	{
		if (maillon->next != NULL && (maillon->next)->fd == fd)
		{
			if ((retour = aux_2_gnl(fd, line, maillon->next)) == 0)
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
			return (aux_1_gnl(fd, line, maillon));
		}
		return (aux_1_gnl(fd, line, maillon->next));
	}
	else
		return (aux_2_gnl(fd, line, maillon));
}

/*
** Remarque :
** En raison de la condition employee pour determiner de la liberation du
** premier maillon, dans le cas ou le nombre de caracteres du fichier
** correspondant au premier file_descriptor est exactement un multiple
** de BUFF_SIZE, 'get_next_line' va effectuer un 'malloc' et un 'free' de plus
** que necessaire
*/

int				get_next_line(const int fd, char **line)
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
	if ((retour = aux_1_gnl(fd, line, chaine)) == -1)
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
