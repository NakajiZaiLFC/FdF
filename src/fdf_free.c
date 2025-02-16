/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:48:28 by snakajim          #+#    #+#             */
/*   Updated: 2025/01/02 20:20:00 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	err_fdf_free(t_fdf *fdf)
{
	int	i;

	if (!fdf)
		return ;
	i = 0;
	if (fdf->map.points)
	{
		while (i < fdf->map.height)
		{
			if (fdf->map.points[i])
				free(fdf->map.points[i]);
			i++;
		}
		free(fdf->map.points);
	}
}

void	fdf_free(t_fdf *fdf)
{
	int	i;

	if (!fdf)
		return ;
	i = 0;
	if (fdf->map.points)
	{
		while (i < fdf->map.height)
		{
			if (fdf->map.points[i])
				free(fdf->map.points[i]);
			i++;
		}
		free(fdf->map.points);
	}
	free(fdf);
}

void	mlx_free(t_fdf *fdf)
{
	if (fdf->img.img_ptr)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img_ptr);
	if (fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr)
		mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
}
