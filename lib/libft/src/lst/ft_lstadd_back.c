/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 15:35:03 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/21 11:23:19 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the end of the list.
 * 
 * @param lst The address of a pointer to the first link of
 * a list.
 * @param new The address of a pointer to the node to be
 * added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!new)
		return ;
	t = ft_lstlast(*lst);
	if (t == NULL)
		ft_lstadd_front(lst, new);
	else if (t != NULL)
		t->next = new;
}

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew(0);
// 	t_list *n2 = ft_lstnew(0);
// 	t_list *n3 = ft_lstnew(0);
// 	t_list *lst = n1;

// 	n1->next = n2;
// 	n2->next = n3;
// 	printf("Before: n3 address:%p next:%p\n",
// 			n3,
// 			n3->next);
// 	t_list *new = ft_lstnew(0);
// 	ft_lstadd_back(&lst, new);

// 	printf("After: n3 address:%p n3 next:%p address new:%p next:%p\n",
// 			n3,
// 			n3->next,
// 			new,
// 			new->next);

// 	// system("leaks a.out");
// }