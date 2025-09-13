#include "../../includes/minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;

	if (fd < 0)
		return ;

	while(s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}
