# PRGC 
Nezapomeň ;

## Header files/libraries/includes
- <stdlib.h>
- <stdio.h> = standard input & output
    - `printf("text, %d", intVal)`
    - `scanf("%d", &intVal)` 
        - načení vstupu, pomocí format modifier určíme načítaný datatyp a uložíme do proměnné podle adresy (&)
        - neumí načíst víc slov (skončí když mezera nebo \n )
        - " %d" - odignoruje whitespace před hledaným vstupem 
    - `fgets(varName, sizeof(varName), stdin)`
        - `getchar(void)` - užitečné, pokud z předchozích vstupů zůstává ve frontě \n. Tato funkce ho načte a tedy odstraní
        - načtení řádku z textového vstupu
- <string.h>
    - přidává funkce pro práci se stringy
    - `strlen(name)` - vrací délku stringu
- <math.h>
    - počítání
    - `sqrt()`,`pwr(x,pwr)`

- <stdbool.h> = importuje datatyp bool

## Variables

```c
char pismeno = 'a'; // 1b
char jmeno[] = "takhle se v c dělá string";
// pro char jsou '' závorky, pro string ""
int cislo = 42; // 4b
float pi = 3.141592f; // 4b
double e = 2.7116811354; // 8b
bool anoNe = true; // vyžaduje include <stdbool.h>,
bool n = 0; // 1b
```

## Format specifiers
Určují jak se zobrazují a interpretují hodnoty 
<br>

- %.nd = určení přesnosti na n desetinných míst (pokud jich má číslo víc než je nastaveno, zaokrouhlí se)
- %pd = určení minimálního počtu znaků, které má číslo zabírat, pokud je číslo kladné, "doplňkové mezery" se dávají před číslo, pokud záporné, za číslo
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

