/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:29:39 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/19 11:17:25 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	edit_size(int fd)
{
	unsigned int	size;

	size = 0;
	if (read(fd, &size, sizeof(int)) == -1)
		kill(1, "Oh dear, something went wrong with read()!");
	else if ((g_champ->size = ft_swap_uint32(size)) > CHAMP_MAX_SIZE)
		kill(0, "A champ' is wayyy to big.");
}

void	edit_name_comment(int fd, int len, char which)
{
	char	str[len + 1];

	ft_bzero(str, len + 1);
	if (read(fd, str, len) == -1)
		kill(1, "Oh dear, something went wrong with read()!");
	if (which)
		(g_champ->name = ft_strdup(str)) ? 0 :\
						kill(1, "Oh dear, something went wrong with malloc()!");
	else
		(g_champ->comment = ft_strdup(str)) ? 0 :\
						kill(1, "Oh dear, something went wrong with malloc()!");
}

char	count_until_first_unset_bit(char option)
{
	static char	opt[5] = {5, 1, 2, 4, 8};
	static char	set_bits = 0;
	int			count;

	option |= set_bits;
	count = 1;
	while (option)
	{
		if (!(option & 1))
			break ;
		count++;
		option >>= 1;
	}
	set_bits |= opt[count];
	return (count);
}

void	edit_token(void)
{
	g_champ = *g_champ->start;
	while (g_champ->next)
	{
		if (g_champ->token == g_env.force_token)
		{
			g_champ->token = count_until_first_unset_bit(g_env.option >> 4);
			g_champ->id = g_champ->token;
			g_champ->r[0] = (unsigned int)(-g_champ->token);
		}
		g_champ = g_champ->next;
	}
	if (g_env.force_token)
	{
		g_champ->token = g_env.force_token;
		g_env.force_token = 0;
	}
	else
		g_champ->token = count_until_first_unset_bit(g_env.option >> 4);
	g_champ->id = g_champ->token;
	g_champ->r[0] = (unsigned int)(-g_champ->token);
}

void	add_champion(void)
{
	t_champ	*tmp;

	tmp = NULL;
	if (!g_champ)
	{
		g_champ = init_champ(0);
		*g_champ->start = g_champ;
	}
	else
	{
		tmp = g_champ;
		g_champ->next = init_champ(1);
		g_champ = g_champ->next;
	}
	if (tmp)
	{
		g_champ->n = tmp->n;
		g_champ->start = tmp->start;
		g_champ->last = tmp->last;
	}
	(*g_champ->n)++;
	*g_champ->last = g_champ;
	edit_token();
}
