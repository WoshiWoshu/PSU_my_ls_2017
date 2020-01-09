/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** flag_L_part2
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

int flag_maj_l_2(char **av,char *array, int i, int k, int j)
{
	DIR *rep = NULL;
	char *array_2 = malloc(sizeof(char)*100);
	struct dirent *file = NULL;

	if (j == 1) {
	rep = opendir(av[2]);
	if (rep == NULL) {
		perror("");
		return (84);
	}
	while ((file = readdir(rep)) != NULL) {
		if (file->d_type == DT_REG && i != 1) {
			my_printf("\n%s:\n%s\n", av[2], file->d_name);			
		} else {
			if (file -> d_type == DT_REG && strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0 && strcmp(file->d_name, ".git") != 0) {
				my_printf("%s ", file->d_name);
				my_printf("\n");
			}
		}
		if (file->d_type == DT_DIR) {
			if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0 && strcmp(file->d_name, ".git") != 0 ) {
				array[0] = 0;
				strcpy(array, av[2]);
				strcat(array, "/");
				strcat(array, file->d_name);
				my_printf("\n%s/%s:\n", av[2], file->d_name);
				flag_maj_l_2(av, array, 1, 2, 0);
			}
		}
	}
	if (closedir(rep) == -1) {
		return(84);
	}
	} else {
	rep = opendir(array);
	if (rep == NULL) {
		perror("");
		return (84);
	}
	while ((file = readdir(rep)) != NULL) {
		if (file->d_type == DT_REG && i != 1) {
			my_printf("\n%s:\n%s\n", array, file->d_name);			
		} else {
			if (file -> d_type == DT_REG && strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0 && strcmp(file->d_name, ".git") != 0) {
				my_printf("%s ", file->d_name);
				my_printf("\n");
			}
		}
		if (file->d_type == DT_DIR) {
			if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0 && strcmp(file->d_name, ".git") != 0 ) {
				array_2[0] = 0;
				strcpy(array_2, array);
				strcat(array_2, "/");
				strcat(array_2, file->d_name);
				my_printf("\n%s/%s:\n", array, file->d_name);
				flag_maj_l_2(av, array_2, 1, 2, 0);
			}
		}
	}
	if (closedir(rep) == -1) {
		return(84);
	}
	}
	return (0);
}
