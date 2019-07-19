/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:28:19 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/19 14:11:43 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASM_H
# define FT_ASM_H

# include <fcntl.h>
# include "op.h"
# include "libft.h"
# include "get_next_line_backslash_zero.h"

# define FT_HEADER_LENGTH (4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4)
# define FT_MAX_CHAMP_LENGTH (FT_HEADER_LENGTH + CHAMP_MAX_SIZE)

/*
** 2 methodes pour liberer la memoire associee a un file descriptor
** (still reachable) :
** - lire le fichier jusqu'a ce que 'get_next_line' renvoie '0'
** - fermer le fichier, appeler 'get_next_line' qui liberera
**   le maillon renverra '-1'
**   / ! \ Attention tout de meme a ne pas se retrouve face a une boucle inf'
**         dans 'asm_gn_pertinent_l' dans le cas de /dev/zero
**
** Dans 'asm_get_label_declaration', on pourrait relever la ligne complete
** en cas d'erreur dans une instruction placee sur la meme ligne
** qu'une declaration de label, grace a (char)*(line + (*i) + j) = LABEL_CHAR
**
** Bonus :
** Faire un convertisseur de chaines de caracteres en instructions 'aff'
**
** Note :
** Si on interrompt l'execution du programme avec 'CTRL + C',
** notamment lors d'une utilisation conjointe avec Valgrind,
** le fichier source <my_champ.s> est supprime O_O
**
** Dans 't_asm_data' :
** - (t_asm_data *)->output_file_name
**
** Dans 'asm_compile.c', sont declarees :
** (char *)line
** (t_header)h;
** (char *)prog;
**
** Dans 'asm_parse_prog.c', sont declarees :
** (t_asm_inst)inst;
** (size_t)pos;
**
**
** OBSOLETE:
** (t_lab_ref *)data->current_label_ref :
** Initialisation a NULL dans 'asm_parse_instruction'
** MaJ dans 'asm_allocate_label_ref'
**
** (size_t)(data->current_label_ref)->size :
** Initialisation dans 'asm_put_inst_prog' (a faire)
**
** (int)((data->current_inst)->arg + i)->is_lab_ref :
** Initialisation a 0 dans 'asm_parse_instruction'
** MaJ a 1 dans 'asm_parse_arg_label'
*/

typedef struct			s_lab_dec
{
	char				*label_name;
	struct s_lab_dec	*next;
}						t_lab_dec;

typedef struct			s_lab_ref
{
	char				*label_name;
	size_t				op_code_pos;
	size_t				ref_pos;
	size_t				size;
	struct s_lab_ref	*next;
}						t_lab_ref;

typedef struct			s_asm_arg
{
	char				check;
	size_t				size;
	unsigned int		value;
}						t_asm_arg;

/*
** Voir fichier 'asm_parse_prog.c'
**	char		*prog;
**	size_t		*pos;
*/

typedef struct			s_asm_inst
{
	char				*prog;
	char				op_code;
	size_t				op_code_pos;
	size_t				nb_of_args;
	char				checksum;
	t_asm_arg			arg[3];
}						t_asm_inst;

typedef struct			s_asm_data
{
	size_t				total_size;
	char				*input_file_name;
	char				*output_file_name;
	int					input_fd;
	int					output_fd;
	char				*current_line;
	int					current_line_nb;
	char				output[FT_MAX_CHAMP_LENGTH];
	size_t				output_index;
	t_lab_dec			*label_tab[CHAMP_MAX_SIZE];
	t_lab_ref			*label_refs;
	t_asm_inst			*current_inst;
}						t_asm_data;

/*
** La taille en octets des directs : voir 'asm_parse_arg_types_01.c'
** Les references aux labels : voir 'asm_parse_arg_types_02.c'
** La correspondances des parametres : voir 'asm_check_inst_args.c'
** Ecriture des instructions : voir 'asm_put_inst_prog.c'
** Remplacement des references a des labels : voir 'asm_parse_prog.c'
*/

/*
** Arborescence du programme :
** | ft_asm
**     | asm_initialise_data
**     | asm_open_input_file
**     | asm_compile
**         | asm_parse_header
**         | asm_parse_prog
**             | asm_parse_line
**                 | asm_gn_pertinent_l
**                     | asm_skip_spacing_chars
**                 | asm_get_label_declaration
**                     | asm_skip_spacing_chars
**                 | asm_parse_instruction
**                     | asm_get_inst_op_code
**                     | asm_parse_inst_arg
**                         | asm_inst_arg_type_register
**                         | asm parse_arg_register
**                         | asm_inst_arg_type_direct
**                         | asm_parse_arg_direct
**                             | asm_parse_arg_direct_size
**                         | asm_inst_arg_type_indirect
**                         | asm_parse_arg_indirect
**                         | asm_inst_arg_type_label
**                         | asm_parse_arg_label
**                             | asm_parse_arg_direct_size
**                         | asm_skip_spacing_chars
**                     | asm_check_inst_args
**                     | asm_put_inst_prog
**         | asm_put_header_output
**         | asm_put_prog_output
**     | asm_create_output_file
**     | asm_liberate_memory
*/

