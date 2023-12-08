/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:06:43 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/20 14:11:58 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			i = i + ft_evaluate_one(str, arg);
			i = i + ft_evaluate_two(str, arg);
		}
		else
		{
			ft_putchar_fd(str[0], 1);
			i++;
		}
		str++;
	}
	va_end(arg);
	return (i);
}
