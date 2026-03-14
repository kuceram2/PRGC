#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define ERROR_INPUT 100
#define MAX_PRIME 1000000

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

int read_int(long *val)
{
    long num = -1;
    int ret;
    if (((ret = scanf("%li", &num)) != 1) || (num < 0))
    {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return ERROR_INPUT;
    }
    if (num == 0)
        return EOF;
    *val = num;
    return EXIT_SUCCESS;
}

int main()
{
    bool numbers[MAX_PRIME + 1];
    int prime_count = MAX_PRIME;
    sieve_primes(MAX_PRIME, &prime_count, numbers);
    int primes[prime_count];
    get_primes_array(primes, numbers, MAX_PRIME);

    long num = 0;
    int ret;
    while ((ret = read_int(&num)) == EXIT_SUCCESS)
    {
        prime_decompose(num, primes);
    }
    if (ret == ERROR_INPUT)
        return ERROR_INPUT;
    return 0;
}
