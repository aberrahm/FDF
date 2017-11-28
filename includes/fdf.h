/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 06:19:31 by aberrahm          #+#    #+#             */
/*   Updated: 2017/07/08 10:27:26 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./keynote.h"
# include "./color.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
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

typedef	struct	s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	t_xy			win_size;
	t_xy			data_size;
	int				bpp;
	int				endian;
	int				sizeline;
}				t_mlx_data;

typedef	struct	s_all
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				recup;
	int				width;
	int				height;
	int				bpp;
	int				endian;
	int				sizeline;
	int				a;
	float			remnant;
	float			err;
	t_xy			posfdf;
	t_xy			pattern;
	t_xy			sign;
	t_xy			var;
	t_xy			start;
	t_xy			end;
	t_xy			coord;
	int				img_win;
	int				size_win_x;
	int				size_win_y;
}				t_all;

typedef struct	s_stock
{
	t_xy			coord;
	int				**tab;
	struct s_stock	*nxt;
}				t_stock;

t_xy			ft_iso1(t_xy posfdf);
t_xy			ft_iso(t_xy posfdf);
t_xy			ft_iso2(t_xy posfdf);
void			call_funct(t_all img1, t_stock *point);
void			ft_trace_map_nxt(t_all *img1, t_stock *lst, int len, int i);
void			ft_trace_map_nxt1(t_all *img1, t_stock *lst, int len, int i);
int				ft_key_hook(int keycode, t_all *pos);
int				create_line(t_all *pos, t_xy start, t_xy end, uint32_t color);
void			create_line_nxt(t_all *pos, t_xy *start, t_xy *end);
void			create_line_nxt1(t_all *pos, t_xy *start, uint32_t color);
void			ft_sign(t_all *pos, t_xy *start, t_xy *end);
void			ft_pattern(t_all *pos, t_xy *start, t_xy *end);
size_t			lenght_lst(t_stock *lst);
void			add(t_stock *new, t_stock **apoint);
int			recup_map(char *line, t_all img1);
void			create_img(t_all *img);
int				main(int ac, char **av);
void			my_pixel_put(t_all *pos1, int x, int y, uint32_t color);
void			equal_sae(t_all *pos, t_xy *start, t_xy *end);
int				temp_quit(void *data);
void			variable(t_all *pos, t_xy *start);
void			ft_trace_map(t_all *img1, t_stock *lst, int len);
void			ft_lstprint(t_stock *point);
t_stock			*head(t_xy point);
void			variable_a(t_all *pos, t_xy *start);
void			equal_sae_n(t_all *pos, t_xy *start);
void			abs_pattern(t_all *pos, t_xy *start, t_xy *end);
t_stock			*ft_get_lst(t_stock *start, size_t n);

#endif
