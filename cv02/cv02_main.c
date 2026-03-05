# include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    char text[100];
    scanf("%10s", text);
    printf("%s\n", text);

    /*int x;
    double num1;

    int ret;
    ret = scanf("%d %lf",&x, &num1);
    printf("x = %d, num1 = %f, ret = %d\n",x, num1, ret);
*/


/*
    double sum = 0;

    for(int i = 1; i < argc; i++){
        printf("parametr %d: %s\n", i, argv[i]);
        sum += atof(argv[i]);
    }
    printf("soucet: %f", sum);
    */

    /*
    int znak;
    while(znak = getchar() != EOF){
        printf("%c, %i\n", znak, znak);

    }
*/
    return 0;
}