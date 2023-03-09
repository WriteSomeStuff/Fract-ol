/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:10:32 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 16:50:03 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief writes len bytes of value c (converted to an unsigned char)
 *  to the string b.
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* returns its first argument. (b)
 */
void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*b_temp;

	i = 0;
	b_temp = (unsigned char *)b;
	while (len > 0)
	{
		b_temp[i] = c;
		i++;
		len--;
	}
	return ((void *)b);
}

// int	main(void)
// {
// 	char	str[] = "Whut dis";

// 	printf("%s\n", ft_memset(str, 'a', 4));
// }
