/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 02:28:22 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/28 02:30:29 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		p;
	char	i;
	char	*str;

	str = (char *)s;
	p = 0;
	i = (char)c;
	while (str[p] != '\0')
	{
		if (str[p] == i)
			return (&str[p]);
		p++;
	}
	if (i == '\0')
		return (&str[p]);
	return (NULL);
}
