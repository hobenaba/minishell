/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:19:44 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/17 16:55:58 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mycopy(char *into, char *from)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (from[i])
	{
		into[j] = from[i];
		j++;
		i++;
	}
	return (into);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		j;

	j = 0;
	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	p = malloc((ft_strlen(s1) + (ft_strlen(s2) + 1)) * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		ft_mycopy(p, s1);
		ft_mycopy(p + ft_strlen(s1), s2);
		p[j + ft_strlen(s1) + ft_strlen(s2)] = '\0';
	}
	return (free(s2), free(s1), p);
}
