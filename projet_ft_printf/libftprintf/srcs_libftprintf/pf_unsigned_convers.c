#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_get_unsigned\"\n");
*/

static int	pf_get_unsigned(unsigned long long int *n, va_list ap, const char *type)
{
	ft_putstr("Appel de \"pf_get_unsigned\"\n");
	if (*type == 'u' || *type == 'o' || *type == 'x' || *type == 'X'
		|| *type == 'b' || *type == 'B')
	{
		*n = (unsigned long long int)va_arg(ap, unsigned int);
	}
	else if (!ft_strncmp("lu", type, 2) || !ft_strncmp("lo", type, 2)
		|| !ft_strncmp("lx", type, 2) || !ft_strncmp("lX", type, 2)
		|| !ft_strncmp("lb", type, 2) || !ft_strncmp("lB", type, 2)
		|| *type == 'U' || *type == 'O')
	{
		*n = (unsigned long long int)va_arg(ap, unsigned long int);
	}
	else if (!ft_strncmp("llu", type, 3) || !ft_strncmp("llo", type, 3)
		|| !ft_strncmp("llx", type, 3) || !ft_strncmp("llX", type, 3)
		|| !ft_strncmp("llb", type, 3) || !ft_strncmp("llB", type, 3)
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

/*
**	ft_putstr("Appel de \"aux_pf_unsigned_convers\"\n");
*/

static char	*aux_pf_unsigned_convers(unsigned long long int n, size_t prec, size_t spac, char conv_spec)
{
	ft_putstr("Appel de \"aux_pf_unsigned_convers\"\n");
	if (conv_spec == 'u' || conv_spec == 'U')
	{
		return (ft_ullitoa_base(n, "0123456789", prec, spac));
	}
	else if (conv_spec == 'o' || conv_spec == 'O')
	{
		return (ft_ullitoa_base(n, "01234567", prec, spac));
	}
	else if (conv_spec == 'x')
	{
		return (ft_ullitoa_base(n, "0123456789abcdef", prec, spac));
	}
	else if (conv_spec == 'X')
	{
		return (ft_ullitoa_base(n, "0123456789ABCDEF", prec, spac));
	}
	else if (conv_spec == 'b' || conv_spec == 'B')
	{
		return (ft_ullitoa_base(n, "01", prec, spac));
	}
	else
	{
		return (NULL);
	}
}

/*
**	ft_putstr("Appel de \"pf_unsigned_convers\"\n");
*/

int	pf_unsigned_convers(const char *format, va_list ap, t_list *mai, const char *type)
{
	ft_putstr("Appel de \"pf_unsigned_convers\"\n");
	unsigned long long int	n;
	size_t			prec;
	size_t			spac;
	char			conv_spec;

	if (pf_get_unsigned(&n, ap, type) == -1)
		return (-1);
	pf_get_prec_and_spac(format, &prec, &spac);
	conv_spec = pf_jump_to_conv_spec(type);
	if (pf_is_flag_present(format, '#'))
	{
		pf_anticipate_sharp_mark(n, conv_spec, &prec);
	}
	if (!(mai->content = (void *)aux_pf_unsigned_convers(n, prec, spac, conv_spec)))
		return (-1);
	if (pf_is_flag_present(format, '#'))
	{
		pf_apply_sharp_mark((char *)mai->content, conv_spec);
	}
	pf_deal_minus_sign_and_zero(format, (char *)mai->content, 0);
	return (0);
}
