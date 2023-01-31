/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:39 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/27 13:18:53 by otokluog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>

char		*ft_uitoa(unsigned int a);

int			ft_atoi(const char *str);
int			ft_printf(const char *str, ...);
int			ft_putchar(int c);
int			ft_putchar_s(char *c);
int			ft_putchar_u(unsigned int a);
int			ft_putchar_d(int a);
int			ft_putchar_p(unsigned long long a);
void		ft_puthex(unsigned long long a);
int			ft_putchar_x(unsigned int x, int c);

#endif
