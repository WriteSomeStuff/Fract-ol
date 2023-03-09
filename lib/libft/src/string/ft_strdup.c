/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:05:49 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/14 21:01:14 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates sufficient memory for a copy of the string s1 and copies
 * 
 * @param s1 
 * @return A char* to the allocated memory
 */
char	*ft_strdup(const char *s1)
{
	void	*p;

	p = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, ft_strlen(s1));
	return ((char *)p);
}

// int	main(void)
// {
// 	char	*ptr = ft_strdup("whut");
// 	printf("%s", ptr);
// 	system("leaks a.out");
// }