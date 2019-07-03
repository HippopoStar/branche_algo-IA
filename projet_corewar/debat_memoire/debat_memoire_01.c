/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debat_memoire_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:52:39 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/03 21:52:40 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

# define HEIGHT 10
# define WIDTH 100
# define X 5
# define Y 30
# define POS_X(x) (x % HEIGHT)
# define POS_Y(x) (x % WIDTH)

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_putchar(*(*(tab + i) + j));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_fill_tab(char **tab, size_t pos_x, size_t pos_y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			*(*(tab + i) + j) = '0';
			j++;
		}
		i++;
	}
	*(*(tab + pos_x) + pos_y) = '1';
}

int		ft_allocate_tab(char ***tab)
{
	size_t	i;

	if (!((*tab) = (char **)malloc(HEIGHT * sizeof(char *) + WIDTH * sizeof(char))))
		return (0);
	*((*tab) + 0) = (char *)((*tab) + HEIGHT);
	i = 1;
	while (i < HEIGHT)
	{
		*((*tab) + i) = *((*tab) + 0) + (i * WIDTH);
		i++;
	}
	return (1);
}

int		main(void)
{
	char	**tab;

	if (HEIGHT > 0 && WIDTH > 0 && ft_allocate_tab(&tab))
	{
		ft_fill_tab(tab, POS_X(X), POS_Y(Y));
		ft_print_tab(tab);
		free(tab);
	}
	return (0);
}
