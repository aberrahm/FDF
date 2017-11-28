/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:14:41 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 06:47:54 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*s3;
	size_t	i;
	size_t	j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = (char *)malloc(sizeof(char) *
					(ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	while (str1[i] != '\0')
	{
		s3[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
		s3[i++] = str2[j++];
	s3[i] = '\0';
	return (s3);
}
