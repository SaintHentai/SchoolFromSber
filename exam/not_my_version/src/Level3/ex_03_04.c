#include <stdio.h>
int main(){
    int a, b, c, result ; 
    char ch ;
    if ( scanf("%d %d %d%c", &a, &b, &c, &ch) != 3 && ch != '\n') {
        printf("n/a");
    } // проверка на то что введены целый числа и то, что нету сиволов
    else{
         /*result = (a<c && c<b) ? 1 : 0 ; - другое решение */
        // тернарный оператор (условие ? значение1(после if исполняем грубо говоря) : значение2(в случае else)) 
        //int result = ((a > c && b < c) || (a < c && b > c)) ? 1 : 0; НА подумать
        
        result = (b - c) > 0 && (c - a) > 0 ;
        printf("%d", result) ;
    }

    return 0;
}

/*                  ПРОВЕРЕННОЕ РЕШЕНИЕ

// ЭКСПЕРЕМЕНТАЛЬНЫМ ПУТЕМ БЫЛО ВЫЯСНО, ЧТО ОПЕРАТОР if можно использовать дважды.

#include <stdio.h>

int main() { 
    
    int a, b, c;
    
    if (scanf("%d %d %d", &a, &b, &c) != 3) || getchar() != '\n') {
        printf("n/a");
    } else {
        ((a>c) && (c < b)) ? printf("1") : printf("0");
    }
    return 0;
}

*/