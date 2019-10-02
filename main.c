#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_hangman(int tries_left);
char* guess_fill_in(char* fill_in, char* word, char guess);
void autofill_in(char* fill_in, char* word);
void print_fill_in(char* fill_in);
int check_phrase(char* fill_in, char* dictIn, char* guess);
void printCompanionCube();

int main(void) {

    char* dict[5];
    char guess[6];
    dict[0] = "Cake is a lie";
    dict[1] = "ThIs StaTEmEnt Is FaLSe - Glados";
    dict[2] = "bug = undocumented feature";
    dict[3] = "I'm a potato";
    dict[4] = "Are you still there?";

    printf("stop %s\n", dict[0]);

    srand(time(NULL));
    int phrase_num = rand()%(4-0 + 1) + 0;
    char* plz = dict[phrase_num];
    int phrase_size = strlen(dict[phrase_num]);

    char* word = malloc(phrase_size * sizeof(char));
    word = dict[phrase_num];
    //for (int i = 0; i < phrase_size; i++) word[i] = tolower(word[i]);

    char phrase_guess[phrase_size];
    //for (int i=0; i<phrase_size; i++) phrase_guess[i] = (char *)malloc(phrase_size * sizeof(char));

    int tries = 7;
    int pass = 0;

    char* fill_in = malloc(phrase_size* sizeof(char));

    autofill_in(fill_in, word);

    printf("Welcome to Hangman!");

    while (pass != 1){
        printf("Please guess a letter! If you would like to guess the phrase type \"Phrase\" followed by enter and you will be prompted for your guess!\n");
        scanf(" %s", guess);
        if (strcmp(guess,"Phrase") || strcmp(guess,"phrase")) {
            gets(phrase_guess);
            for (int i = 0; i < phrase_size; i++) phrase_guess[i] = tolower(phrase_guess[i]);

            int cmp = check_phrase(*fill_in, *word, *phrase_guess);
            if (cmp != 0) {
                tries -= 3;
                printf("You're not a good person. You know that, right? [-3 tries] %d remaining.\n", tries);
                print_hangman(tries);
                print_fill_in(*fill_in);

            }

        } else if (guess[1] == '\0') {
            printf("You guessed the char: %c", guess[0]);
            // some function to check the character
            // if (char exists in code)
            // print "Unbelievable You, \"Subject Name Here\", must be the pride of \"Subject Hometown Here\"
            // else
            // print "I feel sorry for you, really, because you're not even in the right place"

        } else {

        }

    }
}

// Checks if the phrase guess is complete? Not sure if needed, but ehhhhh
int check_phrase(char *fill_in, char *dictIn, char *guess) {
    int size = sizeof(dictIn)/ sizeof(char);
    int flag = 0;
    for (int a = 0; a < size; a++){
        if (guess[a] != dictIn[a]) {
            flag = 1;
            break;
        }
    }
    return flag;
}

// Print the blanks and filled in characters
void print_fill_in(char *fill_in) {
    int s = sizeof(fill_in)/sizeof(char);
    for (int a = 0; a < s; a++) {
        printf("%s ", fill_in[a]);
    }
}

// this fills in the characters from the phrase
char* guess_fill_in(char *fill_in, char *dictIn, char guess) {
    int s = sizeof(dictIn)/sizeof(char);
    for (int a = 0; a < s; a++) {
        if (dictIn[a] == guess) {
            fill_in[a] = guess;
        }
    }
}

// This fills in all Punctuation or Spaces
void autofill_in(char* fill_in, char *word) {
    int phrase_size = sizeof(fill_in)/sizeof(char);
    for (int a = 0; a < fill_in; a++) {
        if (word[a] == ' ') {
            fill_in[a] = ' ';
        } else if (word[a] == '-') {
            fill_in[a] = '-';
        } else if (word[a] == '?') {
            fill_in[a] = '?';
        } else if (word[a] == '\'') {
            fill_in[a] = '\'';
        } else if (word[a] == '='){
            fill_in[a] = '=';
        } else {
            fill_in[a] = '_';
        }
    }
}

