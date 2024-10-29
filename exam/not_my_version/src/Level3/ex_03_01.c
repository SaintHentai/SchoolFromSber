#include <stdio.h>
#include <math.h>
#define ro 21500

double round (double x);

int main() {

    double r, result;

    if(scanf("%lf", &r) != 1 || r < 0 || getchar() != '\n') {
        printf("n/a");
    }
    else{

        result= round(r);

        printf("%.0lf", result);

    }
    
    return 0;
}

double round(double x) {

    double m;
    m = (4.0/3.0) * ro * M_PI * pow(x,3);
    
    return m;
}