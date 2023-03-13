/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 14:16:43 by cschabra      #+#    #+#                 */
/*   Updated: 2022/11/24 19:35:23 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief String compare for n amount of bytes
 * @param s1
 * @param s2
 * @param n
 * @return Returns the int difference between the first difference found
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	*s1 = "abcdefgh";
// 	const char	*s2 = "abcdwxyz";

// 	printf("%i", ft_strncmp(s1, s2, 4));
// }