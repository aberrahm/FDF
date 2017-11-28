/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 02:23:26 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 07:27:38 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	p;
	char	i;
	char	*s1;

	s1 = (char *)s;
	i = (char)c;
	p = ft_strlen(s1);
	if (c == '\0')
		return (s1 + p);
	while (p--)
		if (s1[p] == i)
			return (&s1[p]);
	return (NULL);
}
