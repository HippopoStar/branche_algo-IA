/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_erase_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:35:30 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/25 22:10:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**      F - G
**     /    |\       .V
**    E     H I
**    |      \|
**    D       J        Q
**     \     /        /
**      C - K    O - P
**     /        /
** A - B - M - N - R - Z
**        / \
**       S - T
**            \      W - X
**             U      \ /
**                     Y
*/
/*
** Etape 1:
** - eliminer les salles isolees [V]
** Etape 2:
** - eliminer recursivement les salles n'ayant qu'une liaison [Q-P-O | U]
**    (si le nombre de liaisons de la salle atteinte '- 1' vaut :
**    '0' : l'eliminer
**    '1' : l'eliminer et poursuivre
**    '+' : s'arreter
** Etape 3:
** - eliminer les boucles
**     Pour chaque salle :
**     - Tant qu'il existe un couple de laisons
**       | OU | Si la salle possede uniquement 2 liaisons
**       ... vers des salles voisines comportant
**           chacune 1 seule autre liaison [G | S | W]
**         - Tant que les salles atteintes par chacun des 2 itineraires
**           ne sont pas confondues (condition necessaire, voir [W-X-Y]),
**           et qu'elles ne possedent qu'une seule autre liaison
**             - Suivre ces liaisons [G->H->J ; G->I->J | S->M ; S->T->M | W[...]]
**         - Si elles rejoignent toutes 2 une meme salle
**           ou qu'elle se sont toutes les 2 rejointes
**             - Eliminer le plus long trajet vers cette meme salle [I | T | W[...]]
**
** Repeter les etapes 2 et 3 autant de fois que necessaire
*/

/*
** Rappel :
** Les salles de depart et d'arrivee ne peuvent etre supprimees dans
** l'appel de 'li_erase_room'
**
** Cependant, il est tout de meme preferable de ne pas betement supprimmer
** l'evantuel seul chemin qui y mene !
**
** ref_a[0] = previous 'a'
** ref_a[1] = 'a'
** ref_a[2] = lenght to 'a'
**
**		ft_putstr("aux_li_determine_cycle\n");
*/

int		aux_li_determine_cycle(t_data *data, size_t ref_a[3], size_t ref_b[3])
{
	int		ret_val;

	ret_val = 1;
	if ((*(data->map + ref_a[1]))->nb_of_bonds == 1 && !(ref_a[1] == 0 || ref_a[1] == data->size - 1))
	{
		ft_putstr("aux_li_determine_cycle\n");
		li_erase_room(data, ref_a[1]);
		ret_val = 2 * ret_val;
	}
	if ((*(data->map + ref_b[1]))->nb_of_bonds == 1 && !(ref_b[1] == 0 || ref_b[1] == data->size - 1))
	{
		ft_putstr("aux_li_determine_cycle\n");
		li_erase_room(data, ref_b[1]);
		ret_val = 3 * ret_val;
	}
	return (ret_val);
}

/*
** Rappel :
** Les salles de depart et d'arrivee ne peuvent etre supprimees dans
** l'appel de 'li_erase_room'
**
**>	else if ((*(data->map + ref_a[1]))->nb_of_bonds < 4)< ?
**
**		ft_putstr("li_determine_cycle\n");
*/

int		li_determine_cycle(t_data *data, size_t ref_a[3], size_t ref_b[3])
{
	if (!(ref_a[1] == ref_b[1]))
	{
		return (aux_li_determine_cycle(data, ref_a, ref_b));
	}
	else
	{
		if ((*(data->map + ref_a[1]))->nb_of_bonds == 2)
		{
			ft_putstr("li_determine_cycle\n");
			li_erase_room(data, ref_a[1]);
			return (6);
		}
		else
		{
			return (ref_b[2] < ref_a[2] ? 2 : 3);
		}
	}
}

/*
** La condition sur 'a == ref_b[0] || a == ref_b[1]' est probablement ameliorable
**
**			ft_putstr("rec_li_erase_cycle\n");
**
** (15 lignes)
**		ft_putstr("\"ret_val\" vaut : ");
**		ft_putnbr(ret_val);
**		ft_putchar('\n');
**		ft_putstr("\"a\" vaut : ");
**		ft_putstr((*(data->map + a))->name);
**		ft_putchar('\n');
**		ft_putstr("\"ref_a[1]\" vaut : ");
**		ft_putstr((*(data->map + ref_a[1]))->name);
**		ft_putchar('\n');
**		ft_putstr("\"b\" vaut : ");
**		ft_putstr((*(data->map + b))->name);
**		ft_putchar('\n');
**		ft_putstr("\"ref_b[1]\" vaut : ");
**		ft_putstr((*(data->map + ref_b[1]))->name);
**		ft_putchar('\n');
*/

