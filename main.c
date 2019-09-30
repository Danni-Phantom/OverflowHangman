#include <stdio.h>

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