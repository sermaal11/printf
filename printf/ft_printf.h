/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:57:45 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/20 14:19:31 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

int		ft_decimal_to_hexa(const char *str, unsigned long long num);
int		ft_evaluate_one(char const *str, va_list arg);
int		ft_evaluate_two(char const *str, va_list arg);
int		ft_printf(char const *str, ...);
char	*ft_itoa(int n);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(long long n, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
#endif
