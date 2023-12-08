/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:07:27 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/20 14:08:48 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_evaluate_two(char const *str, va_list arg)
{
	if (*str == 'u')
		return (ft_putnbr_fd(va_arg(arg, unsigned int), 1));
	if (*str == 'x' || *str == 'X')
		return (ft_decimal_to_hexa(str, va_arg(arg, unsigned int)));
	if (*str == '%')
		return (ft_putchar_fd('%', 1));
	if (*str == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_decimal_to_hexa(str, va_arg(arg, unsigned long long)) + 2);
	}
	return (0);
}
