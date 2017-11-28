/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:25:32 by aberrahm          #+#    #+#             */
/*   Updated: 2017/07/06 06:42:24 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		create_line(t_all *pos, t_xy start, t_xy end, uint32_t color)
{
	pos->remnant = -0.5;
	ft_pattern(pos, &start, &end);
	pos->err = (float)ft_max(ft_abs(pos->pattern.x), ft_abs(pos->pattern.y)) /
		(float)ft_min(ft_abs(pos->pattern.x), ft_abs(pos->pattern.y));
	pos->err = pos->err - (int)pos->err;
	ft_sign(pos, &start, &end);
	abs_pattern(pos, &start, &end);
	my_pixel_put(pos, start.x, start.y, color);
	create_line_nxt(pos, &start, &end);
	return (0);
}

void	create_line_nxt(t_all *pos, t_xy *start, t_xy *end)
{
	while (!(start->x == end->x && start->y == end->y))
	{
		pos->remnant += pos->err;
		pos->var.x = 0;
		pos->var.y = 0;
		if (pos->remnant >= 0)
		{
			pos->remnant -= 1.0;
			equal_sae(pos, start, end);
			my_pixel_put(pos, start->x, start->y, ROSEC);
		}
		equal_sae_n(pos, start);
		my_pixel_put(pos, start->x, start->y, ROSEC);
		create_line_nxt1(pos, start, AQUA);
	}
}

void	create_line_nxt1(t_all *pos, t_xy *start, uint32_t color)
{
	while (pos->var.x < pos->pattern.x)
	{
		variable(pos, start);
		my_pixel_put(pos, start->x, start->y, color);
	}
	while (pos->var.y < pos->pattern.y)
	{
		variable_a(pos, start);
		my_pixel_put(pos, start->x, start->y, color);
	}
}

void	ft_pattern(t_all *pos, t_xy *start, t_xy *end)
{
	pos->pattern.x = (end->x - start->x);
	pos->pattern.y = (end->y - start->y);
	pos->pattern.x = (pos->pattern.x ? pos->pattern.x : 1);
	pos->pattern.y = (pos->pattern.y ? pos->pattern.y : 1);
}

void	equal_sae_n(t_all *pos, t_xy *start)
{
	if (pos->pattern.x == pos->pattern.y)
	{
		start->x += pos->sign.x;
		start->y += pos->sign.y;
		pos->var.x++;
		pos->var.y++;
	}
}
