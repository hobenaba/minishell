/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:43 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/18 13:13:37 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress_printf(unsigned long n)
{
	int	i;

	i = 0;
	write (1, "0x", 2);
	i = ft_hexa_printf(n, 'x');
	return (i + 2);
}
