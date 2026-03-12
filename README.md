# PRGC 
## TLDR
-Nezapomeň ;
- &foo [ampersand], kde foo je var vrací adresu dané proměnné
- *foo [asterisk], kde foo je pointer, vrací hodnotu uloženou na adrese uložené ve foo
- *Ternární operátor* 'vyraz' ? 'kod pro vyraz true' : 'kod pro vyraz false'
    - alt. použití: `int a = x<y ? x : y`
- `ctrl+d` v bashi emuluje EOF (end of file)
- `echo $?` - vypíše hodnotu vrácenou posledním spuštěným programem
- nepoužívat `while(true)`, faigl to nesnáší

- NULA NENÍ KLADNÉ ČÍSLO
- Přesměrování vstupu/výstupu

## Header files/libraries/includes
- <stdio.h> = standard input & output
    - `printf("text, %d", intVal)`
    - `scanf("%d", &intVal)` 
        - načení vstupu, pomocí format modifier určíme načítaný datatyp a uložíme do proměnné podle adresy (&)
        - neumí načíst víc slov (skončí když mezera nebo \n )
        - " %d" - odignoruje whitespace před hledaným vstupem 
    - `fgets(varName, sizeof(varName), stdin)`
        - `getchar(void)` - užitečné, pokud z předchozích vstupů zůstává ve frontě \n. Tato funkce ho načte a tedy odstraní
        - načtení řádku z textového vstupu
    - `fprintf`
        - formátované vypisování do daného kanálu/souboru. 
        - užití *stdout*, *stderr*
- <string.h>
    - přidává funkce pro práci se stringy
    - `strlen(name)` - vrací délku stringu
- <math.h>
    - počítání
    - `sqrt()`,`pwr(x,pwr)`
- <ctype.h>
    - `isalpha()`	Checks whether a character is a letter
    - `isdigit()`	Checks whether a character is a decimal digit
    - `tolower()`, `toupper()` - Changes case
- <stdbool.h> = importuje datatyp bool
- <limits.h> = zadefinované min/max hodnoty datatypů
- <stdlib.h> = užitečné kravinky, např:
    - EXIT_SUCCESS, EXIT_FAILURE
    - atoi, atol, atof

## Datatypy
`sizeof(int)` - vrací velikost datatypu/výrazu
```c
char pismeno = 'a'; // 1b
char jmeno[] = "takhle se v c dělá string"; // v paměti zakončený '\0'
// pro char jsou '' závorky, pro string ""
int cislo = 42; // 4b
float pi = 3.141592f; // 4b, to "f" je důležitý
double e = 2.7116811354; // 8b
bool anoNe = true; // vyžaduje include <stdbool.h>,
bool n = 0; // 1b

signed / unsigned int // se znaménkem nebo bez. 
// unsigned nemůže být záporný
```
- velikosti nejsou přesně dány, jsou jen jejich vztahy (int < long), záleží na HW a kompileru

### Literály
**Znakové** 
- 'A', 'B', '\n'
- hodnota literálu je ASCII číslo

**Řetězcové**
- "Text s koncem\n"

**Výčtové** - enum
= sada pojmenovaných int
```c
enum{
    SPADES,
    CLUBS
};
```


## Format specifiers
Určují jak se zobrazují a interpretují hodnoty 
<br>

- %.nd = určení přesnosti na n desetinných míst (pokud jich má číslo víc než je nastaveno, zaokrouhlí se)
- %xd = určení minimálního počtu znaků, které má číslo zabírat, pokud je číslo kladné, "doplňkové mezery" se dávají před číslo, pokud záporné, za číslo
- %0pd = jako předchozí, místo mezer se vypíší nuly
- %+d = vypíše znamínko i u kladných čísel
- tyhle parametry se daj kombinovat
```c
int val = 42;
float pi = 3.141592;
printf("%3d\n", val);
printf("%-3d\n", val);
printf("%03d", val);
printf("%+d", val);
printf("%+010.4f", pi);
>>> _42
>>> 42_
>>> 042
>>> +42
>>> +0003.1416
//ve skutečnosti to nejsou podtržítka ale mezery
``` 

