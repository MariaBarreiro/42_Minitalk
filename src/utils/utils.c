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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	check_null(char *str)
{
	if (str[0] == '\0')
		return (true);
	return (false);
}

bool	check_digits(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
