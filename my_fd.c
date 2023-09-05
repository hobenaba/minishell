/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:00:13 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/25 14:54:01 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	*my_fd(void)
{
	int	*myfd;

	myfd = malloc(sizeof(int) * 2);
	myfd[0] = dup(0);
	myfd[1] = dup(1);
	return (myfd);
}

void	update_fd(int *my_fd)
{
	dup2(my_fd[0], 0);
	dup2(my_fd[1], 1);
}

void	close_myfd_prog(int *myfd)
{
	close(myfd[0]);
	close(myfd[1]);
	free(myfd);
}
