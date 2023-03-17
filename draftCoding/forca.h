void abertura();
void chuta();
int jaChutou (char letra);
void desenhaForca();
void escolhePalavra();
int acertou();
int enforcou();
void adicionaPalavra();
int chutesErrados();

#define TAMANHO_PALAVRA 20

//variaveis globais
char secretWord[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;