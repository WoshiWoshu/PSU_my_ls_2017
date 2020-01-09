##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the libmy
##

CC = gcc
CFLAGS = -g
RM = rm -f

default: all

all:my_ls

my_ls:my_ls.c
	$(CC) $(CFLAGS) -o my_ls my_ls.c libmy.a
clean:
	$(RM) my_ls
