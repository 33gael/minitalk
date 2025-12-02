/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:40 by gaeducas          #+#    #+#             */
/*   Updated: 2025/12/02 16:40:54 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int pid;
	char *str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		// envoyer le message
	}
	else
		ft_printf("\nPlease write more than 1 character");