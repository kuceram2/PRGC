#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define ERROR_INPUT 100
#define MAX_PRIME 1000000
#define MAX_DIGITS 101

void sieve_primes(int n, int *prime_count, bool numbers[])
{
    // Initialize all numbers as prime
    for (int i = 0; i <= n; i++)
    {
        numbers[i] = true;
    }

    numbers[0] = false;
    numbers[1] = false;
    *prime_count -= 1;

    // filter non-prime numbers
    for (int p = 2; p * p <= n; p++)
    {
        if (numbers[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                if (numbers[i])
                {
                    numbers[i] = false;
                    *prime_count -= 1;
                }
            }
        }
    }
}

void get_primes_array(int primes[], bool numbers[], int numbers_len)
{
    // fill array with found primes
    int ctr = 0;
    for (int i = 0; i <= numbers_len; i++)
    {
        if (numbers[i])
        {
            primes[ctr] = i;
            ctr += 1;
        }
    }
}

int prime_decompose(long num, int primes[])
{
    printf("Prvociselny rozklad cisla %li je:\n", num);
    // handle special case
    if (num == 1)
    {
        printf("1\n");
        return EXIT_SUCCESS;
    }

    int i = 0;
    while (primes[i] <= num)
    {
        int exp = 0;
        while ((num % primes[i]) == 0)
        {
            num = num / primes[i];
            ++exp;
        }
        // if number is divisible by current prime
        if (exp > 0)
        {
            printf("%i", primes[i]);
            if (exp > 1)
                printf("^%i", exp);
            if (num > 1)
                printf(" x ");
        }
        i += 1;
    }
    printf("\n");
    return EXIT_SUCCESS;
}

void copy_big_int(long source[], int source_len, int dest[], int *dest_len){
    for (int i = 0; i < source_len; ++i){
        dest[i] = source[i];
    }
    *dest_len = source_len;
}

// int divide_big_int(int digits[], int num_len, int res[], int *res_len, int divider)
// {
//     if (divider == 0) return -2;

//     long long number = 0;
//     int idx = 0;
//     *res_len = 0;

//     while (idx < num_len) {

//         number = number * 10 + digits[idx];

//         if (number < divider && idx < num_len - 1) {
//             idx++;
//             continue;
//         }

//         int digit = number / divider;

//         res[*res_len] = digit;
//         (*res_len)++;

//         number -= digit * divider;

//         idx++;
//     }

//     if (number > 0) return 0;  // remainder
//     return 1;                  // divisible
// }


int divide_big_int(int digits[], int num_len,
                   long res[], int *res_len,
                   int divider)
{
    if (divider == 0)
        return -2;   // division by zero

    int remainder = 0;
    *res_len = 0;

    for (int i = 0; i < num_len; i++)
    {
        remainder = remainder * 10 + digits[i];

        int q = remainder / divider;
        remainder = remainder % divider;

        // avoid leading zero in result
        if (*res_len > 0 || q > 0)
        {
            res[*res_len] = q;
            (*res_len)++;
        }
    }

    // if result is zero
    if (*res_len == 0)
    {
        res[0] = 0;
        *res_len = 1;
    }

    if (remainder == 0)
        return 1;   // divisible
    else
        return 0;   // remainder exists
}

int my_divide_big_int(int digits[], int num_len, long res[], int *res_len, int divider){
    /*returns 1 if division successful, 0 if not divisible, -1 if divider bigger than number*/
    if (divider == 0) return 0;
    int idx = -1;
    //int res = 0;
    long long number = 0;
    *res_len = 0;
    while (idx < num_len-1){
        idx += 1;
        number = (number*10) + digits[idx];
        //number = digits[idx];
        //printf("Number: %i\n", number);
        while (((number / divider) == 0) && (idx < num_len-1) ){
            idx += 1;
            number = (number*10) + digits[idx];
            //printf("sepsano: %i\n", number);
        }
        //idx += 1;
        res[*res_len] = (number / divider);
        *res_len += 1;
        //res = res*10 + (number / divider);
        //printf("current res: %i\n", res);
        number = number - ((number / divider) * divider);

        // if (number < 0) {
        //     printf("overflow detected\n");
        // }
        

    }
    
    //if not divisible
    if ((number > 0) && (res[0] != 0)) return 0;
    if (number > 0) return -1;
    else return 1;
}

