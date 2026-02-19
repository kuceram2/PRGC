# include <stdio.h>
#include <string.h>

int main(){
    int age = 0;
    float floatAge = 0.0f;
    char name[30] = " ";
    char c = '\0';
    scanf("%d", &age);
    //getchar();
    //scanf("%lf", &floatAge);
    //scanf(" %s", &name);
    fgets(name,sizeof(name), stdin);
    // printf("\n");
    printf("%d\n", age);
    // printf("%lf\n", floatAge);
    //printf("%c\n", c);
    printf("%s", name);
    return 0;
}
