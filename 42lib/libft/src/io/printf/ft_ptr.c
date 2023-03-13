/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ptr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 13:47:03 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 20:52:12 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long p)
{
	int	l;

	l = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		p /= 16;
		l++;
	}
	return (l);
}

static int	ft_write(char *a, int i)
{
	while (a[i])
		write(1, &a[i++], 1);
	free (a);
	return (i);
}

int	ft_ptr(unsigned long p)
{
	int		l;
	int		i;
	int		t;
	char	*a;

	l = ft_len(p);
	i = 0;
	a = ft_calloc(l + 1, sizeof(char));
	if (!a)
		return (0);
	a[l--] = '\0';
	if (p == 0)
		a[i] = p + '0';
	while (p)
	{
		t = p % 16;
		if (t < 10)
			t += '0';
		else if (t >= 10)
			t += 87;
		a[l--] = t;
		p /= 16;
	}
	return (ft_write(a, i));
}
