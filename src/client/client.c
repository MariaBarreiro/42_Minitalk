#include "../../includes/minitalk.h"
#include <signal.h>


int	main(int ac, char **av)
{
	size_t				i;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_handler;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);


}
