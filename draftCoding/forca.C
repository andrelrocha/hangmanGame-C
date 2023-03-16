#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

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

void checaTxt(FILE* f) {
    if (f == 0) {
        printf("Desculpe, banco de dados não disponível.\n\n");
        exit(1); 
    }
}

void adicionaPalavra() {

    char deseja;

    printf("Você deseja adicionar uma nova palavra no jogo? (y/n)");
    scanf(" %c", &deseja);
    if (deseja == 'y') {
        char novaPalavra[20];
        printf("Qual a nova palavra?");
        scanf(" %s", novaPalavra);
    FILE* f;

    f = fopen("palavras.txt", "r+");
    checaTxt(f);


    int qtd;
    fscanf(f, "%d", &qtd);
    qtd++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "\n%d", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", novaPalavra);

    fclose(f);
        
    }
}

void escolhePalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    checaTxt(f);

    int qtdDePalavras;
    fscanf(f, "%d", &qtdDePalavras);

    srand(time(0));
    int randomico = rand() % qtdDePalavras;

    for (int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", secretWord);
    }

    fclose(f);
} 

int acertou() {
    for (int i = 0; i < strlen(secretWord); i++) {
        if (!jaChutou(secretWord[i])) {
            return 0;
        }
    }
    return 1;
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

    escolhePalavra();
    abertura();

    do {
        
        desenhaForca();
        chuta();

    } while (!acertou() && !enforcou());
}