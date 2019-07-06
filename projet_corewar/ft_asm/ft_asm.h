/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:28:19 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/05 16:49:57 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASM_H
# define FT_ASM_H

# include <fcntl.h>
# include "op.h"
# include "libft.h"

# define FT_HEADER_LENGTH (4 + PROG_NAME_LENGTH + COMMENT_LENGTH)
# define FT_CHAMP_LENGTH (FT_HEADER_LENGTH + CHAMP_MAX_SIZE)

/*
** Dans 't_asm_data' :
** - (t_asm_data *)->output_file_name
*/

typedef struct	s_lab_ref
{
	char		*label_name;
	size_t		op_code_pos;
	size_t		ref_pos;
	struct s_lab_ref	*next;
}				t_lab_ref;

typedef struct	s_asm_inst
{
	char		op_code;
	char		checksum;
	size_t		op_code_pos;
}				t_asm_inst;

typedef struct	s_asm_data
{
	char		*input_file_name;
	char		*output_file_name;
	int			input_fd;
	int			output_fd;
	int			current_line_nb;
	char		output[FT_CHAMP_LENGTH];
	size_t		output_index;
	char		*label_tab[CHAMP_MAX_SIZE];
	t_lab_ref	*label_refs;
	t_asm_inst	*current_inst;
}				t_asm_data;

/*
** Dans le fichier 'main_asm.c'
*/
void	ft_asm(char *file_name);
/*
** Dans le fichier 'asm_open_input_file.c'
*/
int		asm_open_input_file(t_asm_data *data);
/*
** Dans le fichier 'asm_initialize_data.c'
** void	asm_initialise_data_label_tab(t_asm_data *data);
** void	asm_initialize_data_output(t_asm_data *data);
*/
void	asm_initialize_data(t_asm_data *data);
/*
** Dans le fichier 'asm_error_messages_01.c'
*/
int		asm_memory_allocation_fail(void);
int		asm_input_file_open_fail(t_asm_data *data);
int		asm_incorrect_input_file_name(t_asm_data *data);
void	asm_output_file_creation_fail(t_asm_data *data);
/*
** Dans le fichier 'asm_compile.c'
*/
int		asm_compile(t_asm_data *data);
/*
** Dans le fichier 'asm_write_output.c'
*/
void	asm_create_output_file(t_asm_data *data);
/*
** Dans le fichier 'asm_allocate_label_ref.c'
** static void	aux_asm_allocate_label_name(t_asm *data, char *label_name, t_lab_ref **node);
*/
int	asm_allocate_label_ref(t_asm_data *data, char *label_name);
/*
** Dans le fichier 'asm_liberate_memory.c'
** void	asm_liberate_label_refs(t_asm_data *data);
** void	asm_liberate_labels(t_asm_data *data);
*/
void	asm_liberate_memory(t_asm_data *data);

#endif
