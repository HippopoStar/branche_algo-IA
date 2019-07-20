/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:29:48 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/04 18:56:46 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	ft_strlowcase(str);
	if (ft_islower(str[i]))
		str[i] -= 32;
	while (str[i])
	{
		if (((str[i] >= 0 && str[i] <= '/')
			|| (str[i] >= ':' && str[i] <= '@')
				|| (str[i] >= '[' && str[i] <= '`')
					|| (str[i] >= '{' && str[i] <= '~'))
						&& ft_islower(str[i + 1]))
			str[i + 1] -= 32;
		i++;
	}
	return (str);
}
