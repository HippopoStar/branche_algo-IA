#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_ps
{
	int	verbose;
	size_t	length;
	size_t	a_start;
	size_t	a_end;
	size_t	b_start;
	size_t	b_end;
	int	*a;
	int	*b;
	int	*sorted;
}		t_ps;

/*
** Functions related to PUSH_SWAP & CHECKER
*/
void	ps_display_error(void);
int	ps_parse(t_ps *data, int argc, char **argv);
int	ps_integer_format(t_ps *data, char **to_parse);
int	ps_zero_format(char *str);
int	ps_sort_wit(int *sorted, size_t length);
int	ps_init_stacks(t_ps *data, char **to_parse);
void	ps_swap(t_ps *data, char c);
/*
** Functions related to PUSH_SWAP
*/
void	ft_push_swap(t_ps *data, int argc, char **argv);
void	ps_sort(t_ps *data);
/*
** Functions related to CHECKER
*/

#endif
