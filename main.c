#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_hangman(int tries left);
char* guess_fill_in(char[] dictIn, char[] guess);
void autofill_in(char* fill_in);

int main(void) {

    char *dict[5];
    char [6] guess;
    dict[0] = "Cake is a lie";
    dict[1] = "This statement is false - Glados";
    dict[2] = "bug = undocumented feature";
    dict[3] = "I'm a potato";
    dict[4] = "Are you still there?";

    int phrase_num = rand()%(4-0 + 1) + 0;
    int phrase_size = sizeof(dict[phrase_num])/ sizeof(char);
    char [phrase_size] phrase_guess;
    int tries = 7;
    int pass = 0;

    char [phrase_size] fill_in;
    fill_in = autofill_in(fill_in);

    printf("Welcome to Hangman!");
    printf("Please guess a letter! If you would like to guess the phrase type \"Phrase\" followed by enter and you will be prompted for your guess!");

    scanf("%s", guess);
    if (guess == "Phrase") {
        scanf("%s", phrase_guess);
        int cmp = strcmp(dict[phrase_num], phrase_guess);
        if (cmp != 0){

            tries -= 3;
            printf("You're not a good person. You know that, right? [-3 tries]" + tries + "remaining.");
            print_hangman(tries);
            
            for (int i = 0; i < phrase_size; i++) {
                for (int j = 0; j < phrase_size; j++) {



                }
            }

        }



    } else if() {
        // Letter guess
    } else {
        // error
    }

}
// this fills in the characters from the phrase
char* guess_fill_in(char[] dictIn, char[] guess) {


}

// This fills in all Punctuation or Spaces
void autofill_in(char* fill_in) {

}

void print_hangman(int tries_left) {
    if (tries_left > 7) {
        tries_left = 7;
    }
    switch (tries_left) {
        case 7:
            puts("┏━━━╤━");
            puts("┃┃    ");
            puts("┃┃");
            puts("┃┃");
            puts("┃┃");
            puts("┻┻━━━━━━━");
            break;
        case 6:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃");
            puts("┃┃");
            puts("┃┃");
            puts("┻┻━━━━━━━");
            break;
        case 5:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃  | ");
            puts("┃┃    ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 4:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲| ");
            puts("┃┃    ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 3:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃    ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 2:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃  | ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 1:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃  | ");
            puts("┃┃ ╱  ");
            puts("┻┻━━━━━━━");
            break;
        case 0:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃  | ");
            puts("┃┃ ╱ ╲");
            puts("┻┻━━━━━━━");
            break;
    }
}