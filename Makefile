##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the libmy
##

CC = gcc

RM = rm -f

SRC =   my_ls.c \
	flag_d.c \
	flag_l.c \
	flag_maj_l_1.c \
	flag_maj_l_2.c \
	without_flag.c \

OBJ = $(SRC:.c=.o)

NAME = my_ls

all     :       $(NAME)

$(NAME) :       $(OBJ)
	$(MAKE) -C ./libmy
	$(CC) $(OBJ) -o $(NAME) -L ./libmy -l my
clean:
	$(RM) $(OBJ)

fclean: clean
	make -C libmy fclean
	$(RM) $(NAME)

re: fclean all

.PHONY : all fclean clean re
