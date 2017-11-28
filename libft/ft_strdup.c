/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:37:57 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/28 01:52:59 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*n;
	int		len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (!(n = (char*)malloc(sizeof(*src) * (len + 1))))
		return (NULL);
	while (src[i] != '\0')
	{
		n[i] = src[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
