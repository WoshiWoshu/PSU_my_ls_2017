/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** function that handly the ls without option
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

int without_flag(int ac, char **av)
{
	DIR *rep = NULL;
	struct dirent *file = NULL;
	int i;

	if (ac < 0) {
		my_printf("not enough argument or too much arguments");
		return(84);
	}
	rep = opendir(av[1]);
	if (rep == NULL) {
		perror("");
		return (84);
	}
	while ((file = readdir(rep)) != NULL) {
		if (file->d_type == DT_DIR || file->d_type == DT_REG) {
			if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0 & strcmp(file->d_name, ".git") != 0 ) {
				my_printf("%s\n", file->d_name);
			}
		}
		i++;
	}
	if (closedir(rep) == -1) {
		return(84);
	}
	return 0;
}
