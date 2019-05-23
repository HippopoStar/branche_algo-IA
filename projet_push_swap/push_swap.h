/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:15:12 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/23 18:31:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct		s_reg
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_reg;

typedef struct		s_ps
{
	int				verbose;
	t_reg			reg;
	t_input			*input;
	t_input			*current_input;
	t_nb			*stacks[2];
	size_t			length;
	int				*sorted;
}					t_ps;

/*
** Functions related to both PUSH_SWAP & CHECKER -------------------------------
*/
/*
** Dans le fichier 'ps_display_error.c'
*/
void				ps_display_error(void);
/*
** Dans le fichier 'ps_display_stacks.c'
*/
void				ps_display_stacks(t_nb *stacks[2]);
/*
** Dans le fichier 'ps_parse.c'
*/
int					ps_parse(t_ps *data, int argc, char **argv);
int					ps_integer_format(t_ps *data, char **to_parse);
int					ps_zero_format(char *str);
int					ps_sort_wit(int *sorted, size_t length);
int					ps_init_stacks(t_ps *data, char **to_parse);
/*
** Dans le fichier 'ft_push.c'
*/
void				ft_push(t_nb *stacks[2], char c);
/*
** Dans le fichier 'ft_swap.c'
*/
void				ft_swap(t_nb *stacks[2], char c);
/*
** Dans le fichier 'ft_rotate.c'
*/
void				ft_rotate(t_nb *stacks[2], char c);
/*
** Dans le fichier 'ft_reverse_rotate.c'
*/
void				ft_reverse_rotate(t_nb *stacks[2], char c);
/*
** Dans le fichier 'ps_is_ready_to_go.c'
*/
int					ps_is_a_sorted(t_ps *data);
int					ps_is_b_sorted(t_ps *data);
int					ps_are_sorted(t_ps *data);
int					ps_is_ready_to_go(t_ps *data);
/*
** Functions related to PUSH_SWAP ----------------------------------------------
*/
/*
** Dans le fichier 'main_push_swap.c'
*/
void				ft_push_swap(t_ps *data, int argc, char **argv);
/*
** Dans le fichier 'ps_sort_three.c'
*/
void				ps_sort_three(t_ps *data);
/*
** Dans le fichier 'ps_sort_five.c'
*/
void				ps_sort_five(t_ps *data);
/*
** Dans le fichier 'ps_sort_power_two.c'
*/
void				ps_sort_power_two(t_ps *data);
/*
** Dans le fichier 'ps_position.c'
*/
size_t				ps_position(t_ps *data);
void				ps_swap_instructions(t_ps *data);
/*
** / ! \ Dans le fichier 'ps_apply_moves.c'
*/
void				ps_print_ando(t_ps *data, const char *command);
/*
** Dans le fichier 'ps_gotta_push.c'
*/
int					ps_gotta_push(t_nb *tmp, int pivot, char c);
/*
** Dans le fichier 'ps_shoten.c'
*/
void				ps_shorten(t_input **input);
void				ps_print_input(t_input **input);
/*
** Dans le fichier 'ps_aux_alamano_a.c'
*/
void				ps_aux_alamano_a(t_ps *data);
/*
** Dans le fichier 'ps_alamano_a.c'
*/
void				ps_alamano_a(t_ps *data);
/*
** Dans le fichier 'ps_aux_alamano_b.c'
*/
void				ps_aux_alamano_b(t_ps *data);
/*
** Dans le fichier 'ps_alamano_b.c'
*/
void				ps_alamano_b(t_ps *data);
/*
** Dans le fichier 'ps_sort_power_two_alamano.c'
*/
int					ps_get_a_four_lasts(t_ps *data, int *b, int *c, int *d);
void				ps_sort_power_two_alamano(t_ps *data);
/*
** Dans le fichier 'ps_do.c'
*/
void				ps_do(t_ps *data, const char *inst);
/*
** Functions related to CHECKER ------------------------------------------------
*/
/*
** Dans le fichier 'ps_get_input.c'
*/
int					ps_valid_input(char *line);
int					ps_get_input(t_input **input);
/*
** / ! \ Dans le fichier 'ps_apply_moves.c'
*/
void				ps_reg_m(t_nb *stacks[2], const char *command, t_reg *reg);
void				ps_apply_moves(t_nb *stacks[2], const char *command);
/*
** Dans le fichier 'ps_get_options.c'
*/
int					ps_get_options(int argc, char **argv, t_ps *data);
/*
** Dans le fichier 'ps_print_register.c'
*/
void				ps_print_register(t_reg *reg);

#endif