/*
** Dans le fichier 'main_asm.c'
*/
void					ft_asm(char *file_name);
/*
** Dans le fichier 'asm_open_input_file.c'
*/
int						asm_open_input_file(t_asm_data *data);
/*
** Dans le fichier 'asm_initialize_data.c'
** void	asm_initialise_data_label_tab(t_asm_data *data);
** void	asm_initialize_data_output(t_asm_data *data);
*/
void					asm_initialize_data(t_asm_data *data);
/*
** Dans le fichier 'asm_error_messages_01.c'
*/
void					asm_put_error(void);
void					asm_error_message_reading_stopped(t_asm_data *data);
/*
** Dans le fichier 'asm_error_messages_02.c'
*/
int						asm_memory_allocation_fail(void);
int						asm_input_file_open_fail(t_asm_data *data);
int						asm_incorrect_input_file_name(t_asm_data *data);
void					asm_output_file_creation_fail(t_asm_data *data);
/*
** Dans le fichier 'asm_error_messages_03.c'
*/
int						asm_failed_to_get_prog_name(t_asm_data *data);
int						asm_failed_to_get_comment(t_asm_data *data);
int						asm_syntax_error(t_asm_data *data);
/*
** Dans le fichier 'asm_error_messages_04.c'
*/
int						asm_inexisting_label_reference(char *label_name);
/*
** Dans le fichier 'asm_error_messages_05.c'
*/
int						asm_name_does_not_fit(void);
int						asm_comment_does_not_fit(void);
int						asm_program_does_not_fit(void);
/*
** Dans le fichier 'asm_warning_messages.c'
** static void	asm_put_warning(void);
*/
int						asm_two_labels_in_a_row(t_asm_data *data);
int						asm_label_name_already_exists(char *label_name);
/*
** Dans le fichier 'asm_compile.c'
** static void	asm_liberate_gnl_node(int fd, char **line);
*/
int						asm_compile(t_asm_data *data);
/*
** Dans le fichier 'asm_write_output.c'
*/
void					asm_create_output_file(t_asm_data *data);
/*
** Dans le fichier 'asm_allocate_label_ref.c'
** static void	aux_asm_allocate_label_name(t_lab_ref **node, char *label_name);
*/
int						asm_allocate_label_ref(t_asm_data *data,\
									char *label_name, size_t pos, size_t size);
/*
** Dans le fichier 'asm_liberate_memory.c'
** void	asm_liberate_label_refs(t_asm_data *data);
** void	asm_liberate_labels(t_asm_data *data);
*/
void					asm_liberate_memory(t_asm_data *data);
/*
** Dans le fichier 'asm_putchar_output.c'
*/
int						asm_putchar_output(t_asm_data *data, char c);
int						asm_putusint_output(t_asm_data *data,\
														unsigned short int s);
int						asm_putuint_output(t_asm_data *data, unsigned int s);
/*
** Dans le fichier 'asm_putchar_prog.c'
*/
int						asm_putchar_prog(char *prog, size_t *pos, char c);
int						asm_putusint_prog(char *prog, size_t *pos,\
														unsigned short int s);
int						asm_putuint_prog(char *prog, size_t *pos,\
																unsigned int u);
/*
** Dans le fichier 'asm_put_header_output.c'
** static int	asm_put_magic_output(t_asm_data *data, t_header *h);
** static int	asm_put_name_output(t_asm_data *data, t_header *h);
** static int	asm_put_prog_size_output(t_asm_data *data, t_header *h);
** static int	asm_put_comment_output(t_asm_data *data, t_header *h);
*/
int						asm_put_header_output(t_asm_data *data, t_header *h);
/*
** Dans le fichier 'asm_parse_header.c'
** static void	asm_initialize_header_struc(t_header *h);
** static int	asm_parse_name(t_asm_data *data, t_header *h, char **line);
** static int	asm_parse_comment(t_asm_data *data, t_header *h, char **line);
*/
int						asm_parse_header(t_asm_data *data, t_header *h,\
																char **line);
/*
** Dans le fichier 'asm_get_quote.c'
** static int	aux_asm_get_quote(t_asm_data *data, size_t *i, char *to_fill,\
**																size_t size);
*/
int						asm_get_quote(t_asm_data *data, size_t i,\
													char *to_fill, size_t size);
