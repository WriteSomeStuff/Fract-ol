/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 09:44:49 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/19 16:44:05 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief locates the first occurrence of \0 terminated n in h, where not
 * more than len are searched. after \0 characters are not searched.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return if n empty return = h, n not found returns null else ptr to first char
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = ft_strlen(needle);
	if (count == 0 || !needle || !*needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&(haystack[i]));
		}
		i++;
		j = 0;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *haystack = "aaabcabcd";
// 	const char *needle = "aabc";

// 	printf("%s", ft_strnstr(haystack, needle, 20));
// }