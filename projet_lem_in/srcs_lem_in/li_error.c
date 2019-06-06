/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:08:16 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/26 11:03:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_usage(void)
{
	ft_putstr(USAGE_MSG);
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
