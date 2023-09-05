/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:21:26 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 15:22:06 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_add_arr(t_env *en, int en_len, int val_len)
{
	int		j;
	int		l;
	char	*add;

	en_len = ft_strlen(en->env);
	val_len = ft_strlen(en->value);
	add = (char *)malloc((en_len + val_len + 2) * sizeof(char *));
	if (!add)
		return (NULL);
	j = 0;
	while (j < en_len)
	{
		add[j] = en->env[j];
		j++;
	}
	add[j++] = '=';
	l = 0;
	while (l < val_len)
	{
		add[j++] = en->value[l];
		l++;
	}
	add[j] = '\0';
	return (add);
}

typedef struct s_tabenv
{
	int		en_lenght;
	int		val_lenght;
	int		i;
}	t_tabenv;

char	**create_env_arr(int size)
{
	char		**arr;
	char		*add;
	t_env		*en;
	t_tabenv	tab;

	en = g_var.list;
	tab.i = 0;
	tab.en_lenght = 0;
	tab.val_lenght = 0;
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (!arr)
		return (printf("minishell: Memory allocation failed\n"), NULL);
	while (en)
	{
		add = ft_add_arr(en, tab.en_lenght, tab.val_lenght);
		if (!add)
			return (printf("minishell: Memory allocation failed\n"),
				ft_free(arr), free(add), NULL);
		arr[tab.i] = add;
		en = en->next;
		tab.i++;
	}
	arr[tab.i] = NULL;
	return (arr);
}
