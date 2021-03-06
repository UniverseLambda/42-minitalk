.DEFAULT: all
.PHONY: all clean fclean re common client server
.SUFFIXES: .c .o

NAME_CLIENT := client
NAME_SERVER := server
NAME_COMMON := libcommon.a

CP ?= cp
RM ?= rm
MAKE ?= make

DIR_INC_COMMON := ../sub_common/inc
LIB_COMMON := ../sub_common/$(NAME_COMMON)

all: common $(NAME_CLIENT) $(NAME_SERVER)

common:
	$(MAKE) -C sub_common/ $(NAME_COMMON)

$(NAME_CLIENT):
	$(MAKE) -C sub_client/ $(NAME_CLIENT) DIR_INC_COMMON=$(DIR_INC_COMMON) LIB_COMMON=$(LIB_COMMON)
	$(CP) sub_client/$(NAME_CLIENT) ./$(NAME_CLIENT)

$(NAME_SERVER):
	$(MAKE) -C sub_server/ $(NAME_SERVER) DIR_INC_COMMON=$(DIR_INC_COMMON) LIB_COMMON=$(LIB_COMMON)
	$(CP) sub_server/$(NAME_SERVER) ./$(NAME_SERVER)

clean:
	$(MAKE) -C sub_common/ clean
	$(MAKE) -C sub_client/ clean
	$(MAKE) -C sub_server/ clean

fclean:
	$(MAKE) -C sub_common/ fclean
	$(MAKE) -C sub_client fclean
	$(MAKE) -C sub_server/ fclean
	$(RM) -rf $(NAME_CLIENT)
	$(RM) -rf $(NAME_SERVER)


re:
	$(MAKE) -C sub_common/ re
	$(MAKE) -C sub_client re
	$(MAKE) -C sub_server/ re
	$(RM) -rf $(NAME_CLIENT)
	$(RM) -rf $(NAME_SERVER)