/*
** Dans le fichier 'asm_parse_prog.c'
** static size_t	asm_match_label(t_asm_data *data, t_lab_ref *label_ref);
** static int	aux_asm_check_labels(t_asm_data *data, t_lab_ref *label_ref,\
**																	char *prog);
** static int	asm_check_labels(t_asm_data *data, char *prog);
*/
int						asm_parse_prog(t_asm_data *data, t_header *h,\
													char **line, char *prog);
/*
** Dans le fichier 'asm_parse_line.c'
*/
int						asm_parse_line(t_asm_data *data, char **line,\
																size_t *pos);
/*
** Dans le fichier 'asm_get_label_declaration.c'
** static int	asm_allocate_lab_dec(t_asm_data *data, char *label_name,\
**																	size_t pos);
** static int	aux_asm_label_declaration_available(t_asm_data *data, size_t i,\
**															char *label_name);
** static int	asm_label_declaration_available(t_asm_data *data,\
**												char *label_name, size_t pos);
*/
int						asm_get_label_declaration(t_asm_data *data, char *line,\
														size_t *i, size_t pos);
/*
** Dans le fichier 'asm_parse_instruction.c'
*/
int						asm_parse_instruction(t_asm_data *data, char *line,\
														size_t i, size_t *pos);
/*
** Dans le fichier 'asm_parse_inst_arg.c'
** static int		asm_inst_arg_fits(t_asm_inst *inst, char *line, size_t *i,\
**																size_t arg_nb);
*/
int						asm_parse_inst_arg(t_asm_data *data, char *line,\
													size_t *i, size_t arg_nb);
/*
** Dans le fichier 'asm_get_inst_op_code.c'
** static char	asm_op_code_one(t_asm_inst *inst, char *line, size_t *i);
** static char	asm_op_code_two(t_asm_inst *inst, char *line, size_t *i);
** static char	asm_op_code_three(t_asm_inst *inst, char *line, size_t *i);
** static char	asm_op_code_four(t_asm_inst *inst, char *line, size_t *i);
*/
int						asm_get_inst_op_code(t_asm_inst *inst, char *line,\
																	size_t *i);
/*
** Dans le fichier 'asm_inst_arg_types.c'
*/
int						asm_inst_arg_type_register(char *line, size_t *i);
int						asm_inst_arg_type_direct(char *line, size_t *i);
int						asm_inst_arg_type_indirect(char *line, size_t *i);
int						asm_inst_arg_type_label(char *line, size_t *i);
/*
** Dans le fichier 'asm_parse_arg_types_01.c'
** static size_t	asm_parse_arg_direct_size(t_asm_data *data);
*/
int						asm_parse_arg_register(t_asm_data *data, char *line,\
													size_t *i, size_t arg_nb);
size_t					asm_parse_arg_direct_size(t_asm_data *data);
int						asm_parse_arg_direct(t_asm_data *data, char *line,\
													size_t *i, size_t arg_nb);
int						asm_parse_arg_indirect(t_asm_data *data, char *line,\
													size_t *i, size_t arg_nb);
/*
** Dans le fichier 'asm_parse_arg_types_02.c'
** static void		asm_parse_arg_label_get_type(t_asm_data *data, char *line,\
**													size_t *i, size_t arg_nb);
** static size_t	asm_parse_arg_label_get_ref(t_asm_data *data,\
**																size_t arg_nb);
*/
int						asm_parse_arg_label(t_asm_data *data, char *line,\
													size_t *i, size_t arg_nb);
/*
** Dans le fichier 'asm_check_inst_args.c'
** static int	asm_check_register(char op_code, size_t i);
** static int	asm_check_direct(char op_code, size_t i);
** static int	asm_check_indirect(char op_code, size_t i);
*/
int						asm_check_inst_args(t_asm_inst *inst);
/*
** Dans le fichier 'asm_put_inst_prog.c'
** static int	asm_put_checksum_prog(t_asm_inst *inst, size_t *pos);
** static int	asm_put_op_code_checksum_prog(t_asm_inst *inst, size_t *pos);
** static int	asm_put_arg_prog(t_asm_arg *arg, char *prog, size_t *pos);
*/
int						asm_put_inst_prog(t_asm_inst *inst, size_t *pos);
/*
** Dans le fichier 'asm_put_prog_output.c'
*/
int						asm_put_prog_output(t_asm_data *data, t_header *h,\
																	char *prog);
/*
** Dans le fichier 'asm_skip_spacing_chars.c'
*/
void					asm_skip_spacing_chars(char *line, size_t *i);
/*
** Dans le fichier 'asm_gnl.c'
** static int	asm_gnl(t_asm_data *data, char **line);
** static int	aux_asm_gn_pertinent_l(t_asm_data *data, char **line,\
**																	size_t *i);
*/
int						asm_gn_pertinent_l(t_asm_data *data, char **line,\
																	size_t *i);
/*
** Dans le fichier 'asm_ft_atoi.c'
*/
int						asm_ft_atoi(const char *str);

#endif
