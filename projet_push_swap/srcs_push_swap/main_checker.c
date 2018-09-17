/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:45:54 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/17 15:22:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_nb	**stacks;

	ft_ps_initialize_stacks(&stacks);
	ft_ps_parse(stacks, argc, argv);
	ft_ps_display_stacks(stacks);
	return(0);
}
