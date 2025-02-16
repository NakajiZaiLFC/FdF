/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mlx_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:48:50 by snakajim          #+#    #+#             */
/*   Updated: 2025/01/03 17:06:24 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	make_mlx_window(t_fdf *fdf)
{
	fdf->win_width = WIN_WIDTH;
	fdf->win_height = WIN_HEIGHT;
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (false);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, fdf->win_height,
			"Fil De Fer");
	if (!fdf->win_ptr)
		return (false);
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_width,
			fdf->win_height);
	if (!fdf->img.img_ptr)
		return (false);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img_ptr, &fdf->img.bpp,
			&fdf->img.size_line, &fdf->img.endian);
	if (!fdf->img.addr)
		return (false);
	ft_memset(fdf->img.addr, 0, fdf->img.size_line * fdf->win_height);
	return (true);
}
