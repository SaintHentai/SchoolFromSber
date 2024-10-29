#include <stdio.h>
#define RAD 57.29

int main(){
    double temp, ost ;
    int num, result = 0;
    char ch;
    if ( scanf("%d%c", &num, &ch) != 1 && ch != '\n') {
        printf("n/a") ;
    }
    else{
        temp = num * RAD;
        for(int i = 1; i < temp; i++) {
            result++;
        }
        ost = temp - result;
        if (ost >= 0.5) {
            result++ ; 
        }
        printf("%d", result);   
        }
    return 0 ;
}

/*              НЕВЕРНОЕ РЕШЕНИЕ
// В решегие нету округления вот и вс] проблема  

#include <stdio.h>


int main() {

    int n;
    double result;
    double rad = 57.29;

    if (scanf("%d", &n) != 1) || getchar() != '\n') {
        printf("n/a");
    } else {
        result = n * rad;
        printf("%0.0f", result);

*/