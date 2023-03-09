/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:09:11 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 20:35:51 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static char	*ft_getans(char *store)
{
	char	*ans;
	int		i;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	ans = malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (free(store), NULL);
	ans[i] = '\0';
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		ans[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		ans[i] = store[i];
	return (ans);
}

static bool	ft_ncheck(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (true);
	return (false);
}

static char	*ft_read(char *store, int fd)
{
	char	*buf;
	int		c;

	c = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(store), NULL);
	buf[0] = '\0';
	while (!(ft_ncheck(buf)) && c != 0)
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == 0)
			break ;
		if (c < 0)
			return (free(buf), free(store), NULL);
		while (c <= BUFFER_SIZE)
			buf[c++] = '\0';
		store = ft_strjoin_free(store, buf);
		if (!store)
			return (NULL);
	}
	free(buf);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*ans;
	static char	*store[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!store[fd])
	{
		store[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!store[fd])
			return (NULL);
		store[fd][0] = '\0';
	}
	store[fd] = ft_read(store[fd], fd);
	if (!store[fd])
		return (NULL);
	ans = ft_getans(store[fd]);
	if (!ans)
		return (NULL);
	store[fd] = ft_leftover(store[fd]);
	if (!store[fd])
		return (free(ans), NULL);
	return (ans);
}

// int	main (void)
// {
// 	char *r;
// 	int fd1 = open("test.txt", O_RDONLY);
// 	int fd2 = open("drac.pdf", O_RDONLY);
// 	int fd3 = open("sw.txt", O_RDONLY);
// 	int i = 1;

// 	while (i <= 24)
// 	{
// 		r = get_next_line(fd1);
// 		printf("%i: %s", i, r);
// 		free(r);
// 		r = get_next_line(fd2);
// 		printf("%i: %s", i, r);
// 		free(r);
// 		r = get_next_line(fd3);
// 		printf("%i: %s", i, r);
// 		free(r);
// 		i++;
// 	}
// 	// system("leaks -q a.out");
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }