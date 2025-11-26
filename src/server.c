/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:44 by gaeducas          #+#    #+#             */
/*   Updated: 2025/11/25 18:08:15 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	ft_printf("%d", "Received SIGINT !\n", signum);
	exit(0);
}

int	main(void)
{
	ft_printf("%d", getgid());
}
