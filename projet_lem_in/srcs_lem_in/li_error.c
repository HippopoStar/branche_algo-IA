/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:08:16 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/17 19:16:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_help(void)
{
	ft_putstr("\033[32mHelp\033[00m:\n");
	li_usage();
	ft_putstr("\033[32mAvailable options\033[00m:\n");
	ft_putstr("-h\t: display help\n");
	ft_putstr("-c\t: enable colors\n");
	ft_putstr("-l\t: enable step counting\n");
	ft_putstr("-e\t: enable duplicates in connections declaration\n");
	ft_putstr("-d\t: disable duplicates in rooms' coordinates\n");
	ft_putstr("\033[32mComplexity\033[00m:\n");
	ft_putstr("O(nb_of_rooms * total_nb_of_tubes * max_simultaneous_paths)\n");
}

void	li_usage(void)
{
	ft_putstr("usage: [time] ./lem-in [-hcled] < my_map_file\n");
}

/*
** La fonction 'li_error' n'emploie pas 'ft_putstr' car elle ecrit sur
** la sortie d'erreur
** (On aurait pu employer 'ft_putstr_fd')
** On 'exit' pas a cause de 'valgring' qui est capricieux
** Note :
** On pourrait la prototyper en 'int' et la faire renvoyer systematiquement '0'
** afin de pouvoir l'employer de la maniere suivante :
** return (li_error());
** mais il ne faut pas ommettre de liberer la memoire anterieurement
*/

void	li_error(void)
{
	write(2, "ERROR\n", 6);
}
