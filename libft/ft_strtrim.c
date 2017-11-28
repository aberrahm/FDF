/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 05:36:12 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 07:21:17 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*str;
	char		*str1;

	str1 = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(str1) - 1;
	while (str1[i] == ' ' || str1[i] == '\n' || str1[i] == '\t')
		i++;
	while (str1[j] == ' ' || str1[j] == '\n' || str1[j] == '\t')
		j--;
	j++;
	if (str1[i] != '\0')
		str = ft_strsub(str1, i, j - i);
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}
