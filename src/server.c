/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:44 by gaeducas          #+#    #+#             */
/*   Updated: 2025/12/11 16:15:37 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_msg = NULL;

static int	append_char_to_msg(char c)
{
	char	tmp_c[2];
	char	*old_msg;

	tmp_c[0] = c;
	tmp_c[1] = '\0';
	if (g_msg == NULL)
		g_msg = ft_calloc(1, sizeof(char));
	if (g_msg == NULL)
		return (0);
	old_msg = g_msg;
	g_msg = ft_strjoin(old_msg, tmp_c);
	if (old_msg && g_msg)
		free(old_msg);
	if (!g_msg)
		return (0);
	return (1);
}

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit_index = 0;
	static char	current_char = 0;

	(void)info;
	(void)ucontext;
	current_char = (current_char << 1) | (signum == SIGUSR2);
	if (++bit_index == 8)
	{
		if (current_char == '\0')
		{
			if (g_msg != NULL)
			{
				ft_printf("%s\n", g_msg);
				free(g_msg);
				g_msg = NULL;
			}
		}
		else if (!append_char_to_msg(current_char))
			ft_printf("Error of memory allocation\n");
		current_char = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_msg = NULL;
	ft_printf("%s: %d\n", "✅ PID Received ", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
