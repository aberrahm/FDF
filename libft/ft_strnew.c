/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 02:51:12 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/28 20:28:27 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	str;

	if (!(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str = 0;
	while (str < size + 1)
	{
		ptr[str] = '\0';
		str++;
	}
	return (ptr);
}
