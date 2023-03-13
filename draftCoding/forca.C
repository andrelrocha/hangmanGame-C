#include <stdio.h>
#include <string.h>

int main (void)
{
    char secretWord[20];
    sprintf(secretWord, "pineapple");
    
    int acertou = 0;
    int enforcou = 0;

    do {
        
        
        char chute;
        scanf("%c", &chute);

        for (int i = 0; i < strlen(secretWord); i++) {
            if (secretWord[i] == chute) {
                printf("A posicao %d tem essa letra.\n", i);
            }
        }
    } while (!acertou && !enforcou) {

    }

};