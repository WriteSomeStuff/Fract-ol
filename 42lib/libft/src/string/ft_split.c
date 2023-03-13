/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:56:08 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:26:48 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	wordl;

	wordl = 0;
	while (s[i] != c && s[i])
	{
		wordl++;
		i++;
	}
	return (wordl);
}

static char	**ft_free(char **ans, int j)
{
	while (j >= 0)
	{
		free(ans[j]);
		j--;
	}
	free(ans);
	return (NULL);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array 
 * of strings obtained by splitting ’s’ using the 
 * character ’c’ as a delimiter. The array must end with a NULL pointer.
 * 
 * @param s 
 * @param c 
 * @return char** The array of new strings resulting from the split else 
 * NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		size;
	char	**ans;

	i = 0;
	j = 0;
	word = ft_wordcount(s, c);
	ans = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ans)
		return (NULL);
	while (j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_wordlen(s, c, i);
		ans[j] = ft_substr(s, i, size);
		if (!ans[j])
			return (ft_free(ans, j));
		i += size;
		j++;
	}
	ans[j] = 0;
	return (ans);
}

// int	main(void)
// {
// 	char const	s[] = "  \nSplit   This pls     ";
// 	char	c = ' ';
// 	char **arr = ft_split(s, c);

// 	int	i = 0;
// 	while (arr[i] != 0)
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// 	// system("leaks a.out");
// }