#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char input[100];  // Assuming a maximum input string length of 100 characters
int position;     // Global variable to keep track of the current position in the input

// Function prototypes
bool parseS();
bool parseSPrime();
bool parseA();
bool parseAPrime();

void error(int pos) {
    printf("\nError at position %d\n", pos);
}

bool match(char expected) {
    if (input[position] == expected) {
        position++;
        return true;
    }
    return false;
}

bool parseS() {
    int start_pos = position;
    printf("S -> ");

    if (match('c') && parseA() && parseSPrime()) {
        printf("cAS'\n");
        return true;
    }

    error(start_pos);
    return false;
}

bool parseSPrime() {
    int start_pos = position;
    printf("S' -> ");

    if (match('d')) {
        printf("d\n");
        return true;
    } else {
        printf("epsilon\n");
        return true;
}

    error(start_pos);
    return false;
}

bool parseA() {
    int start_pos = position;
    printf("A -> ");

    if (match('a') && parseAPrime()) {
        printf("aA'\n");
        return true;
    }

    error(start_pos);
    return false;
}

bool parseAPrime() {
    int start_pos = position;
    printf("A' -> ");

    if (match('b')) {
        printf("b\n");
        return true;
    } else {
        printf("epsilon\n");
        return true;
    }

    error(start_pos);
    return false;
}

int main() {
    strcpy(input, "cad"); // Test input string "cad"
    position = 0;
    printf("Parsing input: %s\n", input);

    if (parseS() && position == strlen(input)) {
        printf("\nInput string accepted!\n");
    } else {
        printf("\nInput string rejected!\n");
    }

    strcpy(input, "cat"); // Test input string "cat"
    position = 0;
printf("\nParsing input: %s\n", input);

    if (parseS() && position == strlen(input)) {
        printf("\nInput string accepted!\n");
    } else {
        printf("\nInput string rejected!\n");
    }

    return 0 ;
}
