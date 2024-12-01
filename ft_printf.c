/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:33:58 by oimzilen          #+#    #+#             */
/*   Updated: 2024/12/01 23:25:33 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_args(va_list ap, char specefier, int fd)
{
	int	count;

	count = 0;
	if (specefier == 'c')
		count += ft_putchar_fd(va_arg(ap, int), fd);
	else if (specefier == 's')
		count += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (specefier == 'd' || specefier == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);  // i 
	else if (specefier == 'u')
		count += ft_putuns_fd(va_arg(ap, unsigned int), fd);
	else if (specefier == 'x')
		count += ft_printhex_fd(va_arg(ap, unsigned int), 0, fd);
	else if (specefier == 'X')
		count += ft_printhex_fd(va_arg(ap, unsigned int), 1, fd);
	else if (specefier == 'p')
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_printhex_fd(va_arg(ap, size_t), 0, fd);
	}
	else if (specefier == '%')
		count += ft_putchar_fd('%', fd);
	else
		ft_putstr_fd("(Error: Invalid specefier.)", fd);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	int		fd;
	va_list	ap;

	i = 0;
	count = 0;
	fd = 1;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (0);
			count += print_args(ap, format[i], fd);
		}
		else
			count += ft_putchar_fd(format[i], fd);
		i++;
	}
	va_end(ap);
	return (count);
}
