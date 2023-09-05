/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unb_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:16:42 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/14 15:51:40 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unb_printf(unsigned int nb)
{
	if (nb > 9)
	{
		ft_unb_printf(nb / 10);
		ft_unb_printf(nb % 10);
	}
	else
		ft_char_printf(nb + '0');
	return (ft_len(nb));
}
