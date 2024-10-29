#ifndef PROCESSING_H
#define PROCESSING_H

#include "door.h"
#include <stdio.h>
#include <stdlib.h>

#define PATHMAX 256

#define OUTPUT 0
#define SORT 1
#define INSERTION 2

void output_file_data(FILE *file, int end_of_file);
void print_doorstate(doorstate door);

int door_compare(doorstate door1, doorstate door2);
int day_result(int day, int month, int year);
int validate_door_data(doorstate door);
int is_leap(int year);

#endif
