/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:38:35 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 06:31:33 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		taille;
	size_t		c;
	char		*s2;
	char		*s1;

	if (!s || !f)
		return (NULL);
	s1 = (char *)s;
	taille = ft_strlen(s1);
	c = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (taille + 1))))
		return (NULL);
	while (c < taille)
	{
		s2[c] = f(s1[c]);
		c++;
	}
	s2[c] = '\0';
	return (s2);
}
