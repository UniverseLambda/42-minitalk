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

OBJS := src/ft_putchar_fd.o \
		src/ft_putnbr_fd.o \
		src/ft_putstr_fd.o \
		src/ft_atoi.o \
		src/char_page.o \
		src/char_page_pages0.o \
		src/char_page_pages1.o

INCLUDES := inc/char_pages.h \
			inc/utils.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
