/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:23:50 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/05 16:07:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

void	ft_asm(char *file_name)
{
	t_asm_data	data;

	data->input_file_name = file_name;
	if (asm_open_file(&data))
	{
		asm_initialize_data(&data);
		close(data->input_fd);
	}
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			ft_asm(*(argv + i));
			i++;
		}
	}
	return (0);
}
