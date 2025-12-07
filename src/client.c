/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:40 by gaeducas          #+#    #+#             */
/*   Updated: 2025/12/07 11:42:23 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bit_to_char(pid_t server_pid, char c)
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

static void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		bit_to_char(server_pid, *str);
		str++;
	}
	bit_to_char(server_pid, '\n');
	bit_to_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t server_pid;
	char *str;

	if (argc != 3)
	{
		ft_printf("\nERROR");
		return (1);
	}
	send_string(server_pid, str);
	return (0);
}