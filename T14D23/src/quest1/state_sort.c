#include "processing.h"

int input(char *filename, int *mode);
///---------------------------------------------
void sort_file_mode(char *filename, int *error);
void sort_file_data(FILE *file, int end_of_file);
void swap_doors(doorstate *door1, doorstate *door2, FILE *file);
///---------------------------------------------
void file_insertion_mode(char *filename, int *error);
void insert_new_door(FILE *file, int *end_of_file, int *error);
int scan_door_data(doorstate *door);
///---------------------------------------------
void output_file_mode(char *filename, int *error);
void output_error(void);

int main(void) {
    char filename[PATHMAX] = {0};
    int error = 0;
    int mode = 0;
    error = input(filename, &mode);
    if (!error) {
        if (OUTPUT == mode) {
            output_file_mode(filename, &error);
        } else if (SORT == mode) {
            sort_file_mode(filename, &error);
        } else if (INSERTION == mode) {
            file_insertion_mode(filename, &error);
        }
    }
    if (error) {
        output_error();
    }
    return 0;
}

int input(char *filename, int *mode) {
    int error = 0;
    if (1 != scanf("%255s", filename) || 1 != scanf("%d", mode) || !(*mode >= 0 && *mode <= 2)) {
        error = 1;
    }
    return error;
}

///---------------------------------------------
///---------------------------------------------
///---------------------------------------------

void sort_file_mode(char *filename, int *error) {
    FILE *file = NULL;
    int end_of_file = 0;
    if (NULL == (file = fopen(filename, "r+b")) || fseek(file, 0, SEEK_END) ||
        (end_of_file = ftell(file)) <= 0 || end_of_file % sizeof(doorstate)) {
        *error = 1;
    } else {
        sort_file_data(file, end_of_file);
        output_file_data(file, end_of_file);
        fclose(file);
    }
}

void sort_file_data(FILE *file, int end_of_file) {
    rewind(file);
    doorstate cur_door = {0};
    doorstate next_door = {0};
    int size = end_of_file / sizeof(doorstate);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            fseek(file, j * sizeof(doorstate), SEEK_SET);
            fread(&cur_door, sizeof(doorstate), 1, file);
            fseek(file, (j + 1) * sizeof(doorstate), SEEK_SET);
            fread(&next_door, sizeof(doorstate), 1, file);
            if (door_compare(cur_door, next_door) > 0) {
                fseek(file, j * sizeof(doorstate), SEEK_SET);
                swap_doors(&cur_door, &next_door, file);
            }
        }
    }
}

void swap_doors(doorstate *door1, doorstate *door2, FILE *file) {
    doorstate *tmpdoor = door1;
    fwrite(door2, sizeof(doorstate), 1, file);
    fwrite(tmpdoor, sizeof(doorstate), 1, file);
}

///---------------------------------------------
///---------------------------------------------
///---------------------------------------------

void file_insertion_mode(char *filename, int *error) {
    FILE *file = NULL;
    int end_of_file = 0;
    if (NULL == (file = fopen(filename, "r+b")) || fseek(file, 0, SEEK_END) ||
        (end_of_file = ftell(file)) <= 0 || end_of_file % sizeof(doorstate)) {
        *error = 1;
    } else {
        insert_new_door(file, &end_of_file, error);
        if (0 == *error) {
            sort_file_data(file, end_of_file);
            output_file_data(file, end_of_file);
            fclose(file);
        }
    }
}

void insert_new_door(FILE *file, int *end_of_file, int *error) {
    doorstate new_door = {0};
    if (scan_door_data(&new_door) || !validate_door_data(new_door)) {
        *error = 1;
    } else {
        fseek(file, 0, SEEK_END);
        fwrite(&new_door, sizeof(doorstate), 1, file);
        *end_of_file += sizeof(doorstate);
        rewind(file);
    }
}

int scan_door_data(doorstate *door) {
    int date_result = scanf("%d %d %d", &(door->year), &(door->month), &(door->day));
    int time_result = scanf("%d %d %d", &(door->hour), &(door->minute), &(door->second));
    int door_result = scanf("%d %d", &(door->status), &(door->code));
    return (date_result + time_result + door_result) != 8;
}

///---------------------------------------------
///---------------------------------------------
///---------------------------------------------

void output_file_mode(char *filename, int *error) {
    FILE *file = NULL;
    int end_of_file = 0;
    if (NULL == (file = fopen(filename, "rb")) || fseek(file, 0, SEEK_END) ||
        (end_of_file = ftell(file)) <= 0 || end_of_file % sizeof(doorstate)) {
        *error = 1;
    } else {
        output_file_data(file, end_of_file);
        fclose(file);
    }
}

void output_error(void) { printf("n/a\n"); }
