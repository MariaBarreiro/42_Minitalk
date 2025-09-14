/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:59:16 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/14 18:14:28 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	main(int ac, char **av)
{
	size_t				i;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	if (ac == 3)
	{
		i = 0;
		if (check_null(av[2]) == true)
			return (1);
		while (av[1][i])
		{
			if (check_digits(av[1][i]) == false)
				return (ft_putstr_fd("[Pid_Server] Must be numeric.\n", 2), 1);
			i++;
		}
		send_message(ft_atoi(av[1]), av[2]);
	}
	else
		return (ft_putstr_fd("./client [Pid_Server] [Message]\n", 2), 1);
	while (1)
		pause();
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (sig == SIGUSR2)
		exit (EXIT_SUCCESS);
	if (sig == SIGUSR1)
		send_message(info->si_pid, NULL);
}

void	send_message(int pid, char *message)
{
	static int	i;
	static char	*temp_message;
	static int	bit;

	i = 0;
	bit = 0;
	if (message != NULL)
		temp_message = message;
	if (temp_message[i] != 0)
	{
		send_char(temp_message[i], bit, pid);
		if (++bit == 8)
		{
			bit = 0;
			i++;
		}
	}
	else
	{
		if (bit < 8)
		{
			kill(pid, SIGUSR2);
			bit++;
		}
	}
}

void	send_char(char c, int current_bit, int pid)
{
	if (((c >> current_bit) & 1) == 1)
		kill(pid, SIGUSR1);
	else
		kill (pid, SIGUSR2);
}
