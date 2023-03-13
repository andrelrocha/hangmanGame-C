#include <stdio.h>
#include <string.h>

int main ()
{
    char secretWord[20];
    sprintf(secretWord, "pineapple");
    
    int acertou = 0;
    int enforcou = 0;

    do {
        
        for (int i = 0; i < strlen(secretWord); i++) {
            printf("_ ");
        }
        printf("/n");

        char chute;
        scanf("%c", &chute);
    } while (!acertou && !enforcou); {
        acertou = 1;
    }
}