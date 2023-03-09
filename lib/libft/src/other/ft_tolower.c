/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:17:02 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/11 11:28:51 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Change uppercase to lowercase
 * 
 * @param c 
 * @return Lowercase of c if possible, else it returns c
 */
int	ft_tolower(int c)
{
	if (c < 'A' || c > 'Z')
		return (c);
	c += 32;
	return (c);
}

// int	main(void)
// {
// 	char	c = 'A';

// 	printf("%c", ft_tolower(c));
// }