#include <stdio.h>

//              НЕВЕРНО РЕШЕНО ГДЕ-ТО ОШИБКА


int fact(int n);
int coeff(int n, int k); 

int main(){

    int n;

    if(scanf("%d", &n)!=1 || getchar()!='\n'){
        printf("n/a");
    }else{

      for(int i = 0; i < n; i++){
          printf("%d ", coeff(n, i));
      }

    }
       return 0;
}

int fact(int n){
    int fact = 1;
    if(n!=0){
       
       for(int i=1; i < n; i++){

            fact = fact * i;

        }
    }

    return(fact);
}


int coeff(int n, int k){
    
    int coeff=1;

    coeff = fact(n) / (fact(k) * fact(n-k));    
   
    
    return(coeff);
 }
