/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:29:51 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/15 08:38:03 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_printf(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		ft_char_printf('-');
		ft_nb_printf(n * -1);
	}
	else if (n > 9)
	{
		ft_nb_printf(n / 10);
		ft_nb_printf(n % 10);
	}
	else
		ft_char_printf(n + '0');
	return (ft_len(n));
}
