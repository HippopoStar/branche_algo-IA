#include "ft_asm.h"

int		asm_parse_arg_register(t_asm_data *data, char *line, size_t *i, size_t arg_nb)
{
	unsigned int	u;

	u = (unsigned int)ft_atoi(line);
	((data->current_inst)->arg + arg_nb)->check = (char)1;
	((data->current_inst)->arg + arg_nb)->size = 1;
	if (u < 17)
	{
		((data->current_inst)->arg + arg_nb)->value = u;
	}
	else
	{
		return (0);
	}
	while (ft_isdigit(*(line + (*i))))
	{
		(*i)++;
	}
	return (1);
}

static size_t	asm_parse_arg_direct_size(t_asm_data *data)
{
	if ((data->current_inst)->op_code == 9
			|| (data->current_inst)->op_code == 10
			|| (data->current_inst)->op_code == 11
			|| (data->current_inst)->op_code == 12
			|| (data->current_inst)->op_code == 14
			|| (data->current_inst)->op_code == 15)
	{
		return (2);
	}
	else
	{
		return (4);
	}
}

int		asm_parse_arg_direct(t_asm_data *data, char *line, size_t *i, size_t arg_nb)
{
	unsigned int	u;

	u = (unsigned int)ft_atoi(line);
	((data->current_inst)->arg + arg_nb)->check = (char)2;
	((data->current_inst)->arg + arg_nb)->size = asm_parse_arg_direct_size(data);
	((data->current_inst)->arg + arg_nb)->value = u;
	if (*(line + (*i)) == '+' || *(line + (*i)) == '-')
	{
		(*i)++;
	}
	while (ft_isdigit(*(line + (*i))))
	{
		(*i)++;
	}
	return (1);
}

int		asm_parse_arg_indirect(t_asm_data *data, char *line, size_t *i, size_t arg_nb)
{
	unsigned int	u;

	u = (unsigned int)ft_atoi(line);
	((data->current_inst)->arg + arg_nb)->check = (char)3;
	((data->current_inst)->arg + arg_nb)->size = 2;
	((data->current_inst)->arg + arg_nb)->value = u;
	if (*(line + (*i)) == '+' || *(line + (*i)) == '-')
	{
		(*i)++;
	}
	while (ft_isdigit(*(line + (*i))))
	{
		(*i)++;
	}
	return (1);
}

static size_t	asm_parse_arg_label_get_ref_pos(t_asm_data *data, size_t arg_nb)
{
	size_t	k;
	size_t	ref_pos;

	ref_pos = (data->current_inst)->op_code_pos;
	ref_pos = ref_pos + 1 + (size_t)(data->current_inst)->checksum;
	k = 0;
	while (k < arg_nb)
	{
		ref_pos = ref_pos + ((data->current_inst)->arg + k)->size;
		k++;
	}
	return (ref_pos);
}

/*
**	ft_putstr("Avant 'asm_parse_arg_label' : ");
**	ft_putstr(&(*(line + (*i))));
**	ft_putchar('\n');
**		ft_putstr("Dans 'ft_strchr' : ");
**		ft_putchar(*(line + (*i) + j));
**		ft_putchar('\n');
**		ft_putstr("Apres 'asm_parse_arg_label' : ");
**		ft_putstr(&(*(line + (*i))));
**		ft_putchar('\n');
*/

int		asm_parse_arg_label(t_asm_data *data, char *line, size_t *i, size_t arg_nb)
{
	size_t	j;
	char	c;
	size_t	ref_pos;

	((data->current_inst)->arg + arg_nb)->check = (char)2;
	((data->current_inst)->arg + arg_nb)->size = 2;
	j = 0;
	while (ft_strchr(LABEL_CHARS, (int)*(line + (*i) + j)))
	{
		j++;
	}
	c = *(line + (*i) + j);
	*(line + (*i) + j) = '\0';
	ref_pos = asm_parse_arg_label_get_ref_pos(data, arg_nb);
	if (asm_allocate_label_ref(data, &(*(line + (*i))), ref_pos))
	{
		*(line + (*i) + j) = c;
		*i = (*i) + j;
		return (1);
	}
	else
	{
		return (0);
	}
}
