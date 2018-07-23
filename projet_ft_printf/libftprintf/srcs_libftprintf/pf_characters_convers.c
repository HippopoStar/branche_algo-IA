#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_string_convers\"\n");
*/

static int	pf_string_convers(const char *format, va_list ap, t_list *mai)
{
	size_t	length;
	size_t	prec;
	size_t	spac;
	char	*string;

	if (!(string = va_arg(ap, char *)))
		return (pf_add_const_string_mai("(null)", mai));
	length = ft_strlen(string);
	pf_get_prec_and_spac(format, &prec, &spac);
	if (pf_is_flag_present(format, '.') && prec < length)
	{
		length = prec;
	}
	if (prec > length || spac > length)
	{
		spac = (prec > spac) ? prec : spac;
		if (!(mai->content = (void *)pf_malloc_and_left_spaces(spac, length)))
			return (-1);
		ft_strncpy((((char *)mai->content) + spac - length), string, length);
		*((char *)((mai->content) + spac + length)) = '\0';
	}
	else if (!(mai->content = (void *)ft_strdup(string)))
		return (-1);
	return (0);
}

/*
**	ft_putstr("Appel de \"pf_char_convers\"\n");
*/

static int	pf_char_convers(const char *format, va_list ap, t_list *mai)
{
	size_t	prec;
	size_t	spac;
	char	c;

	c = (char)va_arg(ap, int);
	pf_get_prec_and_spac(format, &prec, &spac);
	if (prec > 1 || spac > 1)
	{
		spac = (prec > spac) ? prec : spac;
		if (!(mai->content = (void *)pf_malloc_and_left_spaces(spac, 1)))
			return (-1);
		*(((char *)mai->content) + spac - 1) = c;
	}
	else
	{
		if (!(mai->content = (void *)malloc(2 * sizeof(char))))
			return (-1);
		*(((char *)mai->content) + 0) = c;
		*(((char *)mai->content) + 1) = '\0';
	}
	return (0);
}		

/*
**	ft_putstr("Appel de \"pf_widestring_convers\"\n");
*/

static int	pf_widestring_convers(const char *format, va_list ap, t_list *mai)
{
	wchar_t	*widestring;
	size_t	length;
	size_t	prec;
	size_t	spac;

	if (!(widestring = va_arg(ap, wchar_t *)))
		return (pf_add_const_string_mai("(null)", mai));
	pf_get_prec_and_spac(format, &prec, &spac);
	if (prec > spac)
	{
		spac = prec;
	}
	if (!(mai->content = (void *)ft_widestring_to_string(widestring, spac)))
		return (-1);
	length = 0;
	while (*((char *)((mai->content) + spac + length)) != '\0')
	{
		length++;
	}
	if (pf_is_flag_present(format, '.') && prec < length)
	{
		*((char *)((mai->content) + spac + prec)) = '\0';
	}
	return (0);
}

/*
**	ft_putstr("Appel de \"pf_widechar_convers\"\n");
*/

static int	pf_widechar_convers(const char *format, va_list ap, t_list *mai)
{
	wchar_t	widestring[2];
	size_t	prec;
	size_t	spac;

	*(widestring + 0) = (wchar_t)va_arg(ap, wint_t);
	*(widestring + 1) = (wchar_t)L'\0';
	pf_get_prec_and_spac(format, &prec, &spac);
	if (prec > spac)
	{
		spac = prec;
	}
	if (!(mai->content = (void *)ft_widestring_to_string(widestring, spac)))
		return (-1);
	return (0);
}

/*
**	ft_putstr("Appel de \"pf_characters_convers\"\n");
*/

int	pf_characters_convers(const char *format, va_list ap, t_list *mai, const char *type)
{
	int	wit;

	wit = -1;
	if (*type == 's')
	{
		wit = pf_string_convers(format, ap, mai);
	}
	else if (*type == 'c')
	{
		wit = pf_char_convers(format, ap, mai);
	}
	else if (*type == 'S' || !ft_strncmp("ls", type, 2))
	{
		wit = pf_widestring_convers(format, ap, mai);
	}
	else if (*type == 'C' || !ft_strncmp("lc", type, 2))
	{
		wit = pf_widechar_convers(format, ap, mai);
	}
	if (wit != -1)
	{
		pf_deal_minus_sign_and_zero(format, (char *)mai->content, 0);
	}
	return (wit);
}
