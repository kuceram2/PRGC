
# include <stdio.h>
# include <stdlib.h>
# define MAX 10000
# define MIN -10000
# define LIMITS_ERR 100

void print(int *input_count, int *positive_count, int *negative_count, int *even_count, int *numbers_sum, int *max_value, int *min_value){
    double positive_percentage = 100 * (*positive_count / (double)*input_count);
    double negative_percentage = 100 * (*negative_count / (double)*input_count);
    double even_percentage = 100 * (*even_count / (double)*input_count);
    printf("\nPocet cisel: %d\n", *input_count);
    printf("Pocet kladnych: %d\n", *positive_count);
    printf("Pocet zapornych: %d\n", *negative_count);
    printf("Procento kladnych: %.2f\n", positive_percentage);
    printf("Procento zapornych: %.2f\n", negative_percentage);
    printf("Pocet sudych: %d\n", *even_count);
    printf("Pocet lichych: %d\n", (*input_count - *even_count));
    printf("Procento sudych: %.2f\n", even_percentage);
    printf("Procento lichych: %.2f\n", (100.0 - even_percentage));
    printf("Prumer: %.2f\n", (*numbers_sum / (double)*input_count));
    printf("Maximum: %d\n", *max_value);
    printf("Minimum: %d\n", *min_value);


}

void update_stats(int value, int *input_count, int *positive_count, int *negative_count, int *even_count, int *numbers_sum, int *max_value, int *min_value){
    if(*input_count == 0){
        *max_value = value;
        *min_value = value;
        printf("%d", value);
    }
    else{
        if(value > *max_value) *max_value = value;
        if(value < *min_value) *min_value = value;
        printf(", %d", value);
    }
    
    ++*input_count;
    *numbers_sum = *numbers_sum + value;
    if(value > 0) ++*positive_count;
    else if(value < 0) ++*negative_count;
    if((value % 2) == 0) ++*even_count; 
}

int is_in_limit(int value){
    if((value <= MAX) && (value >= MIN)) return 1;
    else{
        printf("\nError: Vstup je mimo interval!\n");
        return 0;
    }
    
}

int capture_input(int *input_count, int *positive_count, int *negative_count, int *even_count, int *numbers_sum, int *max_value, int *min_value){
    int ret = 1;
    int value;
    while(ret == 1){
        ret = scanf("%d", &value);
        if(ret == 1){
            if(is_in_limit(value)){
                update_stats(value, input_count, positive_count, negative_count, even_count, numbers_sum, max_value, min_value);
            }
            else return LIMITS_ERR;
        }
    }
    print(input_count, positive_count, negative_count, even_count, numbers_sum, max_value, min_value);
    return 0;
}

int main(int argc, char *argv[]){
    int input_count = 0;
    int positive_count = 0;
    int negative_count = 0;
    int even_count = 0;
    int numbers_sum = 0;
    int max_value = 0;
    int min_value = 0;

    return capture_input(&input_count, &positive_count, &negative_count, &even_count, &numbers_sum, &max_value, &min_value);
}
