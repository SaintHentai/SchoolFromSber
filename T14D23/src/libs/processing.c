#include "processing.h"

int door_compare(doorstate door1, doorstate door2) {
    int dif = 0;
    if (door1.year != door2.year) {
        dif = door1.year - door2.year;
    } else if (door1.month != door2.month) {
        dif = door1.month - door2.month;
    } else if (door1.day != door2.day) {
        dif = door1.day - door2.day;
    } else if (door1.hour != door2.hour) {
        dif = door1.hour - door2.hour;
    } else if (door1.minute != door2.minute) {
        dif = door1.minute - door2.minute;
    } else if (door1.second != door2.second) {
        dif = door1.second - door2.second;
    }
    return dif;
}

int day_result(int day, int month, int year) {
    int result = 0;
    int month31 =
        1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month;
    int february = 2 == month;
    if (february && day > 0 && ((is_leap(year) && day == 29) || day <= 28)) {
        result = 1;
    } else if (month31 && day > 0 && day <= 31) {
        result = 1;
    } else if (day <= 30) {
        result = 1;
    }
    return result;
}

int validate_door_data(doorstate door) {
    int date_result =
        door.year >= 0 && door.month > 0 && door.month < 13 && day_result(door.day, door.month, door.year);
    int hour_result = door.hour >= 0 && door.hour <= 23;
    int min_sec_result = door.minute >= 0 && door.minute <= 59 && door.second >= 0 && door.second <= 59;
    int status_result = door.status == 0 || door.status == 1;
    return date_result && hour_result && min_sec_result && status_result;
}

void output_file_data(FILE *file, int end_of_file) {
    rewind(file);
    doorstate cur_door = {0};
    int pos = 0;
    while (pos != end_of_file) {
        fseek(file, pos, SEEK_SET);
        fread(&cur_door, sizeof(doorstate), 1, file);
        print_doorstate(cur_door);
        pos += sizeof(doorstate);
    }
}

void print_doorstate(doorstate door) {
    printf("%d %d %d ", door.year, door.month, door.day);
    printf("%d %d %d ", door.hour, door.minute, door.second);
    printf("%d %d\n", door.status, door.code);
}

int is_leap(int year) { return year % 4 == 0 && ((year % 400 == 0) || (year % 100 != 0)); }