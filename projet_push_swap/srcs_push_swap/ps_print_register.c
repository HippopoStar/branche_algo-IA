/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_register.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:42:26 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/21 11:48:08 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_register(t_reg *reg)
{
	ft_putstr("Nombre de :\n");
	ft_putstr("\t\"sa\": ");
	ft_putnbr(reg->sa);
	ft_putstr("\n\t\"sb\": ");
	ft_putnbr(reg->sb);
	ft_putstr("\n\t\"ss\": ");
	ft_putnbr(reg->ss);
	ft_putstr("\n\t\"pa\": ");
	ft_putnbr(reg->pa);
	ft_putstr("\n\t\"pb\": ");
	ft_putnbr(reg->pb);
	ft_putstr("\n\t\"ra\": ");
	ft_putnbr(reg->ra);
	ft_putstr("\n\t\"rb\": ");
	ft_putnbr(reg->rb);
	ft_putstr("\n\t\"rr\": ");
	ft_putnbr(reg->rr);
	ft_putstr("\n\t\"rra\": ");
	ft_putnbr(reg->rra);
	ft_putstr("\n\t\"rrb\": ");
	ft_putnbr(reg->rrb);
	ft_putstr("\n\t\"rrr\": ");
	ft_putnbr(reg->rrr);
	ft_putchar('\n');
}
