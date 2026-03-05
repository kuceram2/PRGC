# include <stdio.h>

# define MAX_VAL 10
# define MIN_VAL 1
# define ERR_VAL 100
# define ERR_RANGE 101
 // alternativně

 enum{
    ERROR_VAL = 100,
    ERROR_RANGE = 101
 };

int trojuhelnik(void){
    int width = -1;
    int ret;

    ret = scanf("%d", &width);
    if(ret == 0){
        fprintf(stderr,"ERROR: Cannot read integer value from the standard input\n");
        return ERR_VAL;
    }

    if(!(width >= MIN_VAL && width <= MAX_VAL)){
        fprintf(stderr,"ERROR: Given value %d is not within the range [1, 10]\n", width);
        return ERR_RANGE;
    }

    for(int i = width; i > 0; --i){
        for(int j = 0; j < i; ++j) printf("*");
        printf("\n");
    }

}


int main(int argc, char *argv[]){
    trojuhelnik();
    return 0;
}