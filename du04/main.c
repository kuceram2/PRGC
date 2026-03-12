#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHA_LEN 26

void print_counts(int *letter_counts){
    for(int i = 0; i < ALPHA_LEN; ++i){
        printf(" %i", *(letter_counts + i));
    }
    printf("\n");
}

void print_alphabet(void){
    for(int i = 0; i < ALPHA_LEN; ++i) printf(" %c", 'a' + i);
    printf("\n");
}

int get_input(void){
    char letter;
    int letter_idx;
    int letter_count[ALPHA_LEN] = {[0] = 0};

    while (isalpha(letter = getchar()) || (letter == ' ')){
        if (letter == ' ') continue;

        letter = tolower(letter);
        letter_idx = (letter - 'a');
        if ((letter_count[letter_idx] += 1) > 9){
            fprintf(stderr, "Error: Prilis mnoho stejnych znaku!\n");
            return 101;
        }
    }
    // if reading ended because of unexpected character
    if ((letter != EOF) && (letter != '.') && (letter != '\n')){
        fprintf(stderr, "Chyba vstupu!\n");
        return 100;
    }

    print_alphabet();
    print_counts(letter_count);

    return 0;
}

int main(int argc, char *argv[]){
    return get_input();
}
