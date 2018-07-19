#include "libftprintf.h"

static int	aux_pf_signed_convers(long long int *n, va_list ap, const char *type)
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
		|| !ft_strncmp("lD", 2))
	{
		*n = va_arg(ap, long long int);
	}
	else
	{
		return (-1);
	}
	return (0);
}

int	pf_signed_convers(const char *format, va_list ap, t_list *mai, const char *type)
{
	long long int	n;
	size_t		prec;
	size_t		spac;
	size_t		keep;

	if (aux_pf_signed_convers(&n, ap, type) == -1)
		return (-1);
	pf_get_prec_and_spac(format, &prec, &spac);
	keep = 0;
	if (pf_is_flag_present(format, ' ') || pf_is_flag_present(format, '+'))
	{
		keep = 1;
		pf_anticipate_space(n, &spac);
	}
	if (!(mai->content = (void *)ft_lli_toa_base(n, "0123456789", prec, spac)))
		return (-1);
	pf_apply_minus_sign_and_zero(format, (char *)mai->content, keep);
	if (is_flag_present(format, '+'))
	{
		pf_apply_plus_sign((char *)mai->content);
	}
	return (0);
}
