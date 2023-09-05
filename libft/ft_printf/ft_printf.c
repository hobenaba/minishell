/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:10:21 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/16 12:28:24 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_my(char c, va_list p)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_char_printf(va_arg(p, int));
	if (c == 'd' || c == 'i')
		i += ft_nb_printf(va_arg(p, int));
	if (c == 's')
		i += ft_str_printf(va_arg(p, char *));
	if (c == 'u')
		i += ft_unb_printf(va_arg(p, unsigned));
	if (c == 'p')
		i += ft_adress_printf(va_arg(p, unsigned long));
	if (c == 'x' || c == 'X')
		i += ft_hexa_printf(va_arg(p, unsigned), c);
	if (c == '%')
		i += ft_char_printf(c);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	p;

	len = 0;
	i = 0;
	va_start(p, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += check_my(format[i + 1], p);
			i++;
		}
		else
			len += ft_char_printf(format[i]);
		if (format[i])
			i++;
	}
	va_end (p);
	return (len);
}
