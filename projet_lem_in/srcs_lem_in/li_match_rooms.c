/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_match_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:56 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/09 16:53:52 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Allocation dynamique de memoire dans 'li_allocate_room'
** (t_room *)*room : data->rooms (liste chainee)
*/

int		li_allocate_room(t_room **room)
{
	if (!(*room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	(*room)->name = NULL;
	(*room)->role = 1;
	(*room)->nb_of_bonds = 0;
	(*room)->pipes = NULL;
	(*room)->next = NULL;
	return (1);
}

/*
** La fonction 'li_deal_sharp_marks' met egalement a profit
** le fait que la variable '(t_room *)->role' soit initialisee a '1'
** dans la fonction 'li_allocate_room',
** pour s'en servir dans sa valeur de retour
** et ne renvoyer '0' que si 2 lignes '##start' ou '##end' sont presentes
** dans la meme section de commentaires/commandes
*/

int		li_deal_sharp_marks(t_room *room, t_input **read)
{
	while (*read && (*((*read)->line) + 0) == '#')
	{
		if (!ft_strcmp((*read)->line, "##start"))
		{
			room->role = (room->role == 1) ? 2 : 0;
		}
		else if (!ft_strcmp((*read)->line, "##end"))
		{
			room->role = (room->role == 1) ? 3 : 0;
		}
		*read = (*read)->next;
	}
	return (room->role);
}

int		li_match_room(t_room *room, char *str)
{
	size_t	i;

	room->name = str;
	if (*(str + 0) == 'L')
		return (0);
	i = 0;
	while (*(str + i) != ' ' && *(str + i) != '\0')
	{
		i++;
	}
	if (*(str + i) == ' ')
	{
		*(str + i) = '\0';
		i++;
	}
	else
	{
		room->role = 5;
		return (1);
	}
	if (!ft_is_int(str, &i, &(room->pos_x)) && *(str + i) == ' ')
		return (0);
	i++;
	return ((ft_is_int(str, &i, &(room->pos_y)) && *(str + i) == '\0') ? 1 : 0);
}

/*
** Dans la fonction 'li_match_rooms',
** la condition 'if (!(*tmp) && !li_allocate_rooms(tmp))'
** permet de n'allouer un nouveau maillon que si on a avance
** dans la chaine des salles au cours de l'etape precedente
** (ie la ligne precedente correspondait a une declaration de salle)
**
** On met a profit le fait d'avoir initialise la variable '(t_room *)->role'
** a '1' lors de son allocation dans l'emploi de facteurs premiers
** concernant la variable 'wit'
** (permettant de s'assurer que la condition 'wit % 5 == 0' soit remplie
** seulement lorsqu'on a atteint la fin de la declaration des salles,
** et non par une combinaison de '##start' et de '##end')
*/

int		li_match_rooms(t_input **read, t_data *data)
{
	int		wit;
	t_room	**tmp;

	tmp = &(data->rooms);
	wit = 1;
	while (*read && wit % 5 != 0)
	{
		if (!(*tmp) && !li_allocate_room(tmp))
			return (0);
		if (*((*read)->line + 0) == '#' && !li_deal_sharp_marks(*tmp, read))
		{
			return (0);
		}
		else
		{
			if (!li_match_room(*tmp, (*read)->line))
			{
				return (0);
			}
			wit = wit * (*tmp)->role;
		}
		*read = ((*tmp)->role == 5) ? *read : (*read)->next;
		tmp = &((*tmp)->next);
	}
	return (wit == 30 ? 1 : 0);
}
