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
/*
** Functions related to PUSH_SWAP
*/
void				ft_push_swap(t_ps *data, int argc, char **argv);
void				ps_sort(t_ps *data);
/*
** Functions related to CHECKER
*/

#endif
