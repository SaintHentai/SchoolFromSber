#include <stdio.h>
#include <math.h> // вообще в задание не сказано можно ли подключать её
#define PI 3.14

int main() {   

    double  n, radian, radian_1;

    // double degree;

    if(scanf("%lf", &n) != 1 || getchar() != '\n'){
        printf("n/a");
    }else{

        radian = n * (180.0 / PI);
        radian_1 = n * (180.0 / M_PI);
        
        // 1 radian = 180 / PI
        // 1 degree = PI / 180 

        // degree = n * (PI / 180.0); если задание наоборот градусы в радианы 

        printf("%.3lf\n", radian);
        printf("%.2lf\n", radian_1); //если нужно точность то нужно использовать константу M_PI

    }

    return 0;

}   // если требуется 57.29 то как-то нужно округлять до 3 знаков и откидывать знак после
 

