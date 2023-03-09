/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:35:43 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 17:11:55 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dst.
 * If dst and src overlap, behavior is undefined. Applications in which
 * dst and src might overlap should use memmove(3) instead.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* returns the original value of dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst == 0 && src == 0)
		return ((void *)dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dst);
}

// int	main(void)
// {
// 	char	dst[] = "Replace Me";
// 	const char	src[] =  "reeeeeeeeee";

// 	// memcpy(dst, src, 5);
// 	// printf("%s", dst);
// 	printf("%s", ft_memcpy(dst, src, 5));
// }
