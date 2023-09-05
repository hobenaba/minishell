/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:55:49 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/02 15:48:32 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	c = (char)c;
	if (c == '\0')
	{
		str = str + ft_strlen(str);
		return (str);
	}
	while (str[i])
	{
		if (str[i] == c)
		{
			str = str + i;
			return (str);
		}
		i++;
	}
	return (NULL);
}
