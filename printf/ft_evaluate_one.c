/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:21:07 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/20 14:11:18 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_evaluate_one(char const *str, va_list arg)
{
	char	*aux;
	int		i;

	if (*str == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (*str == 's')
	{
		aux = va_arg(arg, char *);
		if (aux == NULL)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(aux, 1);
		return (ft_strlen(aux));
	}
	if (*str == 'd' || *str == 'i')
	{
		aux = ft_itoa(va_arg(arg, int));
		ft_putstr_fd(aux, 1);
		i = ft_strlen(aux);
		free(aux);
		return (i);
	}
	return (0);
}
