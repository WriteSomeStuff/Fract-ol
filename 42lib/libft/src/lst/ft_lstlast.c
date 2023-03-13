/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:45:54 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/18 15:27:55 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of the list.
 * 
 * @param lst The beginning of the list.
 * @return t_list* Last node of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	t = lst;
	if (t == 0)
		return (NULL);
	while (t->next)
	{
		t = t->next;
	}
	return (t);
}

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew(0);
// 	t_list *n2 = ft_lstnew(0);
// 	t_list *n3 = ft_lstnew(0);
// 	t_list *lst = n1;
// 	t_list *ans;
// 	n1->next = n2;
// 	n2->next = n3;

// 	ans = ft_lstlast(lst);
// 	printf("last node address: %p", ans);
// 	// system("leaks a.out");
// }