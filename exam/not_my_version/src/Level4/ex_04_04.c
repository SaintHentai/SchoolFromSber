#include <stdio.h>

// ошибка

int main(){

    int a, b, c;
    int num;

    if(scanf("%d", &num) != 1 || getchar() != '\n'){
        printf("n/a");
    }else{
        a = num / 100;
        b = (num / 10) % 10;
        c = num % 10;

        a > b ? (b = a) : (a = b);
        a > c ? (c = a) : (a = c);


        printf("%d", a); 
    
    }

    return 0;
}