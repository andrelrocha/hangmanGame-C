#include <stdio.h>
#include <string.h>

//variaveis globais
char secretWord[20];
char chutes[26];
int chutesDados = 0;

void abertura() {
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou (char letra) {
    int achou = 0;
    for (int j = 0; j < chutesDados; j++) {
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

int enforcou() {
    int erros = 0;

    for (int i = 0; i < chutesDados; i++) {
        int existe = 0;

        for (int j = 0; j < strlen(secretWord); j++) {
            if (chutes[i] == secretWord[j]) {
                existe = 1;
                break;
            }
        }

        if (!existe) erros++;
        
    }

    return erros >= 5;
}

int main ()
{
    
    int acertou = 0;

    escolhePalavra();
    abertura();

    do {
        
        desenhaForca();
        chuta();

    } while (!acertou && !enforcou());
}