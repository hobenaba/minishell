/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:17:37 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/26 21:42:03 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	lexer_init(t_lexer *lexer)
{
	lexer -> base = 0;
	lexer -> her = 0;
	lexer -> her2 = 0;
	lexer -> index = 0;
	lexer -> str = NULL;
	lexer -> base2 = lexer -> base;
	lexer -> c = 0;
	lexer -> a = 0;
	lexer -> e = 0;
}
