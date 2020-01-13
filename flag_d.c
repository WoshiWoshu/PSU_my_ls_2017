/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** flag_d
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
#include "include/my_printf.h"

int flag_d(int ac, char **av)
{
	DIR *rep = NULL;
	struct dirent *file = NULL;
	struct stat info;

	if (ac < 0) {
		my_printf("not enough argument or too much arguments");
		return(84);
	}
	rep = opendir(av[2]);
	if (rep == NULL) {
		perror("");
		return (84);
	}
	while ((file = readdir(rep)) != NULL) {
		if (strcmp(file->d_name, ".") == 0) {
			my_printf("%s", file->d_name);
			return (0);
		}
	}
	if (closedir(rep) == -1) {
		return(84);
	}
	return 0;
}
