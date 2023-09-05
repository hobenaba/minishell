/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:01:22 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/25 12:25:34 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_lstnew(char *value, int type, int arten)
{
	t_token	*p;

	p = malloc(sizeof (t_token));
	if (!p)
		return (NULL);
	p -> value = value;
	p ->type = type;
	p -> arten = arten;
	p -> next = NULL;
	return (p);
}

void	ft_lstaddback(t_token **lst, t_token *new)
{
	t_token	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	if (!p)
		return ;
	while (p-> next)
		p = p -> next;
	p -> next = new;
}

t_data2	*lstnew4(char *value, int type, int amg)
{
	t_data2	*p;

	p = malloc(sizeof (t_data2));
	if (!p)
		return (NULL);
	p -> value = value;
	p ->type = type;
	p -> amg = amg;
	p -> next = NULL;
	return (p);
}

void	addback4(t_data2 **lst, t_data2 *new)
{
	t_data2	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	if (!p)
		return ;
	while (p-> next)
		p = p -> next;
	p -> next = new;
}
