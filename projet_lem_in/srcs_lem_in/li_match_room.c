/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_match_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:54:00 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/10 21:16:20 by lcabanes         ###   ########.fr       */
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

int		li_is_name_available(t_room *current, t_data *data)
{
	t_room		*tmp;

	tmp = data->rooms;
	while (tmp && tmp != current)
	{
		if (!ft_strcmp(tmp->name, current->name))
		{
			return (0);
		}
		tmp = tmp->next;
	}
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
/*
** La fonction 'li_deal_sharp_marks' assigne a 'room->role' sa valeur de retour
** qui vaut :
** '0' si 'line' correspond a la commande '##start' ou '##end'
**     et qu'une de ces 2 commandes a dors et deja ete invoquee
**     dans le meme bloc de commentaires/commandes
** '1' si 'line' correspond a un commentaire
** '2' si 'line' correspond a la commande '##start'
** '3' si 'line' correspond a la commande '##end'
*/

void	li_deal_sharp_marks(t_room *current, char *line, int *wit)
{
	if (!ft_strcmp(line, "##start") && (*wit) % 2 != 0)
	{
		*wit = (*wit) * 2;
		current->role = 2;
	}
	else if (!ft_strcmp(line, "##end") && (*wit) % 3 != 0)
	{
		*wit = (*wit) * 3;
		current->role = 3;
	}
	else
	{
		*wit = 0;
	}
	free(line);
}

/*
** Note:
** Dans une description de fourmiliere valide :
** - Aucune ligne ne doit commencer par 'L'
** - Hormis les commentaires, les seules lignes contenant des espaces sont
**     les declarations de salles, et elles doivent en contenir exactement 2
**
** Sachant cela, la fonction 'li_match_room' renvoie :
** '0' en cas de detection d'une incoherence
**     (room->role vaut '1')
** '1' sinon (salle valide ou non salle)
**     (salle valide : room->role vaut '1')
**     (non salle : room->role vaut '5')
*/

int		aux_li_match_room(t_room *current, char *line, int *wit)
{
	size_t	i;

	current->name = line;
	if (*(line + 0) == 'L')
		return (0);
	i = 0;
	while (*(line + i) != ' ' && *(line + i) != '\0')
	{
		i++;
	}
	if (*(line + i) == ' ')
	{
		*(line + i) = '\0';
		i++;
	}
	else
	{
		*wit = (*wit) * 5;
		return ((current->role == 2 || current->role == 3) ? 0 : 1);
	}
	if (!ft_is_int(line, &i, &(current->pos_x)) && *(line + i) == ' ')
		return (0);
	i++;
	return ((ft_is_int(line, &i, &(current->pos_y)) && *(line + i) == '\0')
			? 1 : 0);
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
/*
** La fonction 'li_match_rooms' revoie :
** '-1' si 'line' correspond a la commande '##start' ou '##end'
**      et qu'une de ces 2 commandes a dors et deja ete invoquee
**      dans le meme bloc de commentaires/commandes
** '0' si 'line' correspond a un commentaire
** '1' si 'line' correspond a une description de salle
** '2' si 'line' correspond a la commande '##start'
** '3' si 'line' correspond a la commande '##end'
** '5' sinon
*/

void	li_match_room(t_data *data, char *line, t_room **current, int *wit)
{
	if (*(line + 0) == '#')
	{
		li_deal_sharp_marks(*current, line, wit);
	}
	else
	{
		if (aux_li_match_room(*current, line, wit) && !((*wit) % 5 == 0)
				&& li_is_name_available(*current, data))
		{
			*current = (*current)->next;
		}
		else
		{
			free(*current);
			*current = NULL;
			if (!((*wit) % 5 == 0))
			{
				free(line);
				*wit = 0;
			}
		}
	}
}