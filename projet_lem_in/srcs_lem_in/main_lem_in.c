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
	data.input = NULL;
	data.read = NULL;
	if (!li_get_input(&(data.input)))
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
	return (0);
}
