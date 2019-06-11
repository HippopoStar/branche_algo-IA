/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:02:14 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/11 20:42:33 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Schema de fonctionnement du programme :
** | li_options
**     | ft_options
**         | aux_ft_options
**             | ft_strchr (L)
**     | li_get_output (R)
**         | ft_strlen (L)
**         | li_print_output
** | li_help (O)
**     | ft_putstr (L)
**     | li_usage
**         |ft_putstr (L)
** | li_usage
**     | ft_putstr (L)
** | li_parse_input
**     | li_parse_ants
**         | li_get_next_non_comment_line (*)
**         | li_match_ants
**             | ft_is_int (L)
**             | free (S)
**     | li_parse_rooms
**         | li_allocate_room (*)
**         | li_get_next_non_comment_line (*)
**         | li_match_room
**             | li_deal_sharp_mark
**                 | ft_strcmp (L)
**                 | free (S)
**             | aux_li_match_room
**                 | ft_is_int (L)
**             | li_is_name_available
**                 | ft_strcmp (L)
**             | free (S)
**     | li_allocate_map (*)
**         | aux_li_allocate_map
**     | free (S)
**     | li_parse_pipes
**         | li_get_next_non_comment_line (*)
**         | li_match_pipe
**             | ft_strcmp (L)
**             | li_actualise_map
**         | free (S)
**     | li_shorten_map_pipes (*)
**         | li_fill_bond_summary
** | li_print_output
** | lem_in
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
**             | li_eval_meanwhile
**     | li_move_ants
**         | li_allocate_ant_tab (*)
**             | li_size_ttoa
**                 | li_color_ants (O)
**         | li_steps_length (O)
**         | li_prepare_steps_str (O)
**         | li_ants_distribution
**         | li_display_steps (O)
**         | aux_li_move_ants
**             | li_get_output (R)
**                 | ft_strlen (L)
**                 | li_print_output
**         | li_get_output (R)
**             | ft_strlen (L)
**             | li_print_output
** | li_memory_liberator
** | li_error
** | li_print_output
*/

int		lem_in(t_data *data)
{
	if (!li_bhandari(data)
		|| !li_build_routes(data))
	{
		return (0);
	}
	else
	{
		li_eval_routes(data);
		return (li_move_ants(data) ? 1 : 0);
	}
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		ret_val;

	data.rooms = NULL;
	data.map = NULL;
	data.max_paths = 0;
	data.paths = NULL;
	data.path_nb = 0;
	(data.output).index = 0;
	data.ant_tab = NULL;
	if (!(ret_val = (!li_options(&data, argc, argv) || data.help) ? 0 : 1))
		data.help ? li_help() : li_usage();
	else
	{
		ret_val = li_parse_input(&data);
		li_print_output(&data);
		if (!ret_val || !(ret_val = (!data.ants || lem_in(&data)) ? 1 : 0))
			li_error();
	}
	li_memory_liberator(&data);
	if (ret_val)
		li_print_output(&data);
	return (0);
}
