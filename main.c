#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_hangman(int tries_left);
void printCompanionCube();
int printWord(char* guessedLetters, char* dictIn, int dictSize, int guesssedSize);
int isCharInPhrase(char letter, char* dictIn, int size);
int hasLetterBeenGuessed(char letter, char* guessed, int size);
void printGuessedLetters(char* guessed, int guessedLetterSize);
void printWordWithSpaces(char* word, int phrase_size);

int main(){
    char* dict[5];
    char guess[6];
    dict[0] = "cake is a lie";
    dict[1] = "this statement is false - glados";
    dict[2] = "bug = undocumented feature";
    dict[3] = "i'm a potato";
    dict[4] = "are you still there?";

    srand(time(NULL));
    int phrase_num = rand()%(4-0 + 1) + 0;
    char* plz = dict[phrase_num];
    int phrase_size = strlen(dict[phrase_num]);
    int guessedLetterCount = 0;

    char* word = malloc(phrase_size * sizeof(char));
    word = dict[phrase_num];
    char guessedLetters[26];
    int tries = 7;

    char phrase_guess[phrase_size+sizeof(char)];
    int* pass = phrase_guess+phrase_size;
    *pass = 0;
    phrase_guess[phrase_size] = '\0';

    
    printf("Welcome to Hangman!\n");
    printf("All guess should be using lowercase letters.\n");
    printWord(guessedLetters, word, phrase_size, guessedLetterCount);
    while (*pass != 100){
        printf("Please guess a letter! If you would like to guess the phrase type \"Phrase\" followed by enter and you will be prompted for your guess!\n");
        printGuessedLetters(guessedLetters, guessedLetterCount);
        print_hangman(tries);
        gets(guess);
        if (strcmp(guess,"Phrase") == 0 || strcmp(guess,"phrase") == 0) {
            printf("Make a guess: ");
            //scanf(" %[^\n]", phrase_guess);
            gets(phrase_guess);
            if (strcmp(phrase_guess, word) != 0) {
                tries -= 3;
                printf("The only thing you've managed to break so far is my heart. [-3 tries] %d remaining.\n", tries);
                //print_fill_in(fill_in);
            } else{
                printf("Unbelievable You, \"Subject Name Here\", must be the pride of \"Subject Hometown Here\"\n");
                *pass = 100;
                printWordWithSpaces(word, phrase_size);
                break;
            }

        } else if (guess[0] != '\0') {
            printf("You guessed the char: %c (or at least you didnt type in \"Phrase\", so we are using the first letter you input)\n", guess[0]);
            if (guess[0] < 97 || guess[0] > 122) {
                    tries-=1;
                    printf("You fail the test [you put in bad input, -1 because you don't follow instructions] %d tries remaining\n", tries);
                    printf("try again, but use lowercase characters a-z");
            } else if(isCharInPhrase(guess[0], word, phrase_size)) {
                if (hasLetterBeenGuessed(guess[0], guessedLetters, guessedLetterCount)){
                    tries -= 1;
                    printf("Good people don't end up here. [-1 tries for guessing something thats already been guessed] %d tries remaining\n", tries);
                } else {
                    guessedLetters[guessedLetterCount] = guess[0];
                    guessedLetterCount++;
                }
            } else {
                guessedLetters[guessedLetterCount] = guess[0];
                guessedLetterCount++;
                tries -= 1;
                printf("You don't even care. Do you? [-1 try] %d remaining.\n", tries);
            }
        } else{
            printf("Where are you? (unrecognized input, try again)\n");
        }

        if (tries <= 0){
            print_hangman(tries);
            printf("You don't have any friends because of how unlikable you are. [You lost]\n");
            return 1;
        }

        if (printWord(guessedLetters, word, phrase_size, guessedLetterCount)){
            *pass = 100;
        }

    }

    printf("We are throwing a party in honor of your tremendous success.\n");
    printCompanionCube();
}


int hasLetterBeenGuessed(char letter, char* guessed, int size){
    for (int ii = 0; ii < size; ii++){
        if (guessed[ii] == letter){
            return 1;
        }
    }
    return 0;
}

