/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** function that print repository and files
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "include/my.h"
#include "my_ls.h"
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "libmy/my_ls/my_printf.h" 

static int my_ls(int ac, char **av)
{
	char *array = malloc(sizeof(char)*340);
	
	if (av[1][0] == '-' && av[1][1] == 'l') {
		flag_l(ac, av);
	}
	if (av[1][0] == '-' && av[1][1] == 'd') {
		flag_d(ac, av);
	}	
	if (av[1][0] == '-' && av[1][1] == 'R' && my_strlen(av[2]) < 3) {
		flag_l_maj_1(av, array, 0, 1 , 1);
	}		
	if (av[1][0] == '-' && av[1][1] == 'R' && my_strlen(av[2]) > 3) {
		flag_maj_l_2(av, array, 0, 1 , 1);
	} else {
		without_flag(ac, av);
	}
	return (0);
}

int main(int ac, char **av)
{
	my_ls(ac, av);
}
