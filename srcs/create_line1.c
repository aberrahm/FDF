/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 23:36:10 by aberrahm          #+#    #+#             */
/*   Updated: 2017/11/24 19:13:38 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_sign(t_all *pos, t_xy *start, t_xy *end)
{
	pos->sign.x = start->x > end->x ? -1 : 1;
	pos->sign.y = start->y > end->y ? -1 : 1;
}

void	equal_sae(t_all *pos, t_xy *start, t_xy *end)
{
	if (ft_abs(end->x - start->x) > ft_abs(end->y - start->y))
		start->x += pos->sign.x;
	else
		start->y += pos->sign.y;
}

void	abs_pattern(t_all *pos, t_xy *start, t_xy *end)
{
	if (ft_abs(pos->pattern.x) > ft_abs(pos->pattern.y))
	{
		pos->pattern.x = ft_abs(pos->pattern.x / pos->pattern.y);
		pos->pattern.y = (end->y - start->y ? 1 : 0);
	}
	else
	{
		pos->pattern.y = ft_abs(pos->pattern.y / pos->pattern.x);
		pos->pattern.x = (end->x - start->x ? 1 : 0);
	}
}

void	variable(t_all *pos, t_xy *start)
{
	start->x += pos->sign.x;
	pos->var.x++;
}

void	variable_a(t_all *pos, t_xy *start)
{
	start->y += pos->sign.y;
	pos->var.y++;
}
