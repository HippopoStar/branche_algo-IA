#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_string_convers\"\n");
*/

static int	pf_string_convers(const char *format, va_list ap, t_list *mai)
{
	ft_putstr("Appel de \"pf_string_convers\"\n");
	size_t	length;
	size_t	prec;
	size_t	spac;
	char	*string;

	if (!(string = va_arg(ap, char *)))
		return (-1);
	length = ft_strlen(string);
	pf_get_prec_and_spac(format, &prec, &spac);
	if (prec > length || spac > length)
	{
		spac = (prec > spac) ? prec : spac;
		if (!(mai->content = (void *)pf_malloc_and_left_spaces(spac, length)))
			return (-1);
		ft_strcpy((((char *)mai->content) + spac - length), string);
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
	ft_putstr("Appel de \"pf_char_convers\"\n");
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
	(void)format;
	(void)ap;
	(void)mai;
	return (-1);
}

/*
**	ft_putstr("Appel de \"pf_widechar_convers\"\n");
*/

static int	pf_widechar_convers(const char *format, va_list ap, t_list *mai)
{
	(void)format;
	(void)ap;
	(void)mai;
	return (-1);
}

/*
**	ft_putstr("Appel de \"pf_characters_convers\"\n");
*/

int	pf_characters_convers(const char *format, va_list ap, t_list *mai, const char *type)
{
	int	wit;

	ft_putstr("Appel de \"pf_characters_convers\"\n");
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
		pf_deal_characters_flags(format, (char *)mai->content);
	}
	return (wit);
}
