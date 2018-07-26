/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_characters_convers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:43:16 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/26 02:33:18 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_string_convers\"\n");
*/

static int	pf_string_convers(const char *format, va_list ap, t_list *mai)
{
	char	*string;

	return ((!(string = va_arg(ap, char *))) ?
			pf_add_string_mai("(null)", mai, format)
			: pf_add_string_mai(string, mai, format));
}

/*
**	ft_putstr("Appel de \"pf_char_convers\"\n");
*/

static int	pf_char_convers(const char *format, va_list ap, t_list *mai)
{
	size_t			prec;
	size_t			spac;
	unsigned char	c;

	c = (!(pf_jump_to_conv_spec(format) == '%')) ?
		(unsigned char)va_arg(ap, int) : '%';
	pf_get_prec_and_spac(format, &prec, &spac);
	if (spac > 1)
	{
		if (!(mai->content = (void *)pf_malloc_and_left_spaces(spac, 1)))
			return (-1);
		*(((char *)mai->content) + spac - 1) = (char)c;
	}
	else
	{
		if (!(mai->content = (void *)malloc(2 * sizeof(char))))
			return (-1);
		*(((char *)mai->content) + 0) = (char)c;
		*(((char *)mai->content) + 1) = '\0';
	}
	if (c == '\0')
		mai->content_size = (spac == 0) ? spac + 1 : spac;
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
		return (pf_add_string_mai("(null)", mai, format));
	pf_get_prec_and_spac(format, &prec, &spac);
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
	if (!(mai->content = (void *)ft_widestring_to_string(widestring, spac)))
		return (-1);
	if (*(widestring + 0) == L'\0')
		mai->content_size = (spac == 0) ? spac + 1 : spac;
	return (0);
}

/*
**	ft_putstr("Appel de \"pf_characters_convers\"\n");
*/

int			pf_characters_convers(const char *format, va_list ap,\
												t_list *mai, const char *type)
{
	int	wit;

	wit = -1;
	if (*type == 's')
	{
		wit = pf_string_convers(format, ap, mai);
	}
	else if (*type == 'c' || *type == '%')
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
