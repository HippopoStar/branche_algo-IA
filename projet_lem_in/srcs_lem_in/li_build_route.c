#include "lem_in.h"

/*
** Rappel :
** On alloue a chaque itineraire 'data->size + 2' emplacements car :
** '*(*(*(data->routes + ?) + ?) + data->size)'
**                      vaut le poids de l'itineraire
** '*(*(*(data->routes + ?) + ?) + data->size + 1)'
**                      vaut le nombre de fourmis l'empruntant
*/

void	aux_li_allocate_routes(t_data *data)
{
	size_t	n;
	size_t	i;
	size_t	j;

	n = 0;
	i = 1;
	while (i < data->max_paths)
	{
		n = n + i;
		*(data->routes + i) = &(*(*(data->routes + 0) + n));
		j = 0;
		while (j <= i)
		{
			*(*(data->routes + i) + j) = &(*(*(*(data->routes + 0) + 0)
						+ ((n + j) * (data->size + 2))));
			j++;
		}
		i++;
	}
}

/*
** Allocation dynamique de memoire dans 'li_allocate_routes'
** (size_t ***)data->routes
** (size_t **)*(data->routes + 0)
** (size_t *)*(*(data->routes + 0) + 0)
*/

int		li_allocate_routes(t_data *data)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (i <= data->max_paths)
	{
		n = n + i;
		i++;
	}
	if (!(data->routes = (size_t ***)malloc(data->max_paths * sizeof(size_t **)))
			|| !(*(data->routes + 0) = (size_t **)malloc(n * sizeof(size_t *)))
			|| !(*(*(data->routes + 0) + 0) = (size_t *)malloc(n
					* (data->size + 2) * sizeof(size_t))))
		return (0);
	aux_li_allocate_routes(data);
	return (1);
}

/*
** Dans la fonction 'aux_li_build_routes, on essaie de calculer en place
** la longueur de chaque itineraire nouvellement adapte
**
** Exemple de 'maps/basic_disjoint.map' :
**
**  / B - C \
**  A - E - D - H
**      \ F - G /
**
** A->E->D->H               donne   A->E->F->G->H   D(3) devient F(6)
** A->B->C->D->E->F->G->H     et    A->B->C->D->H   E(5) devient H(4)
**
** Exemple de 'maps/test_aux_li_build_routes.map'
**
** $> cat maps/build_instance.map
** #  / B - - - C \
** #  A - F - E - D - I
** #      \ G - - - H /
** 3
** ##start
** A 0 0
** B 0 0
** C 0 0
** D 0 0
** E 0 0
** F 0 0
** G 0 0
** H 0 0
** ##end
** I 0 0
** A-B
** A-F
** B-C
** C-D
** D-E
** D-I
** E-F
** F-G
** G-H
** H-I
** $>
**
** En appliquant la methode precedente :
**                                     !     !
** A->F->E->D->I            donne   A->F->E->F->G->H->I
** A->B->C->D->E->F->G->H->I  et    A->B->C->D->I
**
** A -> F  \  E   D  /> I
** A -> B -> C -> D  /  E   F  \> G -> H -> I
**
** Lors de l'appel de 'li_get_inversed_edge_length'
** *(*(route->field + i) + j)                           correspond a 'D'
** *(*(route->field + route->height) + k)               correspond a 'D'
** edge_len vaut 2
**
** -> 'D' etant l'element a partir duquel on souhaite bifurquer dans le 1er
**                                                                    itineraire
**
** *(*(route->field + i) + j - edge_len)                correspond a 'F'
** *(*(route->field + route->height) + k + edge_len)    correspond a 'F'
**
** -> 'F' etant l'element a partir duquel on souhaite bifurquer dans le 2nd
**                                                                    itineraire
**
**
** Apres avoir decale les positions dans les itineraires dans 'li_edge_len' :
** La longueur resultante du 1er itineraire vaut :
** j + (*(*(route->field + route->heigth) + route->width) - k)
** La longueur resultante du 2nd itineraire vaut :
** k + (*(*(route->field + i) + route->width) - j) - (2 * edge_len)
*/

void	li_copy_previous_route(t_data *data, size_t index)
{
	size_t	i;
	size_t	j;

	if (index > 0)
	{
		i = 0;
		while (i < index)
		{
			j = 0;
			while (j < data->size + 2)
			{
				*(*(*(data->routes + index) + i) + j) = *(*(*(data->routes
								+ index - 1) + i) + j);
				j++;
			}
			i++;
		}
	}
}

/*
** Rappel :
** Pour tout 0 <= i < data->path_nb,
** La variable *(*(data->paths + i) + data->size)
** correspond a l'index de depart de l'itineraire 'i' dans '*(data->path + i)'
** (voir 'li_bellman_ford' puis 'li_reverse_path')
**
** On initialise *(*(*(data->routes + i) + i) + data->size + 1)
** (devant par la suite prendre la valeur du nombre de fourmis devant traverser
** la fourmiliere en empruntant l'itineraire correspondant) a '0'
*/

void	li_copy_last_path(t_data *data, size_t i)
{
	size_t	j;

	j = 0;
	while (j + *(*(data->paths + i) + data->size) < data->size)
	{
		*(*(*(data->routes + i) + i) + j) = *(*(data->paths + i) + j
				+ *(*(data->paths + i) + data->size));
		j++;
	}
	*(*(*(data->routes + i) + i) + data->size) = j;
	*(*(*(data->routes + i) + i) + data->size + 1) = 0;
	while (j < data->size)
	{
		*(*(*(data->routes + i) + i) + j) = 0;
		j++;
	}
}

/*
** Rappel :
** Dans la fonction 'li_reverse_path' du fichier 'li_bhandari.c'
** assigne a la variable '*(*(data->paths + i) + data->size)'
** l'index de depart de l'itineraire
**
** Ainsi l'assignation
** *(*(*(data->routes + i) + i) + data->size)
**      = data->size - *(*(data->paths + i) + data->size)
** correspont a la longueur de l'itineraire
*/

void	li_build_route(t_data *data, size_t i)
{
	t_route	to_build;

	to_build.data_ptr = data;
	to_build.width = data->size;
	li_copy_previous_route(data, i);
	li_copy_last_path(data, i);
	to_build.height = i;
	to_build.field = *(data->routes + i);
	li_remove_edges(&to_build);
	li_order_paths(&to_build);
}
