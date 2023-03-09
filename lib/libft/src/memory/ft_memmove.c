/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:15:00 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/19 16:41:15 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies len bytes from string src to string dst. The two strings 
 * may overlap; the copy is always done
 * in a non-destructive manner.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* returns the original value of dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (dst == 0 && src == 0)
		return ((void *)dst);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{	
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return ((void *)dst);
}

// int	main(void)
// {
// 	char	dst[] = "Replace me";
// 	char	src[] = "zzzz";

// 	// memmove(dst, src, 4);
// 	// printf("%s", dst);
// 	printf("%s", ft_memmove(dst, src, 4));
// }
