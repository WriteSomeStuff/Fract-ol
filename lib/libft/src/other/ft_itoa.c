/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 17:59:46 by cschabra      #+#    #+#                 */
/*   Updated: 2022/11/24 19:34:38 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlength(int n)
{
	long int	nb;
	int			len;

	nb = n;
	len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 * 
 * @param n 
 * @return char* The string representing the integer.
 * NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	int			len;
	long int	nb;
	char		*p;

	len = ft_getlength(n);
	nb = n;
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	if (nb == 0)
		p[0] = '0';
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	p[len] = '\0';
	while (nb > 0)
	{
		p[len - 1] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (p);
}

// int	main(void)
// {
// 	int n = -1;
// 	char *p = ft_itoa(n);
// 	printf("%s", p);
// 	system("leaks a.out");
// }