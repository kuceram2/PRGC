#include <stdbool.h>
#include <stdio.h>

bool read_numbers(int *a, int *b)
{
    const int MAX = 10000;
    const int MIN = -10000;
    int inputOk;
    inputOk = scanf("%d %d", a, b);

    if (inputOk != 2) {
        fprintf(stderr, "Chyba nacitani vstupu!\n");
        return false;
    }

    if (MIN > *a || *a > MAX || MIN > *b || *b > MAX) {
        fprintf(stderr, "Error: Vstup je mimo interval!\n");
        return false;
    }

    return true;
}

bool do_division(int *a, int *b)
{
    if (*b == 0) {
        fprintf(stdout, "Podil: %d / %d = NaN\n", *a, *b);
        fprintf(stderr, "Error: Nedefinovany vysledek!\n");
        return false;
    }
    fprintf(stdout, "Podil: %d / %d = %d\n", *a, *b, (*a / *b));
    return true;
}

int print_output(int *num1, int *num2)
{
    fprintf(stdout, "Desitkova soustava: %d %d\n", *num1, *num2);
    fprintf(stdout, "Sestnactkova soustava: %x %x\n", *num1, *num2);
    fprintf(stdout, "Soucet: %d + %d = %d\n", *num1, *num2, (*num1 + *num2));
    fprintf(stdout, "Rozdil: %d - %d = %d\n", *num1, *num2, (*num1 - *num2));
    fprintf(stdout, "Soucin: %d * %d = %d\n", *num1, *num2, (*num1 * *num2));

    return 0;
}

int print_average(int *num1, int *num2)
{
    fprintf(stdout, "Prumer: %.1f\n", ((float)*num1 + *num2) / 2);
    return 0;
}

int main()
{

    {
        int foo = 4;
    }

    int num1;
    int num2;
    bool divisionPossible;

    if (!read_numbers(&num1, &num2)) return 100;

    print_output(&num1, &num2);
    divisionPossible = do_division(&num1, &num2);
    print_average(&num1, &num2);
    if (!divisionPossible) {
        return 101;
    }

    return 0;
}
