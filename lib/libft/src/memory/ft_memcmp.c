/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 19:12:40 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/11 10:25:30 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief compare byte strigs s1 and s2. Both s are assumed to be n bytes long
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return Returns the int difference between the first two differing bytes
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*(ts1 + i) != *(ts2 + i))
			return (*(ts1 + i) - *(ts2 + i));
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const void	*s1 = "abc\0d";
// 	const void	*s2 = "abc\0q";

// 	printf("%i", ft_memcmp(s1, s2, 6));
// }