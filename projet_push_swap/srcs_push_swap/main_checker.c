/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:45:54 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/19 11:45:12 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ft_ps_deliberate(t_nb **stacks)
{
	t_nb	*tmp;

	if (*(stacks + 0) != NULL && *(stacks + 1) == NULL)
	{
		tmp = *(stacks + 0);
		while (tmp->next != NULL && tmp->n <= (tmp->next)->n)
		{
			tmp = tmp->next;
		}
		if (tmp->next == NULL)
		{
			return (1);
		}
	}
	return (0);
}

void	ft_ps_reach(t_list *lst, t_nb **stacks)
{
	char	*command;

	if (lst != NULL)
	{
		command = (char *)(lst->content);
		ft_ps_reach(lst->next, stacks);
		ft_ps_apply_moves(stacks, command);
		free(command);
	}
}

int		ft_ps_checker(t_list *lst, t_nb **stacks)
{
	int		ret_gnl;
	t_list	tmp;
	char	*line;

	ret_gnl = get_next_line(0, &line);
	if (ret_gnl == 1)
	{
		tmp.content = (void *)line;
		tmp.next = lst;
		return (ft_ps_checker(&tmp, stacks));
	}
	else if (ret_gnl == 0)
	{
		free(line);
		ft_ps_reach(lst, stacks);
		return (ft_ps_deliberate(stacks));
	}
	else
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_nb	**stacks;

	ft_ps_initialize_stacks(&stacks);
	ft_ps_parse_parameters(stacks, argc, argv);
	ft_ps_display_stacks(stacks);
	(ft_ps_checker(NULL, stacks) == 1) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}
