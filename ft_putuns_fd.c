/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:24:50 by oimzilen          #+#    #+#             */
/*   Updated: 2024/11/17 22:08:31 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putuns_fd((n / 10), fd);
		count += ft_putuns_fd((n % 10), fd);
	}
	else
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
