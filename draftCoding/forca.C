#include <stdio.h>

int main (void)
{
    char secretWord[10] = "Apple";
    char secretWord2[20];
    sprintf(secretWord2, "Pineapple");
    printf("%s\n", secretWord2);
    printf("%s", secretWord);
};