int read_big_int(int digits[], int *len){
    int tmp;
    int idx = 0;
    while (((tmp = getchar()) == ' ') || (tmp == '\n'));
    if ((tmp == '-') || (!isdigit(tmp))){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return ERROR_INPUT;
    }
    do{
        digits[idx] = (tmp - '0');
        idx++;

    }while(isdigit(tmp = getchar()));
    *len =idx;
    if (digits[0] == 0) return 99;
    return EXIT_SUCCESS;
}

int prime_decompose_big(int digits[], int num_len, int primes[], int primes_len)
{
    long res[MAX_DIGITS];
    int res_len =0;
    printf("Prvociselny rozklad cisla ");
    for (int i = 0; i < num_len; ++i) printf("%i", digits[i]);
    printf(" je:\n");
    // handle special case
    if ((num_len == 1) && (digits[0] == 1))
    {
        printf("1\n");
        return EXIT_SUCCESS;
    }
    //printf("starting decomp\n");
    int i = 0;
    int tmp = 0;
    bool first = true;
    while ((i < primes_len) && (((divide_big_int(digits, num_len, res, &res_len, primes[i]))) != -1)) 
    // while primes are smaller than the number
    {
        // printf("here, %i\n", tmp);
        //     printf("digits curr: ");
        //     for (int i = 0; i < num_len; ++i) printf("%i",digits[i]);
        //     printf("\nres curr: ");
        //     for (int i = 0; i < res_len; ++i) printf("%i",res[i]);
        //     printf("\n");
        int exp = 0;
        while ((tmp = divide_big_int(digits, num_len, res, &res_len, primes[i])) == 1) // while divisible
        {
            // printf("digits pre: ");
            // for (int i = 0; i < num_len; ++i) printf("%i",digits[i]);
            // printf("\n   res pre: ");
            // for (int i = 0; i < res_len; ++i) printf("%i",res[i]);
            // printf("\n");

            copy_big_int(res, res_len, digits, &num_len);

            // printf("digits post: ");
            // for (int i = 0; i < num_len; ++i) printf("%i",digits[i]);
            // printf("\n   res post: ");
            // for (int i = 0; i < res_len; ++i) printf("%i",res[i]);
            // printf("\n%i\n", (num_len == res_len));

            // printf("number updated\n");
            ++exp;
        }
        //printf("stop: %i\n", tmp);
        // if number is divisible by current prime
        if (exp > 0)
        {
            if (!first) printf(" x ");
            first = 0;
            printf("%i", primes[i]);
            if (exp > 1)
                printf("^%i", exp);
            //if (num_len >= 1)
                //printf(" x ");
        }
        i += 1;
    }
    printf("\n");
    return EXIT_SUCCESS;
}

int main()
{
    int ret = 0;
    // int arr[] = {1,2};
    // int res[MAX_PRIME];
    // int res_len = 0;
    // printf("Out: %i\n",divide_big_int(arr, 2, res, &res_len, 13));
    // for (int i = 0; i < res_len; ++i){
    //     printf("%i",res[i]);
    // }
    // printf("\n");

    bool numbers[MAX_PRIME + 1];
    int prime_count = MAX_PRIME;
    sieve_primes(MAX_PRIME, &prime_count, numbers);
    int primes[prime_count];
    get_primes_array(primes, numbers, MAX_PRIME);

    int digits[MAX_DIGITS];
    int num_len = 0;
    //read_big_int(digits, &num_len);

    //  for (int i = 0; i < num_len; ++i){
    //     printf("%i",digits[i]);
    // }

   //prime_decompose_big(digits, num_len, primes, prime_count);

    while ((ret = read_big_int(digits, &num_len)) == EXIT_SUCCESS)
        {
            prime_decompose_big(digits, num_len, primes, prime_count);
        }
        if (ret == ERROR_INPUT)
            return ERROR_INPUT;


    // long num = 0;
    // int ret;
    // while ((ret = read_int(&num)) == EXIT_SUCCESS)
    // {
    //     prime_decompose(num, primes);
    // }
    // if (ret == ERROR_INPUT)
    //     return ERROR_INPUT;
    return 0;
}
