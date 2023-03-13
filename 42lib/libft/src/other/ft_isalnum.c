/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:48:26 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:21:42 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for any character if its a letter or number.
 * The value of the argument must be
 * representable as an unsigned char or the value of EOF.
 * 
 * @param c 
 * @return Returns int zero if the character tests false, returns non-zero if 
 * the character tests true.
 */
int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

// int	main(void)
// {
// 	printf("%i", ft_isalnum('a'));
// }
