/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:10 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/06 22:14:53 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s;

	s = ft_strlen(src);
	if ((dst == NULL) && dstsize == 0)
		return (s);
	j = ft_strlen(dst);
	i = 0;
	if (dstsize < j)
	{
		if (!dst && !src)
			return (0);
		else if (!src)
			return (dstsize);
		return (s + dstsize);
	}
	s += j;
	while (j + 1 < dstsize && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (s);
}
