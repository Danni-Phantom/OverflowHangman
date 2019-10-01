#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_hangman(int tries left);
char* guess_fill_in(char[] dictIn, char[] guess);
void autofill_in(char* fill_in);
void print_fill_in(char[] fill_in);
int check_phrase(char* fill_in, char[] dictIn, char[] guess);

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
    char [phrase_size] word = dict[phrase_num];
    for (char *p = word; *p; ++p) *p = tolower(*p);
    char [phrase_size] phrase_guess;
    int tries = 7;
    int pass = 0;

    char [phrase_size] fill_in;
    fill_in = autofill_in(fill_in, word);

    printf("Welcome to Hangman!");
    printf("Please guess a letter! If you would like to guess the phrase type \"Phrase\" followed by enter and you will be prompted for your guess!");

    scanf("%s", guess);
    if (guess == "Phrase") {
        scanf("%s", phrase_guess);
        for (char *p = phrase_guess; *p; ++p) *p = tolower(*p);
        int cmp = check_phrase(fill_in, word, phase_guess);
        if (cmp != 0) {
            tries -= 3;
            printf("You're not a good person. You know that, right? [-3 tries]" + tries + "remaining.");
            print_hangman(tries);
            print_fill_in(fill_in);


        }


    } else {
        printf("You guessed the char: %c", guess[0]);
        // some function to check the character
        // if (char exists in code)
        // print "Unbelievable You, \"Subject Name Here\", must be the pride of \"Subject Hometown Here\"
        // else
        // print "I feel sorry for you, really, because you're not even in the right place"
    }

}

// Checks if the phrase guess is complete? Not sure if needed, but ehhhhh
int check_phrase(char* fill_in, char[] dictIn, char[] guess) {
    int size = sizeof(dictIn)/ sizeof(char);
    int flag = 0;
    for (int a = 0; a < size; a++){
        if (guess[a] != dictIn[a]) {
            flag = 1;
            break;
        }
    }

    for (int a = 0; a < size; a++) {
        guess_fill_in(fill_in, dictIn, guess[a]);
    }

    return flag;
}

// Print the blanks and filled in characters
void print_fill_in(char[] fill_in) {
    s = sizeof(fill_in)/sizeof(char);
    for (int a = 0; a < s; a++) {
        printf(fill_in[a] + " ");
    }
}

// this fills in the characters from the phrase
char* guess_fill_in(char* fill_in, char[] dictIn, char[] guess) {
    s = sizeof(dictIn)/sizeof(char);
    for (int a = 0; a < s; a++) {
        if (dictIn[a] == guess) {
            fill_in[a] = guess;
        }
    }
}

// This fills in all Punctuation or Spaces
void autofill_in(char* fill_in, char[] dictIn) {
    int phrase_size = sizeof(fill_in)/sizeof(char);
    for (int a = 0; a < fill_in; a++) {
        if (dictIn[a] == ' ') {
            fill_in[a] = ' ';
        } else if (dictIn[a] == '-') {
            fill_in[a] = '-';
        } else if (dictIn[a] == '?') {
            fill_in[a] = '?';
        }  else if (dictIn[a] == '\'') {
            fill_in[a] = '\'';
        }  else {
            fill_in[a] = '_';
        }
    }
}

// prints the hanged man
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