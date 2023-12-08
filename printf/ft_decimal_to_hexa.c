/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:20:42 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/20 14:24:09 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal_to_hexa(const char *str, unsigned long long num)
{
	char	*hexa_base;
	int		i;

	if (*str == 'x' || *str == 'p')
		hexa_base = HEXA_LOWER;
	else
		hexa_base = HEXA_UPPER;
	i = 0;
	if (num < 0)
	{
		i = i + ft_putchar_fd('-', 1);
		num = -num;
	}
	if (num < 16)
	{
		write(1, &hexa_base[num], 1);
		i++;
	}
	else
	{
		i = i + ft_decimal_to_hexa(str, num / 16);
		write (1, &hexa_base[num % 16], 1);
		i++;
	}
	return (i);
}
