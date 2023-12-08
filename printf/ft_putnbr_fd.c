/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:35:24 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/19 18:34:04 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(long long n, int fd)
{
	char	a;
	int		i;

	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		i++;
		n = (n * (-1));
	}
	if (n < 10)
	{
		a = n + '0';
		write(fd, &a, 1);
		i++;
	}
	else
	{
		i = i + ft_putnbr_fd((n / 10), fd);
		i = i + ft_putnbr_fd((n % 10), fd);
	}
	return (i);
}
