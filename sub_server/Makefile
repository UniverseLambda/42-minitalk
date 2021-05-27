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

BUILD_TYPE := release

OBJS := src/main.o \
		src/server.o

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIB_COMMON)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

debug:	BUILD_TYPE := debug
debug:	all
