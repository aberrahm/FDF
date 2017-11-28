/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:35:40 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 04:34:48 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] != '\0') &&
			((const unsigned char)s1[i] == (const unsigned char)s2[i]))
		i++;
	return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
}
