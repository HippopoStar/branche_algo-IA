#include "lem_in.h"

/*
** Sommaire des allocations dynamiques de memoire :
** 'li_get_input'
**     (t_input *)*input : data->input (liste chainee)
**     (char *)line : (t_input *)->line (dans chaque maillon)
** 'li_allocate_room'
**     (t_room *)*room : data->rooms (liste chainee)
** 'li_allocate_map'
**     (t_room **)data->map
**     (int *)set_map : (*(data->map + 0))->pipes
** 'li_shorten_map_pipes'
**     (size_t *)(*(data->map + 0))->bond_sum
** 'li_allocate_paths'
**     (size_t **)data->paths
**     (size_t *)*(data->paths + 0)
** 'li_allocate_routes'
**     (size_t ***)data->routes
**     (size_t **)*(data->routes + 0)
**     (size_t *)*(*(data->routes + 0) + 0)
** 'li_allocate_ant_tab'
**     (t_ant *)data->ant_tab
*/

void	li_memory_liberator(t_data *data)
{
	(void)data;
}
