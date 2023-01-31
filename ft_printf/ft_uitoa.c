/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:06:46 by otokluog          #+#    #+#             */
/*   Updated: 2022/02/25 18:08:48 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_size(unsigned int x)
{
	unsigned int	i;

	i = 0;
	while (x)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int a)
{
	char			*s;
	unsigned int	size;

	size = ft_size(a);
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	s[size--] = '\0';
	while (a)
	{
		s[size] = (a % 10) + '0';
		a = a / 10;
		size--;
	}
	return (s);
}
