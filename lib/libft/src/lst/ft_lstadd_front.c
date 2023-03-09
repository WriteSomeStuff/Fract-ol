/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 11:06:30 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 18:46:44 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * 
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the node to be added to the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list *old = ft_lstnew(0);
// 	t_list *lst = old;

// 	printf("content:%d  address:%p next:%p lstpointsto:%p\n",
// 			old->content,
// 			old,
// 			old->next,
// 			lst);

// 	t_list *new = ft_lstnew(1);
// 	ft_lstadd_front(&lst, new);
// 	printf("content:%d  address:%p next:%p\n",
// 		new->content,
// 		new,
// 		new->next);

// 	free(new);
// 	free(old);

// 	new = NULL;
// 	old = NULL;
// 	// system("leaks a.out");
// }