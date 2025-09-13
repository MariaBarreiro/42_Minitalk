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

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd ((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
	else
	{
		nb += '0';
		write (fd, &nb, 1);
	}
}
