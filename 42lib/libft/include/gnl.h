/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 20:33:51 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 21:11:07 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_leftover(char *store);
char	*get_next_line(int fd);

#endif