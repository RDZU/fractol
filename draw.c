/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:17:39 by razamora          #+#    #+#             */
/*   Updated: 2024/07/05 21:54:44 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_color(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_pixels_ptr + offset) = color;
}

void	ft_julia(int x, int y, t_windows *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	c.real = fract->real;
	c.imaginary = fract->imaginary;
	z.real = (scale(x, -2, +2, WIDTH) * (1 / fract->zoom)) + fract->move_x;
	z.imaginary = (scale(y, +2, -2, \
	HEIGHT) * (1 / fract->zoom)) + fract->move_y;
	while (i < fract->iterations)
	{
		z = ft_calculate_complex(z.real, z.imaginary, c.real, c.imaginary);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 4)
		{
			color = scale(i, BLUE, RED, fract->iterations);
			ft_color(x, y, &fract->img, color);
			return ;
		}
		++i;
	}
	ft_color(x, y, &fract->img, WHITE);
}

void	ft_mandelbrot(int x, int y, t_windows *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = 0.0;
	z.imaginary = 0.0;
	c.real = (scale(x, -2, +2, WIDTH) * (1 / fract->zoom)) + fract->move_x;
	c.imaginary = (scale(y, +2, -2, \
	HEIGHT) * (1 / fract->zoom)) + fract->move_y;
	while (i < fract->iterations)
	{
		z = ft_calculate_complex(z.real, z.imaginary, c.real, c.imaginary);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > 4)
		{
			color = scale (i, YELLOW, ORANGE, fract->iterations);
			ft_color(x, y, &fract->img, color);
			return ;
		}
		i++;
	}
	ft_color(x, y, &fract->img, FUCSIA);
}
