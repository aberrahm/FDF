/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:57:05 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 06:31:19 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	c;
	char	*s2;

	if (!s || !f)
		return (NULL);
	str = (char *)s;
	size = ft_strlen(str);
	c = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (c < size)
	{
		s2[c] = f(c, str[c]);
		c++;
	}
	s2[c] = '\0';
	return (s2);
}
