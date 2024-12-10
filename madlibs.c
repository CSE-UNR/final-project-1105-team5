
// Evan Barnett / Ian Lane / Tai. Calvin
// 12-10-2024
// Madlibs Final Project


#include <stdio.h>

#define MADLIB "madlib1.txt"
#define ROWS 25
#define COLUMNS 100

void Read(FILE* fptr, int width, char lib[][width]);
void Display(char lib[][COLUMNS], int rows);
void Replace(char lib[][COLUMNS], int rows);
void UserInput(char prompt, char* input);
void RemoveN(char lib[][COLUMNS], int rows, int columns);

int main(){
	char lib[ROWS][COLUMNS];
	FILE* fptr;
    
	fptr = fopen(MADLIB, "r");

	if (fptr == NULL){
        	printf("Could not access file\n");
	return 0;
	}

	Read(fptr, COLUMNS, lib);  
	fclose(fptr);

	RemoveN(lib, ROWS, COLUMNS);  
	Replace(lib, ROWS);  
	Display(lib, ROWS);  
	
	printf("\n");

	return 0;
}

// reads the madlib file and stores in 2d array
void Read(FILE* fptr, int width, char lib[][width]){
	for (int i = 0; i < ROWS; i++){
        	fgets(lib[i], width, fptr);
       
        	for (int j = 0; j < width; j++){
			if (lib[i][j] == '\n'){
                	lib[i][j] = '\0';
			break;  
			}
		}
	}
}

// displays madlib to screen
void Display(char lib[][COLUMNS], int rows){
	for (int i = 0; i < rows; i++){
		printf("%s", lib[i]);
		if(lib[i][0] = '\0'){
		break;
		}  
	}
}

// gets user input based on letter 
void UserInput(char prompt, char* input){
	char UserWord[COLUMNS];

	if (prompt == 'A'){
        printf("Please enter an adjective: ");
	}else if (prompt == 'N'){
        printf("Please enter a noun: ");
	}else if (prompt == 'V'){
        printf("Please enter a verb: ");
	}

	fgets(UserWord, COLUMNS, stdin);

    
	for (int i = 0; i < COLUMNS; i++){
	if (UserWord[i] == '\n'){
            UserWord[i] = '\0';
            
	break;
	}
	}
	int i = 0;
	*input = ' ';
	*input++;
	while (UserWord[i] != '\0' && i < COLUMNS){
        	*input = UserWord[i];  
        input++;
        i++;
	}

	*input = ' ';
	*input++;
	*input = '\0';
}

// replaces letters with user input
void Replace(char lib[][COLUMNS], int rows){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < COLUMNS; j++){
			if (lib[i][0] == 'A' || lib[i][0] == 'N' || lib[i][0] == 'V'){
                		UserInput(lib[i][j], &lib[i][j]);
			}
		}
	}
}

// removes newline characters to display nice on screen
void RemoveN(char lib[][COLUMNS], int rows, int columns){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			if (lib[i][j] == '\n'){
				lib[i][j] = '\0';  
				break;
			}
		}
	}
}












