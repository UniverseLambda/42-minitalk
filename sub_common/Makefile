.DEFAULT: all
.PHONY: all clean fclean re
.SUFFIXES: .c .o

NAME := libcommon.a

CC ?= gcc
RM ?= rm
AR := ar

CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Iinc -g3
ARFLAGS := rcs

BUILD_TYPE := release

OBJS := src/ft_putchar_fd.o \
		src/ft_putnbr_fd.o \
		src/ft_putstr_fd.o \
		src/ft_atoi.o \
		src/char_page.o \
		src/char_page_pages0.o \
		src/char_page_pages1.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

debug:	BUILD_TYPE := debug
debug:	all
