/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:20:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 23:10:34 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_magic(int fd)
{
	unsigned int	magic;

	magic = 0;
	if (read(fd, &magic, sizeof(int)) == -1)
		kill(1, "Oh dear, something went wrong with read()!");
	else if (ft_swap_uint32(magic) != COREWAR_EXEC_MAGIC)
		kill(0, "Someone has a bad magic number boy...");
}

void	open_input(char *champion)
{
	int	fd;

	if ((fd = open(champion, O_RDONLY)) == -1)
		kill(1, "Oh snap, something went wrong with open()!");
	else
	{
		check_magic(fd);
		add_champion();
		edit_name_comment(fd, PROG_NAME_LENGTH, 1);
		lseek(fd, 8 + PROG_NAME_LENGTH, SEEK_SET);
		edit_size(fd);
		edit_name_comment(fd, COMMENT_LENGTH, 0);
		lseek(fd, 4, SEEK_CUR);
		init_process(fd);
	}
	close(fd);
}

void	options(int nbr)
{
	static int	opt[5] = {1337, OPT_1, OPT_2, OPT_3, OPT_4};

	if (g_env.option & OPT_N)
	{
		if (nbr <= 0 || nbr > MAX_PLAYERS)
			kill(0, "Misuse of -n, the following value must be between "\
					"1 and the number of champions declared.");
		else if (g_env.option & opt[nbr])
			kill(0, "You can't set twice the same position for a champ'...");
		else
			g_env.option |= opt[nbr];
		g_env.option &= ~OPT_N;
		g_env.force_token = nbr;
	}
	else if (g_env.option | OPT_DUMP && g_env.cycle_to_dump == -1)
		g_env.cycle_to_dump = nbr;
	else
		kill(0, "Bad input bro, see --help for futher informations.");
}

void	check_input(char *str, char next_is_int)
{
	if (IS_DUMP(str) && next_is_int && !g_env.force_token)
		g_env.option |= OPT_DUMP;
	else if (IS_N(str) && next_is_int && !g_env.force_token)
		g_env.option |= OPT_N;
	else if (IS_V(str) && !g_env.force_token && !next_is_int)
		g_env.option |= OPT_V;
	else if (IS_C(str) && !g_env.force_token && !next_is_int)
		g_env.option |= OPT_C;
	else if (IS_HELP(str) && !g_env.force_token && !next_is_int)
		kill(0, 0);
	else if (ft_str_is_numeric(str))
		options(ft_atoi(str));
	else if (IS_CHAMP(str))
		open_input(str);
	else
		kill(0, "Bad input bro, see --help for futher informations.");
}
