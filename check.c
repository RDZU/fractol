/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:56:18 by razamora          #+#    #+#             */
/*   Updated: 2024/07/05 21:59:48 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_is_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str < 48 || *str > 57)
		ft_msm_parameters("Error en los parametros");
	while (*str != '\0')
	{
		if ((*str < 48 || *str > 57) && *str != '.')
			ft_msm_parameters("Error en los parametros");
		str++;
	}
}

void	ft_checker_julia(char *arg_real, char *arg_imagi)
{
	ft_is_numeric(arg_real);
	ft_is_numeric(arg_imagi);
}

void	ft_msm_parameters(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
	ft_menu();
	exit(1);
}
