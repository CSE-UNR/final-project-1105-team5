
// Evan Barnett / Ian Lane / name
// 12-10-2024
// Madlibs Final Project


#include <stdio.h>

#define MADLIB "madlib1.txt"
#define ROWS 25
#define COLUMNS 100

// Function prototypes
void Read(FILE* fptr, int width, char lib[][width]);
void Display(char lib[][COLUMNS], int rows);
void Replace(char lib[][COLUMNS], int rows);
void userInput(char prompt, char* input);

int main() {
    char lib[ROWS][COLUMNS];
    FILE* fptr;
    
    fptr = fopen(MADLIB, "r");

    if (fptr == NULL) {
        printf("Could not access file\n");
        return 0;
    }

    Read(fptr, COLUMNS, lib);  
    fclose(fptr);

    Replace(lib, ROWS);  
    Display(lib, ROWS); 

    return 0;
}

// Reads the madlib file and stores content into 2D array
void Read(FILE* fptr, int width, char lib[][width]) {
    for (int i = 0; i < ROWS; i++) {
        fgets(lib[i], width, fptr);
    }
}

// Displays madlib
void Display(char lib[][COLUMNS], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("%s", lib[i]);
    }
}
// Prompts the user for input based on the placeholder type and updates the content in lib
void userInput(char prompt, char* input) {
    char userWord[COLUMNS];

    if (prompt == 'A') {
        printf("Please enter an adjective: ");
    } else if (prompt == 'N') {
        printf("Please enter a noun: ");
    } else if (prompt == 'V') {
        printf("Please enter a verb: ");
    }

    fgets(userWord, COLUMNS, stdin);

    // Replace placeholder with the user input
    int i = 0;
    while (userWord[i] != '\0' && i < COLUMNS) {
        *input = userWord[i];  // Replace character one by one
        
        input++;
        i++;
    }
    *input = ' ';
    input++;
    *input = '\0';  
}

// Replaces placeholders with user input
void Replace(char lib[][COLUMNS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            
            if (lib[i][0] == 'A' || lib[i][0] == 'N' || lib[i][0] == 'V') {
               
                userInput(lib[i][j], &lib[i][j]);
            }
        }
          
    }
    
}











