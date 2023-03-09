/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_io.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:22:21 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/09 12:22:35 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (s[i])
	{
		c = write(STDOUT_FILENO, &s[i], 1);
		if (c == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putchar_pf(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(char)));
}
