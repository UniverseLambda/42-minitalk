#include <signal.h>

#include <server.h>
#include <unistd.h>

#include <utils.h>
#include <char_page.h>

static t_runtime	*rt_ptr(void)
{
	static t_runtime	rt;

	return (&rt);
}

static void	server_flush(void)
{
	t_runtime	*rt;

	rt = rt_ptr();
	if (rt->buffidx == 0)
		return ;
	write(STDOUT_FILENO, rt->buffer, rt->buffidx);
	rt->buffidx = 0;
}

static void	admit_char(t_runtime *rt)
{
	char	c;

	c = rt->partial_char;
	rt->bitidx = 0;
	rt->partial_char = 0;
	if (rt->expect_page)
	{
		rt->expect_page = 0;
		if ((c & 0x0F) == 0)
		{
			server_flush();
			ft_putchar_fd('\n', STDOUT_FILENO);
			return ;
		}
		rt->page = c & 0x0F;
		return ;
	}
	if ((c & 0x0F) == 0x0F)
	{
		rt->expect_page = 1;
		return ;
	}
	rt->buffer[rt->buffidx++] = get_char(rt->page, c & 0x0F);
	if (rt->buffidx >= sizeof(rt->buffer))
		server_flush();
}

static void	sigreceiver(int sig)
{
	t_runtime	*rt;
	uint8_t		b;

	rt = rt_ptr();
	if (sig == SIGUSR1)
		b = 0;
	else
		b = 1;
	rt->partial_char |= b << (rt->bitidx++);
	if (rt->bitidx >= 4)
		admit_char(rt);
}

int	setup_server(void)
{
	void		*sigret;
	t_runtime	*rt;

	rt = rt_ptr();
	rt->bitidx = 0;
	rt->buffidx = 0;
	rt->page = 0;
	rt->expect_page = 0;
	rt->partial_char = 0;
	sigret = signal(SIGUSR1, sigreceiver);
	if (sigret == SIG_ERR)
		return (0);
	sigret = signal(SIGUSR2, sigreceiver);
	if (sigret == SIG_ERR)
		return (0);
	return (1);
}
