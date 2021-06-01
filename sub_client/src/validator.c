#include <utils.h>

#include <unistd.h>

int	validate_str(char *message)
{
	while (*message)
	{
		if (*message < 0x20 || *message > 126)
		{
			ft_putstr_fd("Error: non-printable character\n", STDERR_FILENO);
			return (0);
		}
		++message;
	}
	return (1);
}

int	validate_pid(char *pidstr)
{
	if (*pidstr == '+')
		++pidstr;
	while (*pidstr)
	{
		if (*pidstr > '9' || *pidstr < '0')
			return (0);
		++pidstr;
	}
	return (1);
}
