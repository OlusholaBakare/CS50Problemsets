#include <cs50.h>
#include <stdio.h>

void printspace(int space);
void printhash(int hash);

/**
 * Prints a pyramid pattern based on user input.
 *
 * @returns None
 */
int main(void){
    // get the user input
    int number;
    do{
        number = get_int("Height(1-8): ");
    }while (number < 1 || number > 8);

    // Initialize the hash variable since the top of the pyramid will always be one hash and the rest will be spaces
    int hash = 1;
    int space = number - 1;

    // print the spaces and decrease them, print the hashes and increase them until the number is 0 and do the reverse two spaces later
    while(number != 0){
        printspace(space);
        printhash(hash);

        printf("  ");

        printhash(hash);
        printspace(space);
        
        space--;
        hash++;
        printf("\n");
        number--;
    }
}

void printspace(int space){
    for(int i = 0; i < space; i++){
        printf(" ");
    }
}
void printhash(int hash){
    for(int i = 0; i < hash; i++){
        printf("#");
    }
}
    