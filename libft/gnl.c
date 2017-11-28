/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:59:31 by aberrahm          #+#    #+#             */
/*   Updated: 2017/04/17 18:44:00 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	easy_quit(char **str, int ret)
{
	ft_strdel(str);
	return (ret);
}

static int	gnl_search(char **str, char **line)
{
	char	*tmp;

	tmp = NULL;
	*line = NULL;
	if (*str)
		tmp = ft_strchr(*str, '\n');
	if (tmp && *str)
	{
		*line = ft_strndup(*str, tmp - *str);
		tmp = ft_strdup(tmp + 1);
		ft_strdel(str);
		*str = tmp;
		return (1);
	}
	if (!tmp && *str)
	{
		*line = *str;
		return (0);
	}
	return (-1);
}

static int	gnl_read(char **all, char **line, char *buf, int fd)
{
	int			ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		buf[ret] = '\0';
		if (ret == 0 && (*all == NULL || **all == '\0'))
		{
			*line = NULL;
			ft_strdel(all);
			return (easy_quit(&buf, 0));
		}
		else if (ret == 0 && (*line = *all) != NULL)
		{
			*all = NULL;
			return (easy_quit(&buf, 1));
		}
		*line = ft_strjoin(*all, buf);
		ft_strdel(all);
		*all = (*line ? *line : ft_strdup(buf));
		if ((ret = gnl_search(all, line)) == 1)
			return (easy_quit(&buf, 1));
		else if (ret == -1)
			return (easy_quit(&buf, -1));
	}
	return (easy_quit(&buf, -1));
}

int			get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*all;

	if (BUFF_SIZE > 0 && !(buf = (char*)malloc(BUFF_SIZE + 1)))
		return (-1);
	if (fd < 0 || line == NULL)
		return (easy_quit(&buf, -1));
	*line = NULL;
	if (gnl_search(&all, line) == 1)
		return (easy_quit(&buf, 1));
	return (gnl_read(&all, line, buf, fd));
}
