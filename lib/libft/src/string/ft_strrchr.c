/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 13:14:34 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 18:28:28 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of c (converted to a char) in 
 * the string pointed to by s. The terminating null character is 
 * considered to be part of the string; therefore if c is `\0', 
 * the functions locate the terminating `\0'.
 * 
 * @param s 
 * @param c 
 * @return char* return a pointer to the located character, or NULL if
 *  the character does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *)s;
	while (i != 0 && str[i] != (char)c)
		i--;
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s", ft_strrchr ("pepe y cparlos", 'c'));
// }