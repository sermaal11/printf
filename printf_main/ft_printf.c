/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:45:58 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/20 16:08:13 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
		i++;
	}
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;
	int		i;

	len = ft_strlen(str);
	copy = (char *)malloc(len + 1);
	i = 0;
	if (copy == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	get_num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	len = get_num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

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

int	ft_decimal_to_hexa(const char *str, unsigned long long num)
{
	char	*hexa_lower;
	char	*hexa_upper;
	char	*hexa_base;
	int		i;

	hexa_lower = "0123456789abcdef";
	hexa_upper = "0123456789ABCDEF";
	if (*str == 'x' || *str == 'p')
		hexa_base = hexa_lower;
	else
		hexa_base = hexa_upper;
	i = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		i++;
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

int	evaluate(char const *str, va_list arg)
{
	char	*aux;
	int		i;

	if (*str == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (*str == 's')
	{
		aux = va_arg(arg, char *);
		if (aux == NULL)
			return (ft_putstr_fd("(null)", 1));
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
			i = i + evaluate(str, arg);	
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

int	main(void)
{
	const char		*str0;
	char			*str1;
	int				n;
	unsigned int	u_i;
	int				x;
	int				X;
	char			*str2;
	char			j;

	str0 = "Sergio char: %c str: %s int_d: %d int_i %i uns_i %u hex_x %x hex_X %X percent %%c ptr %p ";
	str1 = "str";
	n = 27;
	u_i = 12;
	x = -1492;
	X = 1492;
	j = 'e';
	str2 = &j;
	printf("%d\n", ft_printf(str0, 'a', str1, n, n, u_i, x, X, str2));
	printf("%d\n", printf(str0, 'a', str1, n, n, u_i, x, X, str2));

	system("leaks -q a.out");
	return (0);
}
