/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsign.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 16:50:37 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 20:52:15 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	l;

	l = 0;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int	ft_unsign(unsigned int u)
{
	int		l;
	int		i;
	char	*s;

	l = ft_len(u);
	i = l - 1;
	if (u == 0)
		return (write(1, "0", 1));
	s = ft_calloc(l + 1, sizeof(char));
	if (!s)
		return (0);
	s[l] = '\0';
	while (u)
	{
		s[i] = (u % 10) + '0';
		u /= 10;
		i--;
	}
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	free(s);
	return (l);
}
