#include "ft_asm.h"

void	asm_create_output_file(t_asm_data *data)
{
	if (!((data->output_fd = open(data->output_file_name, O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR)) == -1))
	{
		ft_putstr("Creating \"");
		ft_putstr(data->output_file_name);
		ft_putstr("\"\n");
		write(data->output_fd, data->output, FT_CHAMP_LENGTH);
	}
	else
	{
		asm_output_file_creation_fail(data);
	}
}
