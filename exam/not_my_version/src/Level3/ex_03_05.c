#include <stdio.h>


int main() {

    int x, y, z;
    char ch;

    if ( scanf("%d %d %d%c", &x, &y, &z, &ch) != 3 && ch != '\n') {
            printf("n/a");
        }
    else{

        if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1) {
            printf("n/a");
        }
        else{
            int result = x && (z || y); // подумать над условием задачи
            //printf("%d", x && (z || y)); тоже вариант
            printf("%d", result); // вывод результата
        }

    }
    
    return 0;
}
/*              НЕВЕРНОЕ РЕШЕНИЕ

#include <stdio.h>

int main() {
    if (scanf("%d %d %d", &x, &y, &z) != 3 || getchar() != '\n') {
        printf("n/a");
    } else {
        // или такой вариант всё равно не верно решено 
        //((x==1)&& ((z==1)||(y==1)))?printf("1"):printf("0");
        if(x==1 && (z==1 || y==1)) printf("1");
        else printf("0");
    }
    return 0;
}


*/