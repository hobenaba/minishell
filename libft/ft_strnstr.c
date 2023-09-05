/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:59:46 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/06 19:30:58 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	while (haystack[i] && needle[j] && i < len)
	{
		if (haystack[i] != needle[j])
		{
			i -= j;
			j = 0;
		}
		else if (haystack[i] == needle[j])
			j++;
		i++;
	}
	if (needle[j] != '\0')
		return (0);
	return ((char *)&haystack[i - j]);
}
