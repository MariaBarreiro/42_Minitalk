#include "../../includes/minitalk.h"
#include <signal.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	action;

	server_pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_handler;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putstr_fd("\n", 1);

	while (1)
		pause();

	return (0);
}
