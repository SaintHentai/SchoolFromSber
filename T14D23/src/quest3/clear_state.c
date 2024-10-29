#include "processing.h"

int input(char *filename, doorstate *door1, doorstate *door2);
int scan_door_data(doorstate *door1, doorstate *door2);
void clear_doors(char *filename, doorstate door1, doorstate door2, int *error);
void output(char *filename, int error);

int main(void) {
    char filename[PATHMAX] = {0};
    doorstate door1 = {0};
    doorstate door2 = {0};
    int error = input(filename, &door1, &door2);
    if (!error) {
        clear_doors(filename, door1, door2, &error);
    }
    output(filename, error);
    return 0;
}

int input(char *filename, doorstate *door1, doorstate *door2) {
    int error = 0;
    if (1 != scanf("%255s", filename) || scan_door_data(door1, door2) || !validate_door_data(*door1) ||
        !validate_door_data(*door2)) {
        error = 1;
    }
    return error;
}

int scan_door_data(doorstate *door1, doorstate *door2) {
    int d1_result = 3 != scanf("%2d.%2d.%4d", &(door1->day), &(door1->month), &(door1->year));
    int d2_result = 3 != scanf("%2d.%2d.%4d", &(door2->day), &(door2->month), &(door2->year));
    return d1_result || d2_result;
}

void output(char *filename, int error) {
    FILE *file = NULL;
    int end_of_file;
    if (error || NULL == (file = fopen(filename, "rb")) || fseek(file, 0, SEEK_END) ||
        (end_of_file = ftell(file)) % sizeof(doorstate)) {
        printf("n/a\n");
    } else {
        output_file_data(file, end_of_file);
    }
    if (file) {
        fclose(file);
    }
}

void clear_doors(char *filename, doorstate door1, doorstate door2, int *error) {
    FILE *file = NULL;
    doorstate *doors = NULL;
    int end_of_file = 0;
    if (NULL == (file = fopen(filename, "rb")) || fseek(file, 0, SEEK_END) ||
        (end_of_file = ftell(file)) <= 0 || end_of_file % sizeof(doorstate)) {
        *error = 1;
    } else {
        int max_size = end_of_file / sizeof(doorstate);
        doors = malloc(end_of_file);
        if (NULL == doors) {
            *error = 1;
        }
        int new_size = 0;
        doorstate new_door = {0};
        for (int i = 0; i < max_size && 0 == *error; i++) {
            fseek(file, i * sizeof(doorstate), SEEK_SET);
            fread(&new_door, sizeof(doorstate), 1, file);
            if (!(door_compare(new_door, door1) * door_compare(new_door, door2) <= 0)) {
                doors[new_size++] = new_door;
            }
        }
        fclose(file);
        if (0 != *error || NULL == (file = fopen(filename, "wb"))) {
            *error = 1;
        } else {
            fwrite(doors, sizeof(doorstate), new_size, file);
            fclose(file);
        }
    }
    free(doors);
}
