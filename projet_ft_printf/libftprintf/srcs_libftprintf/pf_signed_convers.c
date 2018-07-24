#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"aux1_pf_get_signed\"\n");
*/

static int	aux1_pf_get_signed(long long int *n, va_list ap, const char *type)
{
	if (!ft_strncmp("jd", type, 2) || !ft_strncmp("ji", type, 2))
	{
		*n = (long long int)va_arg(ap, intmax_t);
	}
	else if (!ft_strncmp("zd", type, 2) || !ft_strncmp("zi", type, 2))
	{
		*n = (long long int)va_arg(ap, ssize_t);
	}
	else
	{
		return (-1);
	}
	return (0);
}

/*
**	ft_putstr("Appel de \"aux0_pf_get_signed\"\n");
*/

static int	aux0_pf_get_signed(long long int *n, va_list ap, const char *type)
{
	if (!ft_strncmp("hd", type, 2) || !ft_strncmp("hi", type, 2))
	{
		*n = (long long int)va_arg(ap, int);
	}
	else if (!ft_strncmp("hhd", type, 3) || !ft_strncmp("hhi", type, 3))
	{
		*n = (long long int)va_arg(ap, int);
	}
	else
	{
		return (aux1_pf_get_signed(n, ap, type));
	}
	return (0);
}

/*
**	ft_putstr("Appel de \"pf_get_signed\"\n");
*/

static int	pf_get_signed(long long int *n, va_list ap, const char *type)
{
	if (*type == 'd' || *type == 'i')
	{
		*n = (long long int)va_arg(ap, int);
	}
	else if (!ft_strncmp("ld", type, 2) || !ft_strncmp("li", type, 2)
		|| *type == 'D')
	{
		*n = (long long int)va_arg(ap, long int);
	}
	else if (!ft_strncmp("lld", type, 3) || !ft_strncmp("lli", type, 3)
		|| !ft_strncmp("lD", type, 2))
	{
		*n = va_arg(ap, long long int);
	}
	else
	{
		return (aux0_pf_get_signed(n, ap, type));
	}
	return (0);
}

/*
**	ft_putstr("Appel de \"pf_signed_convers\"\n");
*/

int	pf_signed_convers(const char *format, va_list ap, t_list *mai, const char *type)
{
	long long int	n;
	size_t		prec;
	size_t		spac;
	size_t		keep;

	if (pf_get_signed(&n, ap, type) == -1)
		return (-1);
	pf_get_prec_and_spac(format, &prec, &spac);
	keep = 0;
	if (pf_is_flag_present(format, ' ') || pf_is_flag_present(format, '+'))
	{
		keep = 1;
		pf_anticipate_plus_space(n, prec, &spac);
	}
	if (!(mai->content = (void *)ft_llitoa_base(n, "0123456789", prec, spac)))
		return (-1);
	pf_deal_zero(format, (char *)mai->content, keep);
	pf_deal_minus_sign(format, (char *)mai->content, keep);
	if (pf_is_flag_present(format, '+'))
	{
		pf_apply_plus_sign((char *)mai->content);
	}
	return (0);
}
