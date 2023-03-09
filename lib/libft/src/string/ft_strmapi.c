/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 13:54:54 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/19 16:43:57 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ to each character of the
 * string ’s’, and passing its index as first argument
 * to create a new string (with malloc(3)) resulting
 * from successive applications of ’f’.
 * 
 * @param s 
 * @param f 
 * @return char* The string created from the successive applications
 * of ’f’. Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		slen;
	int		i;
	char	*p;

	slen = ft_strlen(s);
	i = 0;
	if (!s || !f)
		return (NULL);
	p = (char *)malloc(sizeof(char) * slen + 1);
	if (!p)
		return (NULL);
	while (i < slen)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = 0;
	return (p);
}

// char	ft_test(unsigned int i, char c)
// {
// 	return (c + (i + 1));
// }

// int	main(void)
// {
// 	char const *s = "aaaaaaa";
// 	char *string = ft_strmapi(s, &ft_test);
// 	printf("%s", string);
// 	// system("leaks a.out");
// }