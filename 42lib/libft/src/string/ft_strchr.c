/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:21:03 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:27:43 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c (converted to a char) in 
 * the string pointed to by s. The terminating null character is 
 * considered to be part of the string; therefore if c is `\0', 
 * the functions locate the terminating `\0'.
 * 
 * @param s 
 * @param c 
 * @return char* return a pointer to the located character, or NULL if
 *  the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] && str[i] != (char)c)
	{
		i++;
	}
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s = "Find the character";
// 	int			c = 't';

// 	printf("%s", ft_strchr(s, c));
// }