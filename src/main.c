/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:48:47 by snakajim          #+#    #+#             */
/*   Updated: 2025/01/03 17:00:31 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (EXIT_FAILURE);
	if (!fdf_init(ac, av, fdf))
		return (free(fdf), EXIT_FAILURE);
	if (!make_mlx_window(fdf))
		return (mlx_free(fdf), free(fdf), EXIT_FAILURE);
	fdf_draw(fdf, 0, 0);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	set_hooks(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
