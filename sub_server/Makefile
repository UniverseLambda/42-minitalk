.DEFAULT: all
.PHONY: all clean fclean re
.SUFFIXES: .c .o

NAME := server

CC ?= gcc
RM ?= rm
LD := $(CC)

CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Iinc -I$(DIR_INC_COMMON) -g3
LDFLAGS := $(LDFLAGS) -g3

OBJS := src/main.o \
		src/server.o

INCLUDES := inc/server.h

all: $(NAME) $(LIB_COMMON)

$(NAME): $(OBJS) $(LIB_COMMON)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIB_COMMON)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
