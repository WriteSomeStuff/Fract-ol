/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:48:58 by cschabra      #+#    #+#                 */
/*   Updated: 2022/11/01 15:33:38 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free the node. The memory of
 * ’next’ must not be freed.
 * 
 * @param lst The node to free.
 * @param del The address of the function used to delete
 * the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// static void	del(void *r)
// {
// 	free(r);
// 	r = NULL;
// }

// int	main(void)
// {
// 	t_list	*n1 = ft_lstnew(ft_strdup("a"));

// 	printf("%s\n", n1->content);
// 	ft_lstdelone(n1, &del);
// 	// printf("%s\n", n1->content);
// 	// system ("leaks a.out");
// }