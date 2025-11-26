/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:44 by gaeducas          #+#    #+#             */
/*   Updated: 2025/11/26 13:30:32 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *signal_handler, void *use_siginfo)
{
	exit(0);
}

int	main(void)
{
	ft_printf("%d", "✅ Received SIGINT !\n", getpid());
	ft_signal(SIGUSR1, signal_handler, 1);
	ft_signal(SIGUSR2, signal_handler, 1);
	while (1)
	{
		pause();
	}
}
