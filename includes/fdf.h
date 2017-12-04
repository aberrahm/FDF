/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 06:19:31 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/04 03:08:59 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./keynote.h"
# include "./color.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_xy
{
	int				x;
	int				y;
	int				z;
}				t_xy;

typedef struct	s_pixelput
{
	t_xy			current;
	t_xy			start;
	t_xy			end;
	int				color;
}				t_pixelput;

typedef	struct	s_all
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				*recup;
	int				width;
	int				height;
	int				bpp;
	int				endian;
	int				sizeline;
	int				a;
	float			remnant;
	float			err;
	t_xy			posfdf;
	t_xy			size_map;
	t_xy			pattern;
	t_xy			sign;
	t_xy			var;
	t_xy			start;
	t_xy			end;
	t_xy			translate;
	t_list			*startlst;
	int				img_win;
	int				size_win_x;
	int				size_win_y;
}				t_all;

void			ft_resize_map_nxt(t_all *pos, t_xy *dot,
		t_xy *resize, t_xy *margin);
void			ft_trace_map_nxt(t_list *map, t_all *pos, t_xy start, t_xy end);
int				ft_key_exit(int keycode, t_all *pos);
void			call_ft(t_all img1);
int				ft_key_hook(int keycode, t_all *pos);
int				create_line(t_all *pos, t_xy start, t_xy end, uint32_t color);
void			create_line_nxt(t_all *pos, t_xy *start,
		t_xy *end, uint32_t color);
void			create_line_nxt1(t_all *pos, t_xy *start, uint32_t color);
void			ft_sign(t_all *pos, t_xy *start, t_xy *end);
void			ft_pattern(t_all *pos, t_xy *start, t_xy *end);
int				*recup_map(char *line);
void			create_img(t_all *img);
int				main(int ac, char **av);
void			my_pixel_put(t_all *pos1, int x, int y, uint32_t color);
void			equal_sae(t_all *pos, t_xy *start, t_xy *end);
void			variable(t_all *pos, t_xy *start);
void			ft_trace_map(t_list *map, t_all *img1);
void			variable_a(t_all *pos, t_xy *start);
void			equal_sae_n(t_all *pos, t_xy *start);
void			abs_pattern(t_all *pos, t_xy *start, t_xy *end);

#endif
