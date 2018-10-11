/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:44:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 17:04:49 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ps_push_swap(t_nb *stacks[2])
{
}

int		main(int argc, char **argv)
{
	t_nb	*stacks[2];
	t_nb	*sorted_refs[2];

	if (argc > 1)
	{
		ft_ps_parse_parameters(stacks, 0, argc, argv);
		*(sorted_refs + 0) = ft_ps_get_ref(*(stacks + 0), 0);
		if (ft_ps_check_doublons(*(sorted_refs + 0)) == 1)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		*(sorted_refs + 1) = ft_ps_get_ref(*(stacks + 0), 1);
		ft_ps_push_swap(stacks);
		ft_ps_free_stacks(stacks);
		ft_ps_free_stacks(sorted_refs);
	}
	return (0);
}