void print_hangman(int tries_left) {
    if (tries_left > 7) {
        tries_left = 7;
    }
    switch (tries_left) {
        case 7:
            printf("┏━━━╤━\n");
            printf("┃┃    \n");
            printf("┃┃\n");
            printf("┃┃\n");
            printf("┃┃\n");
            printf("┻┻━━━━━━━\n");
            break;
        case 6:
            printf("┏━━━╤━\n");
            printf("┃┃  O \n");
            printf("┃┃\n");
            printf("┃┃\n");
            printf("┃┃\n");
            printf("┻┻━━━━━━━\n");
            break;
        case 5:
            printf("┏━━━╤━\n");
            printf("┃┃  O \n");
            printf("┃┃  | \n");
            printf("┃┃    \n");
            printf("┃┃    \n");
            printf("┻┻━━━━━━━\n");
            break;
        case 4:
            printf("┏━━━╤━\n");
            printf("┃┃  O \n");
            printf("┃┃ ╲| \n");
            printf("┃┃    \n");
            printf("┃┃    \n");
            printf("┻┻━━━━━━━\n");
            break;
        case 3:
            printf("┏━━━╤━\n");
            printf("┃┃  O \n");
            printf("┃┃ ╲|╱\n");
            printf("┃┃    \n");
            printf("┃┃    \n");
            printf("┻┻━━━━━━━\n");
            break;
        case 2:
            printf("┏━━━╤━\n");
            printf("┃┃  O \n");
            printf("┃┃ ╲|╱\n");
            printf("┃┃  | \n");
            printf("┃┃    \n");
            printf("┻┻━━━━━━━\n");
            break;
        case 1:
            printf("┏━━━╤━\n");
            printf("┃┃  O \n");
            printf("┃┃ ╲|╱\n");
            printf("┃┃  | \n");
            printf("┃┃ ╱  \n");
            printf("┻┻━━━━━━━\n");
            break;
        case 0:
            printf("┏━━━╤━\n");
            printf("┃┃  O \n");
            printf("┃┃ ╲|╱\n");
            printf("┃┃  | \n");
            printf("┃┃ ╱ ╲\n");
            printf("┻┻━━━━━━━\n");
            break;
    }
}

void printCompanionCube(){
    printf("The Enrichment Center reminds you that the Weighted Companion Cube will never threaten to stab you and, in fact, cannot speak\n");
//    printf("+@##########M/             :@#########@/\n");
//    printf("##############$;H#######@;+#############\n");
//    printf("###############M########################\n");
//    printf("##############X,-/++/+\%+/,\%#############\n");
//    printf("############M$:           -X############\n");
//    printf("##########H;.      ,--.     =X##########\n");
//    printf(":X######M;     -$H@M##MH%:    :H#######@\n");
//    printf("  =\%#M+=,   ,+@#######M###H:    -=/M#\%\n");
//    printf("  \%M##@+   .X##$, ./+- ./###;    +M##\%\n");
//    printf("  \%####M.  /###=         @##M.   X###\%\n");
//    printf("  \%####M.  ;M##H:.     =$###X.   $###\%\n");
//    printf("  \%####@.   /####M$-./@#####:    %###\%\n");
//    printf("  \%H#M/,     /H###########@:     ./M#\%\n");
//    printf(" ;$H##@@H:    .;$HM#MMMH$;,   ./H@M##M$=\n");
//    printf("X#########%.      ..,,.     .;@#########\n");
//    printf("###########H+:.           ./@###########\n");
//    printf("##############/ ./%%%%+/.-M#############\n");
//    printf("##############H$@#######@@##############\n");
//    printf("##############X\%########M$M#############\n");
//    printf("+M##########H:            .$##########X=\n");

}