/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:32 by razamora          #+#    #+#             */
/*   Updated: 2024/07/05 21:59:08 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# define WIDTH 700
# define HEIGHT 700
# define WHITE 0xFFFFFF
# define RED 0xFF0066
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define ORANGE 0xFF9933
# define FUCSIA 0xF600CA

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_windows
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	x;
	double	y;
	double	real;
	double	imaginary;
	t_img	img;
	double	escape;
	int		iterations;
	double	move_x;
	double	move_y;
	double	zoom;
	char	*type_fract;
}	t_windows;

void		ft_putstr(char *s);
void		ft_menu(void);
t_complex	num_complex(double x, double y);
int			ft_iterative_power(int nb, int power);
double		ft_atof(const char *str);
double		scale(double x, double a, double b, double max);
t_complex	ft_calculate_complex(double zx, double zy, double cx, double cy);
int			ft_strcmp(const char *s1, const char *s2);
int			close_handler(t_windows *fract);
void		handle_mlx_image_error(void *mlx, void *win);
void		ft_julia(int x, int y, t_windows *fract);
void		ft_mandelbrot(int x, int y, t_windows *fract);
void		render(struct s_windows *fract);
int			handle_keypress(int keysym, t_windows *fract);
int			mouse_handle(int button, int x, int y, t_windows *fract);
void		ft_event(t_windows *fract);
void		fract_up(t_windows *fract);
void		ft_check_parameters_fractal(int argc, char **argv);
void		ft_is_numeric(char *str);
void		ft_checker_julia(char *arg_real, char *arg_imagi);
void		ft_msm_parameters(char *s);

#endif