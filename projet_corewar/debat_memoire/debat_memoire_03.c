/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debat_memoire_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:52:50 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/03 22:32:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <inttypes.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

/*
** Le caractere d'espacement ' ' == (char)32 s'ecrit '00100000' en binaire
** Sachant cela, la chaine de caractere "  " s'ecrit '00100000 00100000 00000000'
** Par ailleurs, on a '00100000 0010000' = 8224
** et '00100000 00100000 00100000 00100000' = 538 976 288
*/

int		main(void)
{
	char		alphabet_01[26] = "abcdefghijklmnopqrstuvwxyz";
	char		*alphabet_02 = "abcdefghijklmnopqrstuvwxyz";
	char		*str = "    ";
	uint16_t	seize;
	uint32_t	trente_deux;

	printf("%c\n", *(alphabet_01 + 25));
	printf("%c\n", *(alphabet_01 + 26));
	*(alphabet_01 + 26) = '\0';
	*(alphabet_01 + 27) = '\0';
	*(alphabet_01 + 28) = '\0';
	*(alphabet_01 + 29) = '\0';
	*(alphabet_01 + 30) = '\0';
	*(alphabet_01 + 31) = '\0';
	*(alphabet_01 + 32) = '\0';
	*(alphabet_01 + 33) = '\0';
	*(alphabet_01 + 34) = '\0';
	*(alphabet_01 + 35) = '\0';
	*(alphabet_01 + 36) = '\0';
	*(alphabet_01 + 37) = '\0';
	*(alphabet_01 + 38) = '\0';
	*(alphabet_01 + 39) = '\0';
//	*(alphabet_01 + 40) = '\0';
	\
	printf("%d\n", ft_strlen(alphabet_01));
	printf("%d\n", ft_strlen(alphabet_02));
	\
	seize = *((uint16_t *)str);
	trente_deux = *((uint32_t *)str);
	printf("'seize' vaut : %hd\n", seize);
	printf("'trente_deux' vaut : %d\n", trente_deux);
	\
	seize = (uint16_t)(*str);
	trente_deux = (uint32_t)(*str);
	printf("'seize' vaut : %hd\n", seize);
	printf("'trente_deux' vaut : %d\n", trente_deux);
	return (0);
}
