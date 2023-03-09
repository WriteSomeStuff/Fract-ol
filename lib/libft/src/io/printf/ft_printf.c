/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 11:49:01 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 21:06:27 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ilen(int v)
{
	int	l;

	ft_putnbr_fd(v, STDOUT_FILENO);
	if (v > 0)
		l = 0;
	else
		l = 1;
	while (v != 0)
	{
		l++;
		v /= 10;
	}
	return (l);
}

static int	ft_slen(char *s)
{
	int	c;

	c = 0;
	if (!s)
		s = "(null)";
	c = ft_putstr_pf(s);
	if (c == -1)
		return (-1);
	return (ft_strlen(s));
}

static int	ft_indexcheck(const char *s, int i, va_list args)
{
	if (!s || !i || !args)
		return (-1);
	if (s[i] == '%')
		return (ft_putchar_pf(s[i]));
	if (s[i] == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	if (s[i] == 'i' || s[i] == 'd')
		return (ft_ilen(va_arg(args, int)));
	if (s[i] == 's')
		return (ft_slen(va_arg(args, char *)));
	if (s[i] == 'p')
	{
		write (1, "0x", 2);
		return (2 + ft_ptr(va_arg(args, unsigned long)));
	}
	if (s[i] == 'x' || s[i] == 'X')
		return (ft_hex(va_arg(args, unsigned int), s[i]));
	if (s[i] == 'u')
		return (ft_unsign(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		c;

	len = 0;
	i = 0;
	c = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
			c = ft_indexcheck(s, ++i, args);
		else
			c = write(1, &s[i], 1);
		if (c == -1)
			return (-1);
		len += c;
		i++;
	}
	va_end(args);
	return (len);
}

// int main(void)
// {
// 	int	c;
// 	int r;

// 	c = ft_printf("%s", "test");
// 	printf("\n%i\n", c);
// 	r = printf("%s", "test");
// 	printf("\n%i\n", r);
// 	// system("leaks a.out");
// }
