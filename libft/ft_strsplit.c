/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:57:46 by aberrahm          #+#    #+#             */
/*   Updated: 2017/11/26 16:23:16 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_put_in_tab(char c, const char *str, char **dest)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else if (str[i] != c)
		{
			j = i;
			while (str[i] != c && str[i])
				i++;
			dest[k++] = ft_strsub(str, j, i - j);
		}
	}
	dest[k] = NULL;
	return (dest);
}

char			**ft_strsplit(char const *str, char c)
{
	int		word;
	char	**dest;

	if (!str)
		return (NULL);
	word = ft_countword(str, c);
	if (!(dest = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	dest = ft_put_in_tab(c, str, dest);
	return (dest);
}
