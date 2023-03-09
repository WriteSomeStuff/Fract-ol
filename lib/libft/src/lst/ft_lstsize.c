/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:26:52 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/18 14:43:35 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in a list.
 * 
 * @param lst The beginning of the list.
 * @return int The length of the list
 */
int	ft_lstsize(t_list *lst)
{
	t_list	*t;
	int		size;

	t = lst;
	size = 0;
	if (t == 0)
		return (size);
	while (t)
	{
		size++;
		t = t->next;
	}
	return (size);
}

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew(0);
// 	t_list *n2 = ft_lstnew(0);
// 	t_list *n3 = ft_lstnew(0);
// 	t_list *lst = n1;
// 	int siiize;
// 	n1->next = n2;
// 	n2->next = n3;

// 	siiize = ft_lstsize(lst);
// 	printf("amount of nodes: %d", siiize);
// 	system("leaks a.out");
// }