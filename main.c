#include "stdio.h"
#include "stdlib.h"
#include <ctype.h> // for example: isdigit()
#include <stdbool.h>

#define MAXWORD 20
#define MAXTRIES 100
#define CLEARSCREEN system("cls||clear");

int my_getline(char line[], int lim);
bool str_eq(char s1[], char s2[], int max_size);
void stolower(char s1[], int len);
void print_guessed_letters(bool letters_guessed[]);

void print_guessed_word(bool letters_guessed[], char s[], int s_len) {
    for(int i = 0; i < s_len; i++) {
        if(s[i] == ' ') 
            printf(" ");
        else if(letters_guessed[s[i] - 'a'])
            printf("%c", s[i]);
        else
            printf("_");
    }
    printf("\n");
}

int main() {
    CLEARSCREEN
    printf("Enter secret text: ");
    char s[MAXWORD];
    int s_len = my_getline(s, MAXWORD);
    printf("Your word is: %s with length = %d\npress Enter to continue", s, s_len);
    getchar();
    CLEARSCREEN    

    bool guessed = false;
    bool letters_guessd[26] = {0};
    int num_of_tries = 0;
    char guess[MAXWORD];
    int guess_len;

    while(!guessed) {
        if(num_of_tries++ >= MAXTRIES) 
            break;
        printf("Your guess: \n");
        print_guessed_word(letters_guessd, s, s_len);
        printf("Letters you guessed: \n");
        print_guessed_letters(letters_guessd);
        printf("Enter a letter or a word: ");

        switch((guess_len = my_getline(guess, MAXWORD))) {
            case 1:
                printf("give a word u dumbass\n");
            break;
            case 2:
                //printf("%c", guess[0]);
                letters_guessd[guess[0] - 'a'] = true;
            break;
            default:
                printf("A word!\n");
        }
        CLEARSCREEN
    }

    return 0;
}

/* getline: read a line into line, return its length*/
int my_getline(char line[], int lim) {
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if(c == '\n') {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';

    return i;
}

/* str_eq: checks if two strings are equal, returns 1 if they are
 * larger_size - size of larger of the strings*/
bool str_eq(char s1[], char s2[], int larger_size) {
    int i;

    for(i = 0; i < larger_size; i++)
        if(s1[i] != s2[i])
            return false;

    return true; 
}

void print_guessed_letters(bool guessed_letters[]) {
    for(int i = 0; i < 26; i++) {
        char bar = (i == 25) ? ' ' : '|';
        if(guessed_letters[i])
            printf("%c %c ", ('a' + i), bar);
        else 
            printf("_ %c ", bar);
    }
    printf("\n");
}
