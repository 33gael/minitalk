/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:40 by gaeducas          #+#    #+#             */
/*   Updated: 2025/12/05 15:17:21 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_char(pid_t server_pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(500);
	}
	usleep(100);
}

int	main(int argc, char **argv)
{
	pid_t server_pid;
	char c;

	if (argc != 3)
	{
		ft_printf("\nPlease write more than 1 character");
	}
	bit_to_char(server_pid, c);
}