/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:51:58 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:21:48 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for any character if it is a letter. 
 * The value of the argument must be
 * representable as an unsigned char or the value of EOF.
 * 
 * @param c 
 * @return Returns int zero if the character tests false, returns non-zero if 
 * 	the character tests true.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// int	main(void)
// {
// 	printf("%i", ft_isalpha('0'));
// }
