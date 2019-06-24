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

void	li_erase_alone(t_data *data, size_t i)
{
	size_t	tmp;

	if ((*(data->map + i))->nb_of_bonds == 0)
	{
		li_erase_room(data, i);
	}
	else
	{
		while ((*(data->map + i))->nb_of_bonds == 1 && !(i == 0 || i == data->size - 1))
		{
			tmp = *((*(data->map + i))->bond_sum + 0);
			li_erase_room(data, i);
			i = tmp;
		}
		if ((*(data->map + i))->nb_of_bonds == 0)
		{
			li_erase_room(data, i);
		}
	}
}

size_t	li_forward(t_data *data, size_t i, size_t j)
{
	if ((*(data->map + j))->nb_of_bonds == 2 && !(j == 0 || j == data->size - 1))
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
		return (j);
	}
}

/*
** ref_a[0] = previous 'a'
** ref_a[1] = 'a'
** ref_a[2] = lenght to 'a'
*/

int		li_determine(t_data *data, size_t ref_a[3], size_t ref_b[3])
{
	if (!(ref_a[1] == ref_b[1]))
	{
		if ((*(data->map + ref_a[1]))->nb_of_bonds == 1)
		{
			li_erase_room(data, ref_a[1]);
			return (2);
		}
		if ((*(data->map + ref_b[1]))->nb_of_bonds == 1)
			return (3);
		return (1);
	}
	else if ((*(data->map + ref_a[1]))->nb_of_pipes == 2)
	{
		li_erase_room(data, ref_a[1]);
		return (6);
	}
	else if ((*(data->map + ref_a[1]))->nb_
}

int		rec_li_erase_more(t_data *data, size_t ref_a[3], size_t ref_b[3])
{
	size_t	a;
	size_t	b;
	int		ret_val;

	a = ref_a[1];
	b = ref_b[1];
	if (a == (ref_a[1] = li_forward(data, ref_a[0], a)) && b == (ref_b[1] = li_forward(data, ref_b[0], b)))
	{
		return (li_determine(data, ref_a, ref_b));
	}
	else
	{
		if (!(a == ref_a[1]))
		{
			ref_a[0] = a;
			(ref_a[2])++;
		}
		if (!(b == ref_b[1]))
		{
			ref_b[0] = b;
			(ref_b[2])++;
		}
		ret_val = rec_li_erase_more(data, ref_a, ref_b);
		if (ret_val % 2 == 0 && !(a == ref_a[1]))
		{
			li_erase_room(data, a);
		}
		if (ret_val % 3 == 0 && !(b == ref_b[1]))
		{
			li_erase_room(data, b);
		}
		return (ret_val);
	}
}

int		aux_li_erase_more(t_data *data, size_t i, size_t tar_a, size_t tar_b)
{
	size_t	ref_a[3];
	size_t	ref_b[3];

	ref_a[0] = i;
	ref_b[0] = i;
	ref_a[1] = tar_a;
	ref_b[1] = tar_b;
	ref_a[2] = 0;
	ref_b[2] = 0;
	return (rec_li_erase_more(data, ref_a, ref_b));
}

void	li_erase_more(t_data *data, size_t i)
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
					aux_li_erase_more(data, i, tar_a, tar_b);
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

	data->eff = data->size - 1;
	data->wit = 1;
	while (data->wit > 0)
	{
		data->wit = 0;
		i = 1;
		while (i < data->eff)
		{
			if ((*(data->map + i))->nb_of_bonds < 2)
			{
				li_erase_alone(data, i);
			}
			else
			{
				li_erase_more(data, i);
			}
			i++;
		}
	}
}
