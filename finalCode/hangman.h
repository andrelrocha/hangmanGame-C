void opening();
void guess();
int rightGuess (char letter);
void drawHangman();
void addWord();
int wrongGuess();
void pickWord();
int correct();
int hanged();

#define WORD_SIZE 20

//global variables
char secretWord[WORD_SIZE];
char guesses[26];
int guessesTaken = 0;