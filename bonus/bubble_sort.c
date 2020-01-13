/*
** EPITECH PROJECT, 2018
** push_swap
** File description:
** function that sort in ascending order a list
*/

//#include "../push_swap.h"
//#include "../include/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void swap_elem_2(char *array_2, char *array_3)
{
	char *slot;
	
	slot = array_2;
	array_2 = array_3;
	array_3 = slot;
}

int bubble_sort_list(char *array, int t)
{
	int swapped = 0;
	int i;
	char *array_2 = malloc(sizeof(char)*10);
	char *array_3 = malloc(sizeof(char)*10);
	char *array_4 = malloc(sizeof(char)*10);

	for (i = 0 ; array[i] != '\0' ; i++) {
		array_2[0] = array[i];
		array_3[0] = array[i+1];
		if (strcmp(array_2, array_3) > 0) {
		        swap_elem_2(array_2, array_3);
			array_4[i] = array_3[0];
			array_4[i+1] = array_2[0];
			array_4[i+2] = '\0';
			swapped = 1;
		}
	}
	printf(array_4);
	if (swapped == 0) {
		return (0);
	} else {
		bubble_sort_list(array_4, 1);
	}
}

int main(void)
{
	char *array = "bx";
	int i = 0;

	bubble_sort_list(array, 0);
}
