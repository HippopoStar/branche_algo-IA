/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_remove_edges.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:33:36 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/20 16:53:00 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** On ne peut pas depasser les tableaux dans un sens ni dans l'autre,
** car on sait que chaque tableau commence par '0', correspondant a
** la 1ere salle, et se termine par 'data->size', correspondant a la derniere
** salle (au plus tard en position 'data->size - 1')
*/

/*
** La maniere de calculer en place les longueurs des itineraires
** dans la fonction 'li_edge_len' peut surprendre
** mais il ne faut pas omettre qu'elle deplace d'abord localement
** les indexs
**
** Par ailleurs elle remplie les champs contenant les tailles futures
** des deux itineraires concernes, mais cela n'impacte pas la suite de l'algo'
** car par la suite les chaines se copient jusqu'a 'data->size' et non
** jusqu'a leurs longueures respectives
**
** On peut vouloir ajouter les lignes suivantes apres l'assignation
** des variables 'len_1' et 'len_2' (16 lignes) :
**	ft_putstr("begin :\n");
**	ft_putstr("(*len_1) vaut : ");
**	ft_putnbr((int)(*len_1));
**	ft_putchar('\n');
**	ft_putstr("(*len_2) vaut : ");
**	ft_putnbr((int)(*len_2));
**	ft_putchar('\n');
**	ft_putstr("edge_len vaut : ");
**	ft_putnbr((int)edge_len);
**	ft_putchar('\n');
**	ft_putstr("j vaut : ");
**	ft_putnbr((int)j);
**	ft_putchar('\n');
**	ft_putstr("k vaut : ");
**	ft_putnbr((int)k);
**	ft_putchar('\n');
** Ainsi que les lignes suivantes avant le retour de la fonction :
**	ft_putstr("(*len_1) vaut : ");
**	ft_putnbr((int)(*len_1));
**	ft_putchar('\n');
**	ft_putstr("(*len_2) vaut : ");
**	ft_putnbr((int)(*len_2));
**	ft_putchar('\n');
*/

size_t	li_edge_len(t_route *route, size_t i, size_t j, size_t k)
{
	size_t	edge_len;
	size_t	*len_1;
	size_t	*len_2;
	size_t	tmp;

	edge_len = 0;
	while (*(*(route->field + i) + j - 1)
			== *(*(route->field + route->height) + k + 1))
	{
		j--;
		k++;
		edge_len++;
	}
	len_1 = &(*(*(route->field + i) + route->width));
	len_2 = &(*(*(route->field + route->height) + route->width));
	tmp = (*len_1);
	*len_1 = j + ((*len_2) - k);
	*len_2 = k + (tmp - j) - (2 * edge_len);
	return (edge_len);
}

/*
** A la fin de la premiere boucle :
** 'j == route->width || k + edge_len == route->width'
**
** 1er cas :
** - La 2eme liste a copie la 1ere jusqu'a 'route->width' de cette derniere,
** mais ne s'est pas necessairement completee par des '0'
** (ce n'est pas le cas si on a 'k < j')
** - La 1ere liste a copie la 2eme jusqu'a 'route->width - edge_len',
** la suite devant etre remplacee par des '0'
**
** 2eme cas :
** - La 1ere liste a copie la 2eme jusqu'a 'route->width' de cette derniere,
** mais ne s'est pas necessairement completee par des '0'
** (ce n'est pas le cas si on a 'j - edge_len < k + edge_len')
** - La 2eme liste a copie la 1ere jusqu'a 'route->width - edge_len',
** la suite devant etre remplacee par des '0'
*/

int		li_melt_paths(t_route *route, size_t i, size_t j, size_t k)
{
	size_t	edge_len;

	if (!(edge_len = li_edge_len(route, i, j, k)))
		return (0);
	while (j < route->width && k + edge_len < route->width)
	{
		*(*(route->field + i) + j - edge_len) = *(*(route->field
					+ route->height) + k + edge_len);
		*(*(route->field + route->height) + k) = *(*(route->field + i) + j);
		j++;
		k++;
	}
	while (j - edge_len < route->width || k < route->width)
	{
		if (j - edge_len < route->width)
		{
			*(*(route->field + i) + j - edge_len) = 0;
		}
		if (k < route->width)
		{
			*(*(route->field + route->height) + k) = 0;
		}
		j++;
		k++;
	}
	return (1);
}

/*
** Il est necessaire d'apres l'implementation de la suite de l'algorithme
** de pacourir la combinaison d'itineraires d'abord suivant les colonnes
** (distance a la salle de depart) puis suivant les lignes (les itineraires)
** car on doit detecter les superpositions dans l'ordre dans lesquelles elles
** interviennent, afin qu'en echangeant les positions des itineraires ainsi
** fondus, toutes les eventuelles superpositions restantes soient necessairement
** dans la suite de l'itineraire positionne a l'index 'route->height'
**
** On peut vouloir ajouter les lignes suivantes avant l'appel de 'li_melt_paths'
** (20 lignes)
**		ft_putstr("Avant appel de 'li_melt_paths'\n");
**		li_print_route(route, route->height);
**		ft_putstr("i vaut : ");
**		ft_putnbr((int)(*i));
**		ft_putchar('\n');
**		ft_putstr("j vaut : ");
**		ft_putnbr((int)(*j));
**		ft_putchar('\n');
**		ft_putstr((*((route->data_ptr)->map
**						+ *(*(route->field + (*i)) + (*j))))->name);
**		ft_putchar('\n');
**		ft_putstr("route->height vaut : ");
**		ft_putnbr((int)route->height);
**		ft_putchar('\n');
**		ft_putstr("k vaut : ");
**		ft_putnbr((int)(*k));
**		ft_putchar('\n');
**		ft_putstr((*((route->data_ptr)->map
**						+ *(*(route->field + route->height) + (*k))))->name);
**		ft_putchar('\n');
**
** Puis :
**		ft_putstr("Apres appel de 'li_melt_paths'\n");
**		li_print_route(route, route->height);
*/

int		aux_li_remove_edges(t_route *route, size_t *i, size_t *j, size_t *k)
{
	int		ret_val;

	if ((*j) < *(*(route->field + (*i)) + route->width)
			&& *(*(route->field + (*i)) + (*j)) == *(*(route->field
					+ route->height) + (*k)))
	{
		ret_val = li_melt_paths(route, (*i), (*j), (*k));
		li_swap_paths(route, (*i), route->height);
		*k = 1;
		*j = route->width;
		*i = route->height;
	}
	return (ret_val);
}

int		li_remove_edges(t_route *route)
{
	int		ret_val;
	size_t	i;
	size_t	j;
	size_t	k;

	ret_val = 1;
	k = 1;
	while (ret_val && k + 1 < *(*(route->field + route->height) + route->width))
	{
		j = 1;
		while (ret_val && j < route->width)
		{
			i = 0;
			while (ret_val && i < route->height)
			{
				ret_val = aux_li_remove_edges(route, &i, &j, &k);
				i++;
			}
			j++;
		}
		k++;
	}
	return (ret_val);
}
