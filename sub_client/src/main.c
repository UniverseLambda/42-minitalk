#include <unistd.h>
#include <signal.h>

#include <utils.h>
#include <char_page.h>

int	validate_str(char *message);

static void	usage(char *pgm_name)
{
	ft_putstr_fd("USAGE: ", STDOUT_FILENO);
	ft_putstr_fd(pgm_name, STDOUT_FILENO);
	ft_putstr_fd(" <server PID> <string to send>\n", STDOUT_FILENO);
}

static int	print_char(pid_t srv_pid, char c)
{
	size_t	i;
	int		kret;

	i = 0;
	while (i < 4)
	{
		if (((c >> i) & 0x01) == 0)
			kret = kill(srv_pid, SIGUSR1);
		else
			kret = kill(srv_pid, SIGUSR2);
		usleep(500);
		if (kret != 0)
			return (0);
		++i;
	}
	return (1);
}

static int	print_str(pid_t pid, const char *str)
{
	size_t	i;
	uint8_t	page;
	uint8_t	next_page;
	char	charid;

	i = 0;
	page = 0;
	while (str[i])
	{
		charid = conv_char(str[i], &next_page);
		if (next_page != page)
		{
			page = next_page;
			if (!print_char(pid, 0xFF) || !print_char(pid, page))
				return (0);
		}
		if (!print_char(pid, charid))
			return (0);
		++i;
	}
	return (print_char(pid, 0xFF) && print_char(pid, 0x00));
}

static int	parse_args(char *argv[], pid_t *pid, char **message)
{
	pid_t	tmp;

	tmp = ft_atoi(argv[1]);
	if (tmp <= 1)
	{
		ft_putstr_fd("Invalid PID\n", STDERR_FILENO);
		return (0);
	}
	*pid = tmp;
	*message = argv[2];
	return (1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;

	if (argc < 3)
	{
		ft_putstr_fd("Missing argument\n", STDERR_FILENO);
		usage(argv[0]);
		return (1);
	}
	if (argc > 3)
	{
		ft_putstr_fd("Too many argument\n", STDERR_FILENO);
		usage(argv[0]);
		return (2);
	}
	if (!parse_args(argv, &pid, &message))
		return (3);
	if (!validate_str(message))
		return (4);
	if (!print_str(pid, message))
	{
		ft_putstr_fd("Communication error\n", STDERR_FILENO);
		return (5);
	}
	return (0);
}
