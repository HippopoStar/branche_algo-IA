/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:02:14 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/05 20:44:09 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Shema de fonctionnement du programme :
** lem_in
**     | li_get_input (*)
**         | get_next_line_backslash_zero (L*)
**         | li_get_output
**         | li_print_output
**     | li_parse_input
**         | li_match_ants
**             | ft_is_int
**                 | ft_is_digit (L)
**                 | ft_atoi (L)
**         | li_match_rooms
**             | li_allocate_room (*)
**             | li_deal_sharp_marks
**                 | ft_strcmp (L)
**             | li_match_room
**                 | ft_is_int
**                     | ft_is_digit (L)
**                     | ft_atoi (L)
**         | li_allocate_map (*)
**             | aux_li_allocate_map
**         | li_match_pipes
**             | li_match_pipe
**                 | ft_strcmp (L)
**         | li_shorten_map_pipes (*)
**             | li_fill_bond_summary
**     | li_bhandari
**         | li_bhandari_max_iteration
**         | li_allocate_paths (*)
**         | li_initialise_weights
**         | li_bellman_ford
**             | aux_li_bellman_ford
**         | li_reverse_path
**     | li_build_routes
**         | li_allocate_routes (*)
**             | aux_li_allocate_routes
**         | li_copy_previous_route
**         | li_copy_last_path
**         | li_remove_edges
**             | li_melt_paths
**                 | li_edge_len
**             | li_swap_paths
**         | li_order_paths
**     | li_eval_routes
**         | li_eval_steps
**             | li_eval_meanwhile
**     | li_move_ants
**         | li_allocate_ant_tab (*)
**             | li_size_ttoa
**                 | li_color_ants
**         | li_ants_distribution
**         | aux_li_move_ants
**             | li_get_output
**         | li_get_output
**     | li_memory_liberator
**     | li_print_output
*/

int		main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.rooms = NULL;
	data.map = NULL;
	data.max_paths = 0;
	data.paths = NULL;
	data.path_nb = 0;
	data.input = NULL;
	data.read = NULL;
	(data.output).index = 0;
	data.ant_tab = NULL;
	data.color = 1;
	if (!li_get_input(&data, &(data.input)))
	{
		li_error();
	}
	ft_putstr("\"li_get_input\" OK !\n");
	/*else*/ if (!li_parse_input(&data))
	{
		li_error();
	}
	ft_putstr("\"li_parse_input\" OK !\n");
	/*else*/
//	{
//		li_print_map(&data);
//	}
	if (li_bhandari(&data))
	{
		li_print_paths(&data);
		ft_putstr("\"data->path_nb\" vaut ");
		ft_putnbr((int)data.path_nb);
		ft_putchar('\n');
	}
	if (!li_build_routes(&data))
	{
		li_error();
	}
	li_eval_routes(&data);
	li_print_routes(&data);
	if (!li_move_ants(&data))
	{
		li_error();
	}
	li_memory_liberator(&data);
	li_print_output(&data);
	ft_putstr("data.ants : ");
	ft_putnbr((int)data.ants);
	ft_putchar('\n');
	ft_putstr("data.best_route : ");
	ft_putnbr((int)data.best_route);
	ft_putchar('\n');
	ft_putstr("data.best_steps : ");
	ft_putnbr((int)data.best_steps);
	ft_putchar('\n');
	return (0);
}
