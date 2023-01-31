/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:03:31 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/26 16:59:42 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_count(long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
		a = -a;
	while (a)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

int	ft_putchar_d(int n)
{
	int	len;

	len = ft_count(n);
	if (n == -2147483648)
	{
		len += ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		n = n * -1;
		len += ft_putchar('-');
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return (len);
	}
	else
	{
		ft_putchar_d(n / 10);
	}
	ft_putchar_d(n % 10);
	return (len);
}
