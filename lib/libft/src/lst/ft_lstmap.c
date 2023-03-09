/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:01:53 by cschabra      #+#    #+#                 */
/*   Updated: 2022/11/24 19:44:09 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 * 
 * @param lst The address of a pointer to a first node.
 * @param f The address of the function used to do something with new node.
 * @param del The address of the function used to delete
 * the content of a node if needed.
 * @return t_list* The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*head;

	head = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newnode, del);
			return (NULL);
		}
		if (head == NULL)
			head = newnode;
		else
			ft_lstadd_back(&head, newnode);
		lst = lst->next;
	}
	return (head);
}

// static void	*f(void *r)
// {
// 	*(char*)r = *(char*)r - 32;
// 	return (r);
// }

// static void	del(void *r)
// {
// 	free(r);
// 	r = NULL;
// }

// void printlist(t_list *head)
// {
// 	while (head)
// 	{
// 		printf("content: %s address: %p next: %p\n",
// 					head->content, head, head->next);
// 		head = head->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*fl1 = ft_lstnew(ft_strdup("a"));
// 	t_list	*fl2 = ft_lstnew(ft_strdup("b"));
// 	t_list	*fl3 = ft_lstnew(ft_strdup("c"));
// 	t_list	*ans = NULL;

// 	fl1->next = fl2;
// 	fl2->next = fl3;
// 	printlist(fl1);
// 	ans = ft_lstmap(fl1, &f, &del);
// 	printlist(ans);
// 	// system("leaks a.out");
// }