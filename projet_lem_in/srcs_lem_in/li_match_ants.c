#include "lem_in.h"

int		li_match_ants(t_input **read, t_data *data)
{
	size_t	i;
	int		wit;

	while (*read)
	{
		if (*((*read)->line + 0) == '#')
		{
			(*read) = (*read)->next;
		}
		else
		{
			i = 0;
			wit = ((ft_is_int((*read)->line, &i, &(data->ants)) && data->ants > 0
					&& *((*read)->line + i) == '\0') ? 1 : 0);
			*read = (*read)->next;
			return (wit);
		}
	}
	return (0);
}
