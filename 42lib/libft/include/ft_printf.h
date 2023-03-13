/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 20:42:11 by cschabra      #+#    #+#                 */
/*   Updated: 2023/03/08 21:12:48 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int		ft_putstr_pf(char *s);
int		ft_putchar_pf(char c);
int		ft_printf(const char *s, ...);
int		ft_ptr(unsigned long p);
int		ft_hex(unsigned int n, char f);
int		ft_unsign(unsigned int u);

#endif