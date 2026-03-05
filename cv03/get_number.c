# include <stdlib.h>
# include <stdio.h>

long get_number(void){
    long result = 0;
    char digit;
    while(((digit=getchar()) != EOF) && (digit >= '0') && (digit <= '9')){
        result *= 10;
        result += (digit - '0');
        printf("precteno %c %d\n", digit, (digit-'0'));
    }
    return result;
    
}

int main(int argc, char *argv[]){

    printf("Precteno: %ld\n",get_number());
    return 0;
}