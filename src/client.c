/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:40 by gaeducas          #+#    #+#             */
/*   Updated: 2025/12/08 16:55:11 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	char_to_bit(pid_t server_pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
	}
}

static void	send_string(pid_t server_pid, char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		char_to_bit(server_pid, *str);
		str++;
	}
	char_to_bit(server_pid, '\n');
	char_to_bit(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;

	str = argv[2];
	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("\nERROR");
		return (1);
	}
	send_string(server_pid, str);
	return (0);
}
