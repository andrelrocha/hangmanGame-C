#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

void opening() {
    printf("***********************\n");
    printf("*    Hangman Game     *\n");
    printf("*   Guess the fruit   *\n");
    printf("***********************\n\n");
}

void guess() {
    char guess;
    scanf(" %c", &guess);

    guesses[guessesTaken] = guess;
    guessesTaken++;
}

int rightGuess (char letter) {
    int found = 0;
    for (int j = 0; j < guessesTaken; j++) {
            if (guesses[j] == letter) {
                found = 1; 
                break;
            }
        }
    return found;
}

void DrawHangman() {
    int errors = wrongGuess();
    int errorsSize = 5;

    printf("  _______      \n"); 
    printf(" |/      |     \n");

    char* hangmanParts[] = {
        " |      (_)    \n",
        " |      \\|/   \n",
        " |       |     \n",
        " |      / \\   \n"
    };

    if (errors != 0) {
        for (int i = 0; i < errorsSize; i++) {
            if (i < errors) {
                printf("%s", hangmanParts[i]);
            } else {
                printf(" |             \n");
            }
        }
    } else {
        for (int i = 0; i < errorsSize; i++) {
            printf(" |             \n");
        }
    }

    printf("_|___          \n"); 
    
    for (int i = 0; i < strlen(secretWord); i++) {

        int found = rightGuess(secretWord[i]);

        if (found) {
            printf("%c ", secretWord[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");

}

void checkTxt(FILE* f) {
    if (f == 0) {
        printf("Sorry, game's database is not available right now.\n\n");
        exit(1); 
    }
}

void addWord() {
    
    char want;

    printf("Do you want to add a new word to the game? (y/n)\n");
    scanf(" %c", &want);
    if (want == 'y') {
        char newWord[WORD_SIZE];
        printf("What's the new word?\n");
        scanf(" %s", newWord);
    
    FILE* f;

    f = fopen("fruits.txt", "r+");
    checkTxt(f);

    int amount;
    fscanf(f, "%d", &amount);
    amount++;

    // Go back to the beginning of the file and update the word count
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", amount);

    // Add the new word to the end of the file
    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", newWord);

    fclose(f);
    }
}

void pickWord() {
    FILE* f;

    f = fopen("fruits.txt", "r");
    checkTxt(f);

    int amountOfWords;
    fscanf(f, "%d", &amountOfWords);

    srand(time(0));
    int randomico = rand() % amountOfWords;

    for (int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", secretWord);
    }

    fclose(f);
} 

int correct() {
    for (int i = 0; i < strlen(secretWord); i++) {
        if (!rightGuess(secretWord[i])) {
            return 0;
        }
    }
    return 1;
}

int wrongGuess() {
    int errors = 0;

    for (int i = 0; i < guessesTaken; i++) {
        int exists = 0;

        for (int j = 0; j < strlen(secretWord); j++) {
            if (guesses[i] == secretWord[j]) {
                exists = 1;
                break;
            }
        }

        if (!exists) errors++;
        
    }

    return errors;
}

int hanged() {

    return wrongGuess() >= 5;
}

int main ()
{

    pickWord();
    opening();

    do {
        
        DrawHangman();
        guess();

    } while (!correct() && !hanged());

    if (correct()) {
        printf("\nExactly, the secret word was %s.\n\n", &secretWord);
        printf("Congrats, you won the game!!!\n\n");
        addWord();
    }  else {
        printf("Oh no. You were hanged, better luck next time.\n");
    }
}