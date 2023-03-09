/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:06:50 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:29:41 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a substring
 * from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return Char* to the substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*p;

	slen = ft_strlen(s);
	if (start >= slen)
		return (p = ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s[start], len + 1);
	p[len] = '\0';
	return (p);
}

// int	main(void)
// {
// 	char const		*s = "hola";
// 	unsigned int	start = 0;
// 	size_t			len = 6;
// 	char *ans = ft_substr(s, start, len);

// 	printf("%s", ans);
// 	// system("leaks a.out");
// }