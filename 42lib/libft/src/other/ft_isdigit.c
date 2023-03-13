/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:40:36 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:22:22 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for a decimal digit character. (0 - 9).
 * The value of the argument must be
 * representable as an unsigned char or the value of EOF.
 * @param c 
 * @return Returns int zero if the character tests false, returns non-zero if 
 * 	the character tests true.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int	main(void)
// {
// 	printf("%i", ft_isdigit('9'));
// }
