#include "lem_in.h"

int		li_allocate_room(t_room **room)
{
	if (!(*room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	(*room)->name = NULL;
	(*room)->role = 1;
	(*room)->pipes = NULL;
	(*room)->next = NULL;
	return (1);
}

int		li_deal_sharp_marks(t_room *room, t_input **read)
{
	if (!ft_strcmp((*read)->line, "##start"))
	{
		if (room->role == 1)
		{
			room->role = 2;
		}
		else
		{
			return (0);
		}
	}
	else if (!ft_strcmp((*read)->line, "##end"))
	{
		if (room->role == 1)
		{
			room->role = 3;
		}
		else
		{
			return (0);
		}
	}
	*read = (*read)->next;
	return (1);
}

int		li_match_room(t_room *room, char *str)
{
	size_t	i;

	room->name = str;
	if (*(str + 0) == 'L')
		return (0);
	i = 0;
	while (*(str + i) != ' ' && *(str + i) != '\0')
	{
		i++;
	}
	if (*(str + i) == ' ')
	{
		*(str + i) = '\0';
		i++;
	}
	else
	{
		room->role = 5;
		return (1);
	}
	if (!ft_is_int(str, &i, &(room->pos_x)) && *(str + i) == ' ')
		return (0);
	i++;
	return ((ft_is_int(str, &i, &(room->pos_y)) && *(str + i) == '\0') ? 1 : 0);
}

int		li_match_rooms(t_input **read, t_data *data)
{
	int		wit;
	t_room	**tmp;

	tmp = &(data->rooms);
	wit = 1;
	while (*read && wit % 5 != 0)
	{
		if (!(*tmp) && !li_allocate_room(tmp))
			return (0);
		if (*((*read)->line + 0) == '#' && !li_deal_sharp_marks(*tmp, read))
		{
			return (0);
		}
		else
		{
			if (!li_match_room(*tmp, (*read)->line))
			{
				return (0);
			}
			wit = wit * (*tmp)->role;
		}
		*read = ((*tmp)->role == 5) ? *read : (*read)->next;
		tmp = &((*tmp)->next);
	}
	return (wit == 30 ? 1 : 0);
}
