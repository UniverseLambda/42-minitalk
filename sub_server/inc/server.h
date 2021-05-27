// FIXME: 42 header

#ifndef SERVER_H
# define SERVER_H

#include <stdint.h>
#include <stddef.h>

typedef struct s_runtime
{
	char	buffer[1024];
	size_t	buffidx;

	char	partial_char;
	uint8_t	bitidx;

	uint8_t	page;
	int		expect_page;
}	t_runtime;

int	setup_server();

#endif // SERVER_H
