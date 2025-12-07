/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:44 by gaeducas          #+#    #+#             */
/*   Updated: 2025/12/07 18:34:49 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (signum == SIGUSR1)
		ft_printf("0");
	else if (signum == SIGUSR2)
		ft_printf("1");
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%s: %d\n", "✅ PID Received ", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "\n", 1);
	while (1)
		pause();
	write(1, "\n", 1);
}
