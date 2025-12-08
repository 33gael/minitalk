/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:44 by gaeducas          #+#    #+#             */
/*   Updated: 2025/12/08 13:32:04 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit_index = 0;
	static char	current_char = 0;
	pid_t		client_pid;

	(void)ucontext;
	client_pid = info->si_pid;
	current_char <<= 1;
	if (signum == SIGUSR2)
		current_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char != '\0')
			write(1, &current_char, 1);
		else
			write(1, "\n", 1);
		// kill(client_pid, SIGUSR1);
		current_char = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%s: %d\n", "✅ PID Received ", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
