// Evan Barnett / name / name
// 12-10-2024
// Madlibs Final Project

#define MADLIB "madlib1.txt"
#define ROWS 25
#define COLUMNS 100

#include <stdio.h>

void Read(FILE* fptr, int width, char lib[][width]);
void Subs(FILE* fptr, int width, char lib[][width]);
int main() {
    char lib[ROWS][COLUMNS];
    char lib2[ROWS]; 
    FILE* fptr;
    
    fptr = fopen(MADLIB, "r"); 

    if (fptr == NULL) {
        printf("Could not access file\n");
        return 0;  
       }

Subs(fptr, COLUMNS, lib);

    fclose(fptr);

    return 0;
}
//Reads file and stores in 2d array "lib"
void Read(FILE* fptr, int width, char lib[][width]) {

    for (int i = 0; i < ROWS; i++) {
        fgets(lib[i], width, fptr);
       
  }
}
//calls 2d array "lib" and pulls out all A,N,V that need to be subbed
void Subs(FILE* fptr, int width, char lib[][width]){
char store[ROWS];
Read(fptr, width, lib);

for(int i = 0; i < ROWS; i++){
	if( i %2 != 0){
	
                store[i] = lib[i][0];    
                printf("%c", store[i]);  
		}
	}
}















