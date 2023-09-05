/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:22:36 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/02 15:57:06 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	c = (char)c;
	str = (char *)s;
	i = ft_strlen(s) - 1;
	if (c == '\0')
	{
		str = str + ft_strlen(str);
		return (str);
	}
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			str = str + i;
			return (str);
		}
		i--;
	}
	return (NULL);
}
