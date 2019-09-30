#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_hangman(int tries left);

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

    printf("Welcome to Hangman!");
    printf("Please guess a letter! If you would like to guess the phrase type \"Phrase\" followed by enter and you will be prompted for your guess!");

    scanf("%s", guess);
    if (guess == "Phrase") {
        scanf
    }

}

void print_hangman(int tries_left) {
    if (tries_left > 7) {
        return;
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