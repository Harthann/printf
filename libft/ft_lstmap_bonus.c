/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:09:25 by nieyraud          #+#    #+#             */
/*   Updated: 2019/10/21 09:27:19 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new_list;

	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new_list->content = f(lst->content)))
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	if (lst->next)
		new_list->next = ft_lstmap(lst->next, f, del);
	else
		new_list->next = NULL;
	return (new_list);
}
