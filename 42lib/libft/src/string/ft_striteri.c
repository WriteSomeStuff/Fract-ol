/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:05:40 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/19 16:41:50 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ on each character of
 * the string passed as argument, passing its index
 * as first argument. Each character is passed by
 * address to ’f’ to be modified if necessary.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s || !f)
		return ;
	while (i < slen)
	{
		f(i, &s[i]);
		i++;
	}
}

// void	ft_test(unsigned int i, char *c)
// {
// 	*c = *c + i;
// }

// int	main(void)
// {
// 	char s[20] = "aaaa";
// 	ft_striteri(s, &ft_test);
// }