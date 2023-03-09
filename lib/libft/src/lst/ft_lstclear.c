/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 18:52:37 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/19 16:39:44 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and every
 * successor of that node, using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
 * the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		p = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
	*lst = NULL;
}

// static void	del(void *r)
// {
// 	free(r);
// 	r = NULL;
// }

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew(ft_strdup("a"));
// 	t_list *n2 = ft_lstnew(ft_strdup("b"));

// 	n1->next = n2;
// 	printf("%s\n", n1->content);
// 	printf("%s\n", n2->content);
// 	ft_lstclear(&n1, &del);
// 	system ("leaks a.out");
// }