/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:26:59 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:22:15 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for an ASCII character, which is any character 
 * between 0 and octal 0177 inclusive.
 * 
 * @param c 
 * @return Returns int zero if the character tests false, returns non-zero if 
 * 	the character tests true.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	printf("%i", ft_isascii(-1));
// }
