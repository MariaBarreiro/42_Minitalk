#include "../../includes/minitalk.h"
#include <signal.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	action;

	server_pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handle_sig;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

}