int		rec_li_erase_cycle(t_data *data, size_t ref_a[3], size_t ref_b[3], size_t iter)
{
	size_t	a;
	size_t	b;
	int		ret_val;

	if (!(ref_a[1] == ref_b[1] || (ref_a[0] == ref_a[1] && ref_b[0] == ref_b[1])))
	{
		a = ref_a[1];
		b = ref_b[1];
		li_forward_ref(data, ref_b);
		if (!(ref_a[1] == ref_b[1]))
		{
			li_forward_ref(data, ref_a);
		}
		ret_val = rec_li_erase_cycle(data, ref_a, ref_b, iter + 1);
		if (ret_val % 2 == 0 && !(a == ref_a[1]) && b < data->eff) //TODO
		{
			ft_putstr("rec_li_erase_cycle\n");
			li_erase_room(data, a);
		}
		if (ret_val % 3 == 0 && !(b == ref_b[1]) && b < data->eff) //TODO
		{
			ft_putstr("rec_li_erase_cycle\n");
			li_erase_room(data, b);
		}
		li_print_map_summary(data);
		return (ret_val);
	}
	else
	{
		return (li_determine_cycle(data, ref_a, ref_b));
	}
}

/*
** (8 lignes)
**	ft_putstr("Initialisation de \"rec_li_erase_cycle\" :\n");
**	ft_putstr("salle de depart : ");
**	ft_putstr((*(data->map + i))->name);
**	ft_putstr("itineraire 'a' : ");
**	ft_putstr((*(data->map + tar_a))->name);
**	ft_putstr("itineraire 'b' : ");
**	ft_putstr((*(data->map + tar_b))->name);
**	ft_putchar('\n');
*/

void	aux_li_erase_cycle(t_data *data, size_t i, size_t tar_a, size_t tar_b)
{
	size_t	ref_a[3];
	size_t	ref_b[3];

	ref_a[0] = i;
	ref_b[0] = i;
	ref_a[1] = tar_a;
	ref_b[1] = tar_b;
	ref_a[2] = 0;
	ref_b[2] = 0;
	ft_putstr("\033[34mInitialisation de \"rec_li_erase_cycle\" :\n");
	ft_putstr("salle de depart : ");
	ft_putstr((*(data->map + i))->name);
	ft_putstr("\nitineraire 'a' : ");
	ft_putstr((*(data->map + tar_a))->name);
	ft_putstr("\nitineraire 'b' : ");
	ft_putstr((*(data->map + tar_b))->name);
	ft_putstr("\033[00m\n");
	rec_li_erase_cycle(data, ref_a, ref_b, 0);
}

/*
** Remarque :
**
** Ne pas omettre, que si le nombre de liaisons de la salle d'index 'i' est au
** depart superieur ou egale a '2', rien ne garanti que ca reste le cas apres
** quelques appels de 'aux_li_erase_cycle' !
**
** Par ailleurs, n'omettons pas que la salle pointee par l'index 'i' peut
** entre-temps avoir vu sa position etee intervertie avec une autre salle !
**
** En revanche, il semble acquis que la salle pointee par l'index 'i', quelle
** qu'elle soit, sera toujours une salle a tester
**
** Cela, il n'est pas garanti que la liaison
** '*((*(data->map + i))->bond_sum + a)'
** designe une salle voisine possedant strictement 2 liaisons !
**
** / ! \
**
** Si une la position d'une salle devant etre effacee dans un certain appel
** recursif, est intervertie avec celle de de l'avant-dernier element lors
** d'un appel recursif plus haut dans la pile,
** cela a pour effet de declencher en boucle l'effacement de cette salle
**
** 2 solutions a creuser :
** - Soit n'appeler 'li_erase_room' que dans le cas ou l'index cible est
**   encore '< data->eff' dans 'rec_li_erase_cycle'
** - Soit n'intervertir les indexs dans que si l'index de la salle a effacer
**   est '< data->eff' dans 'li_erase_room'
**
**		ft_putstr("(li_erase_cycle)");
**		li_display_room_info(data, i);
**		ft_putchar('\n');
**		ft_putnbr((int)a);
**		ft_putchar('\n');
*/

void	li_erase_cycle(t_data *data, size_t i)
{
	size_t	a;
	size_t	b;
	size_t	tar_a;
	size_t	tar_b;

	a = 0;
	while (a < (*(data->map + i))->nb_of_bonds)
	{
		tar_a = *((*(data->map + i))->bond_sum + a);
		if ((*(data->map + tar_a))->nb_of_bonds == 2) //TODO
		{
			b = a + 1;
			while (b < (*(data->map + i))->nb_of_bonds)
			{
				tar_b = *((*(data->map + i))->bond_sum + b);
				if ((*(data->map + tar_b))->nb_of_bonds == 2)
				{
					aux_li_erase_cycle(data, i, tar_a, tar_b);
				}
				b++;
			}
		}
		a++;
	}
}
