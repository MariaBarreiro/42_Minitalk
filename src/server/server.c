/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:04:47 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/14 19:14:48 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	action;

	server_pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handle_sig;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putstr_fd("\n", 1);

	while (1)
		pause();

	return (0);
}

void	handle_sig(int sig, siginfo_t *info, void *ctx)
{
	static int		current_bit;
	static int		current_char;
	static char		*message;

	(void) ctx;
	if (sig == SIGUSR1 || sig == SIGUSR2)
		if (sig == SIGUSR1)
			current_char = current_char | (1 << current_bit);
	current_bit++;
	if (current_bit == 8)
	{
		if (current_char == '\0')
		{
			ft_putstr_fd(message, 1);
			free(message);
			message = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		else
			message = add_char(message, current_char, info->si_pid);
		current_bit = 0;
		current_char = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
}

char	*add_char(char *initial_str, char char_to_add, int pid)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	i = 0;
	if (initial_str == NULL)
	{
		new_str = (char *)malloc(sizeof(char));
		new_str[0] = '\0';
		len = 0;
	}
	else
		len = ft_strlen(initial_str);
	new_str = (char *)malloc((len + 2) * sizeof(char));
	while (i < len)
	{
		new_str[i] = initial_str[i];
		i++;
	}
	new_str[i] = char_to_add;
	new_str[i + 1] = '\0';
	free (initial_str);
	kill(pid, SIGUSR1);
	return (new_str);
}
