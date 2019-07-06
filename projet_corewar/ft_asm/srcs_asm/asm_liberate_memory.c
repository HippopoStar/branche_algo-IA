#include "ft_asm.h"

static void	asm_liberate_label_refs(t_asm_data *data)
{
	t_lab_ref	*to_free;

	while (!(data->label_refs == NULL))
	{
		to_free = data->label_refs;
		data->label_refs = (data->label_refs)->next;
		if (!(to_free->label_name == NULL))
		{
			free(to_free->label_name);
		}
		free(to_free);
	}
}

static void	asm_liberate_labels(t_asm_data *data)
{
	size_t	i;

	i = 0;
	while (i < CHAMP_MAX_SIZE)
	{
		if (!(*(data->label_tab + i) == NULL))
		{
			free(*(data->label_tab + i));
		}
		i++;
	}
}

void		asm_liberate_memory(t_asm_data *data)
{
	if (!(data->output_file_name == NULL))
	{
		free(data->output_file_name);
	}
	if (!(data->input_fd == -1))
	{
		close(data->input_fd);
	}
	if (!(data->output_fd == -1))
	{
		close(data->output_fd);
	}
	asm_liberate_labels(data);
	asm_liberate_label_refs(data);
}
