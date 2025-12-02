/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:49:11 by gaeducas          #+#    #+#             */
/*   Updated: 2025/11/28 13:31:59 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include "boolean.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_signal(int, void *, t_bool);
# define sa .sa_flags = SA_SIGINFO

#endif