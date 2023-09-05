/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:13:58 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/06 23:10:52 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	if (len == 0)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = len - 1;
	if (dst1 > src1)
	{
		while (i > 0)
		{
			dst1[i] = src1[i];
			i--;
		}
		dst1[0] = src1[0];
	}
	else if (dst1 == src1)
		return (dst);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
