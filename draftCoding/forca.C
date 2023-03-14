#include <stdio.h>
#include <string.h>

//variaveis globais
char secretWord[20];
char chutes[26];
int tentativas = 0;

void abertura() {
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jaChutou (char letra) {
    int achou = 0;
    for (int j = 0; j < tentativas; j++) {
            if (chutes[j] == letra) {
                achou = 1; 
                break;
            }
        }
    return achou;
}

void desenhaForca() {
    for (int i = 0; i < strlen(secretWord); i++) {

        int achou = jaChutou(secretWord[i]);

        if (achou) {
            printf("%c ", secretWord[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");

}

void escolhePalavra() {
    sprintf(secretWord, "pineapple");
} 

int main ()
{
    
    int acertou = 0;
    int enforcou = 0;

    escolhePalavra();
    abertura();

    do {
        
        desenhaForca();
        chuta();

    } while (!acertou && !enforcou);
}