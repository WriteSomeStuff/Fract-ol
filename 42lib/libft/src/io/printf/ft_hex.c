/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:19:46 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 20:51:42 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	l;

	l = 0;
	while (n)
	{
		n /= 16;
		l++;
	}
	return (l);
}

static int	ft_inputcheck(int t, char f)
{
	if (t < 10)
		return (t += 48);
	else if (t >= 10 && f == 'X')
		return (t += 55);
	else if (t >= 10 && f == 'x')
		return (t += 87);
	return (0);
}

int	ft_hex(unsigned int n, char f)
{
	int		l;
	int		i;
	int		t;
	char	*hex;

	l = ft_len(n);
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	hex = ft_calloc(l + 1, sizeof(char));
	if (!hex)
		return (0);
	hex[l--] = '\0';
	while (n)
	{
		t = n % 16;
		t = ft_inputcheck(t, f);
		hex[l--] = t;
		n /= 16;
	}
	while (hex[i])
		write(1, &hex[i++], 1);
	free (hex);
	return (i);
}
