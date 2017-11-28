/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:00:02 by aberrahm          #+#    #+#             */
/*   Updated: 2017/06/05 18:33:04 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(s1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > i)
	{
		s1[i] = s[start];
		start++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
