/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:20:05 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/26 18:57:46 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	normal_word(char *input, int start)
{
	int	j;

	j = 0;
	while (input[start] && ft_strchr(" $|><\'\"", input[start]) == NULL)
	{
		j++;
		start++;
	}
	return (j);
}

int	quotes_word(char *input, int start, int base)
{
	char	c;
	int		j;

	j = 0;
	if (base == 1)
		c = '\'';
	else
		c = '\"';
	while (input[start] && input[start] != c)
	{
		if (base == 2 && input[start] == '$')
			break ;
		j++;
		start++;
	}
	return (j);
}

int	env_word(char *input, int start)
{
	int	j;

	j = 0;
	while (input[start] && ((ft_isalnum(input[start]) == 1)
			|| input[start] == '_'))
	{
		j++;
		start++;
	}
	return (j);
}
