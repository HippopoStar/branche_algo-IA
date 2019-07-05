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

# include OP_H

# define FT_HEADER_LENGTH (4 + PROG_NAME_LENGTH + COMMENT_LENGTH)
# define FT_CHAMP_LENGTH (FT_HEADER_LENGTH + CHAMP_MAX_SIZE)

/*
** Dans 't_asm_data' :
** - (t_asm_data *)->output_file_name
*/

typedef struct	s_asm_instruction
{
	char		op_code;
	char		checksum;
}				t_asm_instruction;

typedef struct	s_asm_data
{
	char		*input_file_name;
	char		*output_file_name;
	int			input_fd;
	int			output_fd;
	char		output[ASM_CHAMP_LENGTH + 1];
	size_t		output_index;
	char		*label_tab[CHAMP_MAX_SIZE];
}				t_asm_data;

/*
** Dans le fichier 'main_asm.c'
*/
void	ft_asm(char *file_name);
/*
** Dans le fichier 'asm_open_input_file.c'
*/
int		asm_open_input_file(t_asm_data *data)
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

#endif
