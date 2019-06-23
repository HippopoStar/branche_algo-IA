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
** Dans la fonction 'li_erase_alone', si une suite de liaisons
** n'est pas reliee au reste de la fourmiliere,
** la derniere salle se verra isolee mais non effacee
** lors de cet appel
*/

void	li_erase_alone(t_data *data, size_t i, int *wit)
{
	size_t	tmp;

	if ((*(data->map + i))->nb_of_bonds == 0)
	{
		li_erase_room(data, i);
	}
	else
	{
		while (!(i == 0 || i == data->size - 1) && (*(data->map + i))->nb_of_bonds == 1)
		{
			tmp = *((*(data->map + i))->bond_sum + 0);
			li_erase_room(data, i);
			i = tmp;
		}
		if ((*(data->map + i))->nb_of_bonds == 0 && !(i == 0 || i == data->size - 1))
		{
			li_erase_room(data, i);
		}
	}
	*wit = 1;
}

size_t	li_forward(t_data *data, size_t i, size_t j)
{
	if ((*(data->map + j))->nb_of_bonds == 2)
	{
		if (*((*(data->map + j))->bond_sum + 0) == i)
		{
			return (*((*(data->map + j))->bond_sum + 1));
		}
		else
		{
			return (*((*(data->map + j))->bond_sum + 0));
		}
	}
	else
	{
		return (0);
	}
}

int		aux_li_erase_more(t_data *data, size_t i, size_t tar_a, size_t tar_b)
{
	size_t	a;
	size_t	b;

	a = i;
	b = i;
}

void	li_erase_more(t_data *data, size_t i, int *wit)
{
	size_t	a;
	size_t	b;
	size_t	tar_a;
	size_t	tar_b;

	a = 0;
	while (a < (*(data->map + i))->nb_of_bonds - 1)
	{
		tar_a = *((*(data->map + i))->bond_sum + a);
		if ((*(data->map + tar_a))->nb_of_bonds == 2)
		{
			b = a + 1;
			while (b < (*(data->map + i))->nb_of_bonds)
			{
				if ((*(data->map + tar_b))->nb_of_bonds == 2)
				{
					*wit = (*wit) + aux_li_erase_more(data, i, tar_a, tar_b);
				}
				b++;
			}
		}
		a++;
	}
}

void	li_epur(t_data *data)
{
	size_t	i;
	int		wit;

	data->eff = data->size - 1;
	wit = 1;
	while (wit > 0)
	{
		wit = 0;
		i = 1;
		while (i < data->eff)
		{
			if ((*(data->map + i))->nb_of_bonds < 2)
			{
				li_erase_alone(data, i, &wit);
			}
			else
			{
				li_erase_more(data, i, &wit);
			}
			i++;
		}
	}
}
