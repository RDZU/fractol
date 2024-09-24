/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:01:23 by razamora          #+#    #+#             */
/*   Updated: 2024/07/05 20:41:31 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_event(t_windows *fract)
{
	mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, handle_keypress, fract);
	mlx_hook(fract->win_ptr, ButtonPress, ButtonPressMask, mouse_handle, fract);
	mlx_hook(fract->win_ptr, DestroyNotify, StructureNotifyMask, \
	close_handler, fract);
}

int	close_handler(t_windows *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->img.img_ptr);
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	mlx_destroy_display(fract->mlx_ptr);
	free(fract->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int keysym, t_windows *fract)
{
	if (keysym == XK_Escape)
		close_handler(fract);
	if (keysym == XK_Left)
		fract->move_x += 0.05 * (1 / fract->zoom);
	if (keysym == XK_Up)
		fract->move_y -= 0.05 * (1 / fract->zoom);
	if (keysym == XK_Right)
		fract->move_x -= 0.05 * (1 / fract->zoom);
	if (keysym == XK_Down)
		fract->move_y += 0.05 * (1 / fract->zoom);
	if (keysym == 65451)
		fract->iterations += 1;
	if (keysym == 65453)
		fract->iterations -= 1;
	render(fract);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_windows *fract)
{
	if (button == 4)
		fract->zoom *= 1.7;
	if (button == 5 && fract->zoom >= 0.008100)
		fract->zoom *= 0.3;
	if (fract->zoom >= 0.008100)
	{
		fract->move_x += (scale(x - fract->move_x, -2, 2, \
		WIDTH - fract->move_x)) * (1 / fract->zoom);
		fract->move_y += (scale(y - fract->move_y, 2, -2, \
		HEIGHT - fract->move_y)) * (1 / fract->zoom);
	}
	render(fract);
	return (0);
}
