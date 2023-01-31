/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:28:15 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/26 15:32:40 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_count(unsigned long long a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

int	ft_putchar_p(unsigned long long a)
{
	int	len;

	len = 0;
	write (1, "0x", 2);
	len += 2;
	if (a == 0)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	else
		ft_puthex(a);
	len += ft_count(a);
	return (len);
}
