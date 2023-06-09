#include <stdio.h>
#include <string.h>

void abertura() {
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n\n");
}

void chuta(int* tentativas, char chutes[26]) {
    char chute;
    scanf(" %c", &chute);

    chutes[*tentativas] = chute;
    (*tentativas)++;
}

int jaChutou (char letra, char chutes[26], int tentativas) {
    int achou = 0;
    for (int j = 0; j < tentativas; j++) {
            if (chutes[j] == letra) {
                achou = 1; 
                break;
            }
        }
    return achou;
}

int main ()
{
    char secretWord[20];
    sprintf(secretWord, "pineapple");
    
    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do {
        
        for (int i = 0; i < strlen(secretWord); i++) {

            int achou = jaChutou(secretWord[i], chutes, tentativas);

            if (achou) {
                printf("%c ", secretWord[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        chuta(&tentativas, chutes);

    } while (!acertou && !enforcou);
}