/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:28:57 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/14 15:36:07 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_printf(unsigned long n, char c)
{
	int		i;
	char	*h;

	i = 0;
	if (c == 'x')
		h = "0123456789abcdef";
	else
		h = "0123456789ABCDEF";
	if (n >= 16)
	{
		i += ft_hexa_printf(n / 16, c);
		i += ft_hexa_printf(n % 16, c);
	}
	else
		i += ft_char_printf(h[n % 16]);
	return (i);
}
