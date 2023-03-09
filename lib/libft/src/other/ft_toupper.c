/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:04:56 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/11 11:29:21 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Change lowercase to uppercase
 * 
 * @param c 
 * @return Uppercase of c if possible, else it returns c
 */
int	ft_toupper(int c)
{
	if (c < 'a' || c > 'z')
		return (c);
	c -= 32;
	return (c);
}

// int	main(void)
// {
// 	char	c = 'A';

// 	printf("%c", ft_toupper(c));
// }