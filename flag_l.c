/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** flag_l
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

int flag_l(int ac, char **av)
{

	DIR *rep = NULL;
	struct dirent *file = NULL;
	struct stat info;
	struct passwd *info_2 = NULL;
	struct group *info_3 = NULL;
	char *array = malloc(sizeof(char)*340);
	int i = 0;
	int h =0;


	if (ac < 0) {
		printf("not enough argument or too much arguments");
		return(84);
	}
	rep = opendir(av[2]);
	if (rep == NULL) {
		perror("");
		return (84);
	}
	while ((file = readdir(rep)) != NULL) {
		array = strcat(array, av[2]);
		array = strcat(array, "/");
		array = strcat(array, file->d_name);
		if (stat(array, &info) == -1) {
			perror("");
			return(84);
		}
		info_2 = getpwuid(info.st_uid);
		if (info_2 == NULL) {
			perror("");
			return (84);
		}
		info_3 = getgrgid(info.st_gid);
		if (info_3 == NULL) {
			perror("");
			return (84);
		}
		if (file->d_type == DT_DIR || file->d_type == DT_REG) {
			if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0 & strcmp(file->d_name, ".git") != 0 ) {
				h = h + info.st_blocks;
				if (file->d_type == DT_DIR) {
					printf("%s","d");
				} else {
					printf("%s","-");
				}
				if (info.st_mode && S_IRUSR) {
					printf("%s","r");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IWUSR) {
					printf("%s","w");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IXUSR) {
					printf("%s","x");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IRGRP) {
					printf("%s","r");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IWGRP) {
					printf("%s","w");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IXGRP) {
					printf("%s","x");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IROTH) {
					printf("%s","r");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IWOTH) {
					printf("%s","w");
				} else {
					printf("%s","-");
				}
				if (info.st_mode & S_IXOTH) {
					printf("%s","x. ");
				} else {
					printf("%s","-. ");
				}
				printf("%d ", info.st_nlink);
				printf("%s ", info_2->pw_name);
				printf("%s ", info_3->gr_name);
				printf("%d ", info.st_size);
				printf("%.12s ", 4+ctime(&info.st_mtime));
				printf("%s\n", file->d_name);
			}
		}
		array[0] = 0;
	}
	h = h / 2;
	printf("total %d\n", h);
	if (closedir(rep) == -1) {
		return(84);
	}
	return (0);
}
