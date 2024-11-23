/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:00:04 by oimzilen          #+#    #+#             */
/*   Updated: 2024/11/21 15:58:44 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	zero_case(int count, int fd)
{
	count += ft_putchar_fd('0', fd);
	return (count);
}

static int	hex_letters(char *buffer, int i, int upper, size_t rem)
{
	if (upper)
		buffer[i++] = 'A' + (rem - 10);
	else
		buffer[i++] = 'a' + (rem - 10);
	return (i);
}

int	ft_printhex_fd(size_t num, int upper, int fd)
{
	char			buffer[16];
	int				count;
	int				i;
	size_t			rem;

	rem = 0;
	count = 0;
	i = 0;
	if (num == 0)
		return (zero_case(count, fd));
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			buffer[i++] = (rem + '0');
		else
			i = hex_letters(buffer, i, upper, rem);
		num /= 16;
	}
	while (--i >= 0)
		count += ft_putchar_fd(buffer[i], fd);
	return (count);
}
