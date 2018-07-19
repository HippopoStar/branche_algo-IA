#include "libftprintf.h"

char	pf_jump_to_conv_spec(const char *format)
{
	size_t	i;

	i = 0;
	while (!(ft_strchr(PF_CONVERSION_SPECIFIERS, (int)*(format + i))
		|| *(format + i) == '\0'))
	{
		i++;
	}
	return (*(format + i));
}

void	pf_apply_plus_sign(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i + 1) == ' ')
	{
		i++;
	}
	if (!(*(str + i) == '-'))
	{
		*(str + i) = '+';
	}
}

void	pf_anticipate_space(long long int n, size_t *spac)
{
	size_t	nb_of_char;

	if (n > 0)
	{
		nb_of_char = 0;
		while (n > 0)
		{
			n = n / 10;
			nb_of_char++;
		}
		if (!(*spac > nb_of_char))
		{
			*spac = nb_of_char;
		}
	}
}		

void	pf_apply_sharp_mark(char *nbr_base, char conv_spec)
{
	size_t	i;

	i = 0;
	while (*(nbr_base + i) != '0')
	{
		i++;
	}
	*(nbr_base + 1) = conv_spec;
}

void	pf_anticipate_sharp_mark(unsigned long long int n, char conv_spec, size_t *prec)
{
	size_t			nb_of_char;
	unsigned long long int	base_length;

	base_length = 0;
	if (!(((conv_spec == 'o' || conv_spec == 'O') && (base_length = 8))
		|| ((conv_spec == 'x' || conv_spec == 'X') && (base_length = 16))
		|| ((conv_spec == 'b' || conv_spec == 'B') && (base_length = 2))))
	{
		nb_of_char = 0;
		while (n > 0)
		{
			n = n / base_length;
			nb_of_char++;
		}
		if (base_length == 8 && !(*prec > nb_of_char))
		{
			*prec = nb_of_char + 1;
		}
		else if ((base_length == 16 || base_length == 2)
			&& !(*prec > nb_of_char + 2))
		{
			if (n > 0)
			{
				*prec = nb_of_char + 2;
			}
			else
			{
				*prec = 3;
			}
		}
	}
}
