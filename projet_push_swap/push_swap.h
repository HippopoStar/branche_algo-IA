#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_nb
{
	int		n;
	struct s_nb	*next;
}			t_nb;

void			ft_ps_swap(t_nb **stacks, char c);
void			ft_ps_rotate(t_nb **stacks, char c);
void			ft_ps_push(t_nb **stacks, char c);
void			ft_ps_reverse_rotate(t_nb **stacks, char c);
void			ft_ps_display_stacks(t_nb **stacks);
int				ft_ps_stack_length(t_nb *stack);
void			ft_ps_initialize_stacks(t_nb ***stacks_adress);
void			ft_ps_add_elem(t_nb **stacks, char c, int nb);

#endif
