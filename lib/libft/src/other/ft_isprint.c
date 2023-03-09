/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:37:06 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:22:28 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for any printing character, including space(` ')
 * The value of the argument must be
 * representable as an unsigned char or the value of EOF.
 * @param c 
 * @return Returns int zero if the character tests false, returns non-zero if 
 * 	the character tests true.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int	main(void)
// {
// 	printf("%i", ft_isprint(1));
// }
