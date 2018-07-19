/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:25:48 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 02:19:15 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux2_ft_itoa_base(size_t length, t_list *lst)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(str + i) = *((char *)lst->content);
		lst = lst->next;
		i++;
	}
	*(str + length) = '\0';
	return (str);
}

static char	*aux1_ft_itoa_base(t_list *l_n, size_t i, t_list *lst)
{
	t_list	new;
	char	c;

	if (*((size_t *)((l_n->next)->next)->content) > i)
	{
		c = '0';
	}
	else if (l_n->content_size == 1)
	{
		c = '-';
		l_n->content_size = 0;
	}
	else if (((l_n->next)->next)->content_size > i)
	{
		c = ' ';
	}
	else
	{
		return (aux2_ft_itoa_base(i, lst));
	}
	new.content = (void *)(&c);
	new.next = lst;
	return (aux1_ft_itoa_base(l_n, i + 1, &new));
}

char		*aux0_ft_itoa_base(t_list *l_n, size_t i, t_list *lst)
{
	t_list					new;
	char					c;
	unsigned long long int	tmp;

	if (*((unsigned long long int *)(l_n->content)) == 0)
	{
		return (aux1_ft_itoa_base(l_n, i, lst));
	}
	else
	{
		c = *((char *)((l_n->next)->content)\
				+ ((size_t)(*((unsigned long long int *)(l_n->content)))\
					% (l_n->next)->content_size));
		tmp = *((unsigned long long int *)l_n->content)\
				/ (unsigned long long int)((l_n->next)->content_size);
		l_n->content = (void *)(&tmp);
		new.content = (void *)(&c);
		new.next = lst;
		return (aux0_ft_itoa_base(l_n, i + 1, &new));
	}
}

char		*ft_itoa_base(int n, const char *base, size_t prec, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;
	long long int			tmp;
	unsigned long long int	nb;

	l_n.content_size = (n < 0) ? 1 : 0;
	tmp = (long long int)n;
	nb = (unsigned long long int)((n < 0) ? -tmp : tmp);
	l_n.content = (void *)(&nb);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
	{
		return (NULL);
	}
	l_base.next = &l_length;
	if (prec == 0)
	{
		prec = 1;
	}
	l_length.content = (void *)(&prec);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}
