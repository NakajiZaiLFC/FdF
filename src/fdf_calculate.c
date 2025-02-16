/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:12:37 by snakajim          #+#    #+#             */
/*   Updated: 2025/01/03 18:09:38 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	iso_projection(int x, int y, int z, t_fdf *fdf)
{
	t_point		p;
	t_iso_param	iso;

	iso.angle_x = M_PI / 6;
	iso.angle_y = M_PI / 6;
	iso.scale = fmin((fdf->win_width / (fdf->map.width * sqrt(2))),
			(fdf->win_height / (fdf->map.height * sqrt(2)))) * 0.7;
	iso.projected_x = (x - fdf->map.width / 2.0) * iso.scale;
	iso.projected_y = (y - fdf->map.height / 2.0) * iso.scale;
	iso.projected_z = z * (iso.scale * 0.5);
	p.x = (iso.projected_x - iso.projected_y) * cos(iso.angle_x);
	p.y = ((iso.projected_x + iso.projected_y) * sin(iso.angle_y)
			- iso.projected_z);
	p.x += fdf->win_width / 2;
	p.y += fdf->win_height / 2;
	return (p);
}

static void	_init_line_data(t_line_data *line, t_point p0, t_point p1)
{
	line->dx = abs(p1.x - p0.x);
	line->dy = abs(p1.y - p0.y);
	if (p0.x < p1.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (p0.y < p1.y)
		line->sy = 1;
	else
		line->sy = -1;
	if (line->dx > line->dy)
		line->error = line->dx / 2;
	else
		line->error = -line->dy / 2;
	line->current = p0;
}

static void	_update_line_position(t_line_data *line)
{
	line->error2 = line->error;
	if (line->error2 > -line->dx)
	{
		line->error -= line->dy;
		if (line->sx > 0)
			line->current.x += 1;
		else
			line->current.x -= 1;
	}
	if (line->error2 < line->dy)
	{
		line->error += line->dx;
		if (line->sy > 0)
			line->current.y += 1;
		else
			line->current.y -= 1;
	}
}

static void	_my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_line_to_image(t_img *img, t_point p0, t_point p1, int color)
{
	t_line_data	line;

	_init_line_data(&line, p0, p1);
	while (1)
	{
		if (line.current.x >= 0 && line.current.x < WIN_WIDTH
			&& line.current.y >= 0 && line.current.y < WIN_HEIGHT)
			_my_mlx_pixel_put(img, line.current.x, line.current.y, color);
		if (line.current.x == p1.x && line.current.y == p1.y)
			break ;
		_update_line_position(&line);
	}
}
