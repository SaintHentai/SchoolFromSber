#include <stdio.h>
#include <stdlib.h>


int main(){

    int temp =0;
    int g = -1;
    int flag = 1;

    while(flag) {
        scanf("%d", &temp);
       
        if(temp == -1) {
            flag = 0;
        }

        if (temp > g) {
            g = temp;
        }
        
    }

    printf("%d", g);
    
    return 0;
}