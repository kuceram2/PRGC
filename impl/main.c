#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

#define ERROR_OK EXIT_SUCCESS
#define ERROR_INVALID_CHAR 100
#define ERROR_NOT_POSITIVE 101
#define ERROR_OVERFLOW 102
#define ERROR_OUT_OF_RANGE 103
#define ERROR_IO 104
#define MAX (INT_MAX-1)
#define MAX_INT_EXP 8

int highest_power10(int value){    
    if (value < 10) return 0;
    for(int i = 1;i < MAX_INT_EXP;++i){
        int compare = 10;
        for(int j = 0;j < i; ++j) compare = compare*10;
        if ((value % compare) == value) return i;
    }
}

int print_int(int value){
    int pwr = highest_power10(value);
    int digit;
    for (int i = pwr; i>=0;--i){
        int divider = 1;
        for (int j = 0; j<i;++j) divider = divider*10;
        digit = (value / divider);
        printf("%c", '0'+digit);
        value = value - (digit*divider);
    }
    printf("\n");

}

int read_int(int *value){
    int tmp;
    long number = 0;
    while (((tmp = getchar()) == ' ') || (tmp == '\n'));
    if (tmp == EOF) return EOF;
    if (tmp == '-') return ERROR_NOT_POSITIVE;
    if (!(isdigit(tmp)) && (tmp != ' ') && (tmp != '\n')) return ERROR_INVALID_CHAR;
    do{
        if(number*10 > INT_MAX) return ERROR_OVERFLOW;
        number = (number*10);
        //printf("%c, %i\n", tmp,tmp);
        number += (tmp - '0');
    }while (isdigit(tmp = getchar()));

    if ((tmp != ' ') && (tmp != '\n')) return ERROR_INVALID_CHAR;
    if (number >= MAX) return ERROR_OUT_OF_RANGE;
    if (number > INT_MAX) return ERROR_OVERFLOW;
    *value = (int)number;
    return ERROR_OK;

}

int main(){
    int val = -1;
    int out;
    int ret;
    while ((ret = read_int(&val)) == ERROR_OK){
        printf("%i\n", val);
    }
    return ret;
}