/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 19:36:16 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 19:05:18 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on
 * the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*t;

	t = lst;
	if (!lst)
		return ;
	while (t)
	{
		f(t->content);
		t = t->next;
	}
}

// static void	f(void *r)
// {
// 	*(char*)r = *(char*)r - 32;
// }

// int	main(void)
// {
// 	t_list	*n1 = ft_lstnew(ft_strdup("a"));
// 	t_list	*n2 = ft_lstnew(ft_strdup("b"));
// 	t_list	*n3 = ft_lstnew(ft_strdup("c"));
// 	t_list	*lst = n1;

// 	n1->next = n2;
// 	n2->next = n3;

// 	ft_lstiter(lst, &f);
// 	printf("%s", n1->content);
// 	printf("%s", n2->content);
// 	printf("%s", n3->content);

// 	system("leaks a.out");
// 	return (0);
// }