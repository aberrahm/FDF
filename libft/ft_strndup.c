/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 00:33:52 by aberrahm          #+#    #+#             */
/*   Updated: 2017/04/05 07:05:06 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t		i;
	char		*s2;
	size_t		len;

	len = ft_strlen((char*)s1);
	if (n < len)
		len = n;
	i = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] && i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
