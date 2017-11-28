/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 03:27:43 by aberrahm          #+#    #+#             */
/*   Updated: 2017/05/31 17:29:12 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*del1;
	t_list	*del2;

	del1 = *alst;
	while (del1 != NULL)
	{
		del2 = del1->next;
		del(del1->content, del1->content_size);
		free(del1);
		del1 = del2;
	}
	*alst = NULL;
}
