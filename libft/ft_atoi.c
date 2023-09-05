/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:55 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/18 19:15:36 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_signe_res(const char *str, int *signe, unsigned long *res)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		*res = *res * 10 + *str - '0';
		str++;
	}
}

long	ft_atoi(const char *str)
{
	int				signe;
	unsigned long	res;

	signe = 1;
	res = 0;
	ft_signe_res(str, &signe, &res);
	if (signe > 0 && res == 9223372036854775807)
		return (2);
	if (signe < 0 && res == 9223372036854775807)
		return (3);
	if ((signe > 0 && res > 9223372036854775807)
		|| (signe < 0 && res > 9223372036854775807))
	{
		printf("minishell: exit: %s: numeric argument required\n", str);
		exit(255);
	}
	return (signe * res);
}
