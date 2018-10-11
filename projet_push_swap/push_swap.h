#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_nb
{
	int				n;
	struct s_nb		*next;
}					t_nb;

void			ft_ps_swap(t_nb *stacks[2], char c);
void			ft_ps_rotate(t_nb *stacks[2], char c);
void			ft_ps_push(t_nb *stacks[2], char c);
void			ft_ps_reverse_rotate(t_nb *stacks[2], char c);
void			ft_ps_display_stacks(t_nb *stacks[2]);
int				ft_ps_stack_length(t_nb *stack);
void			ft_ps_initialize_stacks(t_nb ***stacks_adress);
void			ft_ps_add_elem(t_nb *stacks[2], char c, int nb);
void			ft_ps_parse_parameters(t_nb *stacks[2], int opt, int argc, char **argv);
void			ft_ps_apply_moves(t_nb *stacks[2], char *command);
void			ft_ps_rev_sort_ref(t_nb *lst_copy);
void			ft_ps_sort_ref(t_nb *lst_copy);
t_nb			*ft_ps_copy_lst(t_nb *lst);
t_nb			*ft_ps_get_refs(t_nb *init_lst, int instruction);
int				ft_ps_check_doublons(t_nb *sorted_lst);
void			ft_ps_checker_programm_check_doublons(t_nb *stack_a);
int				ft_ps_check_order(t_nb *stacks[2], t_nb *sorted_refs[2], char c);
void			ft_ps_free_lst(t_nb *lst);
void			ft_ps_free_stacks(t_nb *stacks[2]);

#endif
