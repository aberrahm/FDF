/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 04:27:40 by aberrahm          #+#    #+#             */
/*   Updated: 2017/05/31 17:24:40 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*last;

	first = NULL;
	last = NULL;
	while (lst != NULL)
	{
		if (last != NULL)
		{
			first->next = f(lst);
			first = first->next;
		}
		else
		{
			last = f(lst);
			first = last;
		}
		lst = lst->next;
	}
	return (last);
}
