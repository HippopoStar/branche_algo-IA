/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:44:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/19 12:50:39 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_nb	**stacks;

	if (argc > 1)
	{
		ft_ps_initialize_stacks(&stacks);
		ft_ps_parse_parameters(stacks, argc, argv);
		ft_ps_push_swap(stacks);
	}
	return (0);
}
