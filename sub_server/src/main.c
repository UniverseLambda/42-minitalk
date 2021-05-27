#include <server.h>

#include <unistd.h>

#include <utils.h>

int	main(void)
{
	pid_t	pid;

	ft_putstr_fd("Initializing the server, please wait...\n", STDOUT_FILENO);
	if (!setup_server())
	{
		ft_putstr_fd("Oops. An error occured.\n", STDERR_FILENO);
		return (1);
	}
	pid = getpid();
	ft_putstr_fd("Here we go!\n", STDOUT_FILENO);
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
		sleep(0);
	return (0);
}
