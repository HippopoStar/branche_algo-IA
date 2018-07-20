#include "libft.h"
#include "common_functions.h"

int	main(void)
{
	wchar_t	test0[2];
	wchar_t	test1[4];
	wchar_t	test2[2];
	wchar_t	test3[5];
	char	*str0;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;

	*(test0 + 0) = L'a';
	*(test0 + 1) = L'\0';
	*(test1 + 0) = L'一';
	*(test1 + 1) = L'α';
	*(test1 + 2) = L'一';
	*(test1 + 3) = L'\0';
	*(test2 + 0) = L'ሴ';
	*(test2 + 1) = L'\0';
	*(test3 + 0) = L'一';
	*(test3 + 1) = L'α';
	*(test3 + 2) = L'一';
	*(test3 + 3) = L'ሴ';
	*(test3 + 4) = L'\0';
	str0 = ft_widestring_to_string(test0, 0);
	str1 = ft_widestring_to_string(test1, 0);
	str2 = ft_widestring_to_string(test2, 0);
	str3 = ft_widestring_to_string(test3, 0);
	ft_putstr(str0);
	ft_putchar('\n');
	ft_putstr(str1);
	ft_putchar('\n');
	ft_putstr(str2);
	ft_putchar('\n');
	ft_putstr(str3);
	ft_putchar('\n');
	str4 = ft_widestring_to_string(test0, 7);
	str5 = ft_widestring_to_string(test1, 7);
	str6 = ft_widestring_to_string(test2, 7);
	str7 = ft_widestring_to_string(test3, 7);
	ft_putstr(str4);
	ft_putchar('\n');
	ft_putstr(str5);
	ft_putchar('\n');
	ft_putstr(str6);
	ft_putchar('\n');
	ft_putstr(str7);
	ft_putchar('\n');
	return (0);
}