**Pro jednotlivé datatypy:**
- %d = int (bool) - decimal
- %f = float (defaultně 6 desetinných míst)
- %lf = double (*long float*) (default 6 des. míst, max 16)
- %c = char
- %s = char[] (string)
- %x	a hexadecimal (base 16) integer
- %p	an address (or pointer)
- %f	a floating point number for floats
- %u	int unsigned decimal
- %p    pointer

## Compilery
`gcc main.c -o main`
`gcc main.c -o main && ./main && echo $?` - zkompilovat, spustit, vypsat výstup mainu
-E - spustí pouze preprcesor
-o jmeno = linkuje výstup do souboru daného jména
-lm 

info o souboru
file, vdd

## main
```c
int main(int argc, char *argv[] ){ // počet vstupů, pointr k array vstupů

}
```

## Funkce
deklarace = void foo(params);
definice = void foo(params){ *tělo fce*}
návratový typ i argumenty můžou být prázdné
`void foo(void);`
### Keywords
static = viditelné pouze v daném bloku (souboru)

### Předávání parametrů do funkce
* defaultně se předává hodnotou
* pole se předávají odkazem, proto je praktické předávat zároveň délku pole
```c
foo(int a, int *b); // a předává hodnotu, b předává adresu
```

## Cykly
### řídící příkazy
`break` - ukončí provádění nejvnitřnějšího cyklu
`continue` - přeskočí současný průběh cyklu, u for a while se vrátí k vyhodnocení na začátku
`goto` - teleport, pouze uvnitř jedné funkce (bloku), 

```c
if(a >0){
    goto teleport;
}

teleport:
pritnf(...);
//tady musí být alespoň jeden příkaz
```

## Operátory

- ^ = XOR
- | = OR
- & = AND
- ∼ Bitové NOT ∼x 1 pokud x je rovno 0 (bit po bitu).
- `<<` Posun vlevo x << y Posun x o y bitů vlevo. (nižší priorita než aritmetika)
- `>>` Posun vpravo x >> y Posun x o y bitů vpravo. (nižší priorita než aritmetika)


## Pole
= více hodnot stejného typu hned za sebou v paměti
* statická velikost, neměnná
* pole se defaultně neinicializuje, po deklaraci obsahuje random hodnoty
* Nekontrolují se index-errory

### Pole variabilní délky
* velikost se určuje až při runtime
```c
int n;
int str[n]; // alokuje se pole délky n
```
* Nebezpečí přetečení/naplnění zásobníku

### Vícerozměrná pole
`int a[2] [3]` = řádek, sloupec

## Poiners
= proměnná, jejíž hodnota je adresa v paměti, na které je uložená jiná proměnná = nepřímé referecnování
* Pointery mají "typ" podle typu proměnné, na kterou ukazují, aby uchovaly informaci, kolik bytes za danou adresou se má číst
    * Díky tomu funguje pointerová aritmetika
`&` = Referenční operátor, vrací adresu, na které je proměnná uložená
`*p` = dereferenční operátor, hodnota uložená na adrese, ktrerá je uložená v p

`**p` = pointer na pointer

### Coding style
```c
char *a,*b; // definuje dva pointery
NULL = makro pro neplatnou/prázdnou adresu

```

## Textové řetězce
```c
char str[] = "abc"; //je string, samo se přidá '\0'
char s[] = {'d','e','f'} // je je  array charů , \0 se nepřidá
```

## Redirecting stdin/stdout/stderr

'>'	Redirects stdout to a file (overwrite)	ls > output.txt
'>>'	Redirects stdout to a file (append)	ls >> output.txt
'2>'	Redirects stderr to a file (overwrite)	ls non_existent 2> error.txt
'2>>'	Redirects stderr to a file (append)	ls non_existent 2>> error.txt
'&>'	Redirects both stdout and stderr to the same file	ls &> all_output.txt
'2>&1'	Redirects stderr to stdout (combines both outputs)	command > file 2>&1
'<'	Redirects stdin from a file	sort < data.txt
'<<'	Here-document redirection for multi-line input	cat << EOF
