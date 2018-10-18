/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:50:55 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:43:32 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*head;
	t_list		*elem;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (!(new = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	head = new;
	while (lst)
	{
		elem = f(lst);
		if (!(new->next = ft_lstnew(elem->content, elem->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
