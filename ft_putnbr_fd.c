/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:52:20 by oimzilen          #+#    #+#             */
/*   Updated: 2024/11/17 22:08:10 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n > 9)
	{
		count += ft_putnbr_fd((n / 10), fd);
		count += ft_putnbr_fd((n % 10), fd);
	}
	else if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n *= -1;
		count += ft_putnbr_fd(n, fd);
	}
	else
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
