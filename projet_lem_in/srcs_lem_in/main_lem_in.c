/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:02:14 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/22 10:04:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	{
		li_print_map(&data);
	}
	if (li_bhandari(&data))
	{
		li_print_paths(&data);
	}
	return (0);
}
