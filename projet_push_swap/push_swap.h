#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_nb
{
	int				nb;
	struct s_nb		*next;
}					t_nb;

typedef struct		s_input
{
	char			inst[4];
	struct s_input	*next;
}					t_input;

typedef struct		s_ps
{
	int				verbose;
	t_nb			*stacks[2];
	size_t			length;
	int				*sorted;
}					t_ps;

/*
** Functions related to both PUSH_SWAP & CHECKER
*/
void				ps_display_error(void);
void				ps_display_stacks(t_nb *stacks[2]);
int					ps_parse(t_ps *data, int argc, char **argv);
int					ps_integer_format(t_ps *data, char **to_parse);
int					ps_zero_format(char *str);
int					ps_sort_wit(int *sorted, size_t length);
int					ps_init_stacks(t_ps *data, char **to_parse);
void				ft_push(t_nb *stacks[2], char c);
void				ft_swap(t_nb *stacks[2], char c);
void				ft_rotate(t_nb *stacks[2], char c);
void				ft_reverse_rotate(t_nb *stacks[2], char c);
int					ps_is_a_sorted(t_ps *data);
int					ps_is_b_sorted(t_ps *data);
int					ps_are_sorted(t_ps *data);
int					ps_is_ready_to_go(t_ps *data);
/*
** Functions related to PUSH_SWAP
*/
void				ft_push_swap(t_ps *data, int argc, char **argv);
void				ps_sort(t_ps *data);
void				ps_sort_bis(t_ps *data);
void				ps_print_and_apply(t_ps *data, char *command);
int					ps_gotta_push(t_nb *tmp, int pivot, char c);
/*
** Functions related to CHECKER
*/
int					ps_valid_input(char *line);
int					ps_get_input(t_input **input);
void				ps_apply_moves(t_nb *stacks[2], char *command);

#endif