int isCharInPhrase(char letter, char* dictIn, int size){
    for (int ii = 0; ii < size; ii++){
        if (letter == dictIn[ii]){
            return 1;
        }
    }
    return 0;
}

void printWordWithSpaces(char* dictIn, int size){
    for(int ii = 0; ii < size; ii++){
        printf("%c ", dictIn[ii]);
    }
    printf("\n");
}

void printGuessedLetters(char* guessed, int guessedLetterSize){
    printf("Guessed Letters: [");
    for (int ii = 0; ii < guessedLetterSize; ii++){
        if (ii != 0){
            printf(", ");
        }
        printf("%c", guessed[ii]);
    }
    printf("]\n");
}

int printWord(char* guessedLetters, char* dictIn, int dictSize, int guessedSize){
    int notGuessed = 0;
    int complete = 1;

    if (guessedSize == 0){
        for(int ii = 0; ii < dictSize; ii++){
            if (dictIn[ii] == '=' || dictIn[ii] == '\'' || dictIn[ii] == '-' || dictIn[ii] == '?' || dictIn[ii] == ' '){
                printf("%c ", dictIn[ii]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
        return 0;
    }

    for (int ii = 0; ii < dictSize; ii++) {
        notGuessed = 1;
        for (int jj = 0; jj < guessedSize; jj++){
            if (guessedLetters[jj] == dictIn[ii]){
                printf("%c ", dictIn[ii]);
                notGuessed = 0;
                break;
            } else if (dictIn[ii] == '=' || dictIn[ii] == '\'' || dictIn[ii] == '-' || dictIn[ii] == '?' || dictIn[ii] == ' '){
                printf("%c ", dictIn[ii]);
                notGuessed = 0;
                break;
            }
        }
        if (notGuessed){
            printf("_ ");
            complete = 0;
        }
    }
    printf("\n");
    return complete;
}

void print_hangman(int tries_left) {
    if (tries_left > 7) {
        tries_left = 7;
    } else if (tries_left < 0){
        tries_left = 0;
    }
    switch (tries_left) {
        case 7:
            printf("  _______\n");
            printf("  |/\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
            break;
        case 6:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
            break;
        case 5:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |    |\n");
            printf("  |    |\n");
            printf("  |\n");
            printf("__|_________\n\n");
            break;
        case 4:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|\n");
            printf("  |    | \n");
            printf("  |\n");
            printf("__|_________\n\n");
            break;
        case 3:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |\n");
            printf("__|_________\n\n");
            break;
        case 2:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |   /\n");
            printf("__|_________\n\n");
            break;
        case 1:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |   / \\\n");
            printf("__|_________\n\n");
            break;
        case 0:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    X \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |   / \\\n");
            printf("__|_________\n\n");
            break;
    }
}

void printCompanionCube(){
    printf("The Enrichment Center reminds you that the Weighted Companion Cube will never threaten to stab you and, in fact, cannot speak\n");
    printf("+@##########M/             :@#########@/\n");
    printf("##############$;H#######@;+#############\n");
    printf("###############M########################\n");
    printf("##############X,-/++/+%%+/,%%#############\n");
    printf("############M$:           -X############\n");
    printf("##########H;.      ,--.     =X##########\n");
    printf(":X######M;     -$H@M##MH%%:    :H#######@\n");
    printf("  =%%#M+=,   ,+@#######M###H:    -=/M#%%\n");
    printf("  %%M##@+   .X##$, ./+- ./###;    +M##%%\n");
    printf("  %%####M.  /###=         @##M.   X###%%\n");
    printf("  %%####M.  ;M##H:.     =$###X.   $###%%\n");
    printf("  %%####@.   /####M$-./@#####:    %%###%%\n");
    printf("  %%H#M/,     /H###########@:     ./M#%%\n");
    printf(" ;$H##@@H:    .;$HM#MMMH$;,   ./H@M##M$=\n");
    printf("X#########%%.      ..,,.     .;@#########\n");
    printf("###########H+:.           ./@###########\n");
    printf("##############/ ./%%%%+/.-M ##############\n");
    printf("##############H$@#######@@##############\n");
    printf("##############X%%########M$M#############\n");
    printf("+M##########H:            .$##########X=\n");

}