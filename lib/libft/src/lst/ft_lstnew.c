/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschabra <cschabra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:11:51 by cschabra      #+#    #+#                 */
/*   Updated: 2022/10/20 18:46:36 by cschabra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’. The variable
 * ’next’ is initialized to NULL.
 * 
 * @param content 
 * @return t_list* The new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// void	printcontent(const t_list *new, const char *comment)
// {
// 	if (new == NULL)
// 		printf("%s is NULL\n", comment);
// 	else
// 	{
// 		printf("%s: content:%d  address:%p next:%p\n",
// 			comment,
// 			new->content,
// 			new,
// 			new->next);
// 	}
// }

// int	main(void)
// {
// 	t_list *first = NULL;
// 	t_list *second = NULL;

// 	printcontent(first, "first");
// 	printcontent(second, "second");

// 	first = ft_lstnew(100);
// 	second = ft_lstnew(200);

// 	printcontent(first, "first");
// 	printcontent(second, "second");

// 	first->next = second;
// 	printcontent(first, "first");
// 	printcontent(first->next, "first->next");
// 	printcontent(second, "second");

// 	free(first);
// 	free(second);

// 	first = NULL;
// 	second = NULL;
// 	// system("leaks a.out");
// }