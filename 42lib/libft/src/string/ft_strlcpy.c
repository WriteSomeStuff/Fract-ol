/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:46:12 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 17:42:14 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strlcpy() and strlcat() functions copy and concatenate 
 * strings with the same input parameters and output result as
 * snprintf(3). They are designed to be safer, more consistent,
 * and less error prone replacements for the easily misused 
 * functions strncpy(3) and strncat(3
 * strlcpy() and strlcat() take the full size of the destination buffer
 * and guarantee NUL-termination if there is room. Note
 * that room for the NUL should be included in dstsiz
 * strlcpy() copies up to dstsize - 1 characters from the string src to 
 * dst, NUL-terminating the result if dstsize is not 0.
 * If the src and dst strings overlap, the behavior is undefined.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t returns the total length of the string they tried to create.
 * the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	dst[128] = "Replace Me";
// 	const char	src[] = "zzzzzzzzz";

// 	printf("%zu\n", ft_strlcpy(dst, src, 50));
// 	printf("%s\n", dst);
// }
