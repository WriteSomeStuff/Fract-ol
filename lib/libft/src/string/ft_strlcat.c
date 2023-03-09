/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 09:33:17 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 18:20:29 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strlcpy() and strlcat() functions copy and concatenate 
 * strings with the same input parameters and output result as
 * snprintf(3). They are designed to be safer, more consistent, 
 * and less error prone replacements for the easily misused 
 * functions strncpy(3) and strncat(3).
 * strlcpy() and strlcat() take the full size of the destination buffer
 * and guarantee NUL-termination if there is room. Note
 * that room for the NUL should be included in dstsiz
 * strlcat() appends string src to the end of dst. It will append at most 
 * dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
 * dstsize is 0 or the original dst string was longer than dstsize (in practice 
 * this should not happen as it means that either dstsize is incorrect or that 
 * dst is not a proper string
 * If the src and dst strings overlap, the behavior is undefined.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t returns the total length of the string they tried to create.
 * the initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	const size_t	dst_len = ft_strlen(dst);
	const size_t	src_len = ft_strlen(src);

	i = 0;
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	if (dstsize > dst_len + 1)
	{
		while (src[i] && dst_len + 1 + i < dstsize)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char	*dst = "HelloWorld!";
// 	const char	*src = "!!!!!!";

// 	printf("%zu", ft_strlcat(dst, src, 11));
// 	printf("%s", dst);
// }
