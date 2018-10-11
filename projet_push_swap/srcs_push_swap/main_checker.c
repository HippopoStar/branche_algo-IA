/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:45:54 by lcabanes          #+#    #+#             */
/*   Updated: 2018/10/11 17:27:20 by lcabanes         ###   ########.fr       */
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

void	ft_ps_reach(t_list *lst, t_nb **stacks, int verbose_wit, size_t *occ)
{
	char	*command;

	if (lst == NULL)
	{
		*occ = 0;
	}
	else
	{
		command = (char *)(lst->content);
		ft_ps_reach(lst->next, stacks, verbose_wit, occ);
		ft_ps_apply_moves(stacks, command);
		free(command);
		(*occ)++;
	}
	if (verbose_wit)
	{
		ft_putnbr((int)(*occ));
		ft_putstr(".\n");
		ft_ps_display_stacks(stacks);
	}
}

int		ft_ps_checker(t_list *lst, t_nb **stacks, int verbose_wit, size_t *occ)
{
	int		ret_gnl;
	t_list	tmp;
	char	*line;

	ret_gnl = get_next_line(0, &line);
	if (ret_gnl == 1)
	{
		tmp.content = (void *)line;
		tmp.next = lst;
		return (ft_ps_checker(&tmp, stacks, verbose_wit, occ));
	}
	else if (ret_gnl == 0)
	{
		free(line);
		ft_ps_reach(lst, stacks, verbose_wit, occ);
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
	int		verbose_wit;
	size_t	occ;
	t_nb	*stacks[2];

	verbose_wit = (argc > 1 && !ft_strcmp(*(argv + 1), "-v")) ? 1 : 0;
	if (1 + verbose_wit < argc)
	{
		ft_ps_parse_parameters(stacks, verbose_wit, argc, argv);
		ft_ps_checker_programm_check_doublons(*(stacks + 0));
		occ = 0;
		(ft_ps_checker(NULL, stacks, verbose_wit, &occ) == 1) ?
			ft_putstr("OK\n") : ft_putstr("KO\n");
		ft_ps_free_stacks(stacks);
	}
	return (0);
}
