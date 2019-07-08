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

	data.input_file_name = file_name;
	asm_initialize_data(&data);
	if (asm_open_input_file(&data))
	{
		if (asm_compile(&data))
		{
			asm_create_output_file(&data);
		}
	}
	asm_liberate_memory(&data);
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
	else
	{
		ft_putstr("usage: ./asm <my_champ.s>\n");
	}
	return (0);
}
