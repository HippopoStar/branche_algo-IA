#include "libftprintf.h"

static int	aux_pf_unsigned_convers(unsigned long long int *n, va_list ap, const char *type)
{
	if (*type == 'u' || *type == 'o' || *type == 'x' || *type == 'X')
	{
		*n = (unsigned long long int)va_arg(ap, unsigned int);
	}
	else if (!ft_strncmp("lu", type, 2) || !ft_strncmp("lo", type, 2)
		|| !ft_strncmp("lx", type, 2) || !ft_strncmp("lX", type, 2)
		|| *type == 'U' || *type == 'O')
	{
		*n = (unsigned long long int)va_arg(ap, unsigned long int);
	}
	else if (!ft_strncmp("llu", type, 3) || !ft_strncmp("llo", type, 3)
		|| !ft_strncmp("llx", type, 3) || !ft_strncmp("llX", type, 3)
		|| !ft_strncmp("lU", type, 2) || !ft_strncmp("lO", type, 2))
	{
		*n = (unsigned long long int)va_arg(ap, unsigned long long int);
	}
	else
	{
		return (-1);
	}
	return (0);
}

int	pf_unsigned_convers(const char *format, va_list ap, t_list *mai, const char *type)
{
	unsigned long long int	n;
	size_t			prec;
	size_t			spac;

	(void)format;
	(void)ap;
	(void)mai;
	(void)type;
	return (-1);
}
