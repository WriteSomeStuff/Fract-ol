/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:41:44 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/14 11:12:37 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c in string s.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return Pointer to the byte located, or NULL if no such byte exists within n.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	find;

	i = 0;
	str = (unsigned char *)s;
	find = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const void	*s  = "Check dis string";
// 	int			c = 'd';

// 	printf("%s", ft_memchr(s, c, 20));
// }