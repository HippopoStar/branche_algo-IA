/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:59:04 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/25 21:33:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_of_digits(int n)
{
	size_t	compteur;

	compteur = 0;
	if (n == 0)
	{
		compteur = 1;
	}
	else if (n == -2147483648)
	{
		compteur = 11;
	}
	else if (n < 0)
	{
		compteur++;
		n = -n;
	}
	while (n > 0)
	{
		compteur++;
		n = n / 10;
	}
	return (compteur);
}

static void		aux_ft_itoa(int n, size_t length, char *chaine)
{
	size_t	i;

	if (n == 0)
	{
		*(chaine + 0) = '0';
	}
	else if (n == -2147483648)
	{
		ft_strcpy(chaine, "-2147483648");
	}
	else if (n < 0)
	{
		*(chaine + 0) = '-';
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		*(chaine + length - 1 - i) = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	*(chaine + length) = '\0';
}

char			*ft_itoa(int n)
{
	size_t	length;
	char	*chaine;

	length = nbr_of_digits(n);
	if (!(chaine = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	aux_ft_itoa(n, length, chaine);
	return (chaine);
}
