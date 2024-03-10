#include <cs50.h>
#include <stdio.h>

void printspaceOrDot(int spaceOrDot,int option);
void printhash(int hash);

/**
 * Prints a pyramid of a specified height and style.
 *
 * @returns None
 */
int main(void){
    // get the user input
    int number;
    do{
        number = get_int("Height(1-8): ");
    }while (number < 1 || number > 8);

    // get the preference of the user
    printf("What style do you want your pyramid to be,\nHere are the options:\n1 for left-aligned\n2 for right-aligned\n3 for dots instead of spaces\n");
    int select;
    do{
       select = get_int("Enter a number to select an option: "); 
    }while (select < 1 || select > 3);

    // Initialize the hash variable since the top of the pyramid will always be one hash and the rest will be spaces
    int hash = 1;
    int spaceOrDot = number - 1;

    // print the spaces or dots and decrease them, print the hashes and increase them until teh number is 0
    if(select == 1){
        while(number != 0){
            printspaceOrDot(spaceOrDot,1);
            spaceOrDot--;

            printhash(hash);
            hash++;

            printf("\n");
            number--;
        }
    }else if(select == 2){
        while(number != 0){
            printhash(hash);
            hash++;

            printspaceOrDot(spaceOrDot,1);
            spaceOrDot--;

            printf("\n");
            number--;
        }
    }else if (select == 3){
         while(number != 0){
            printspaceOrDot(spaceOrDot,0);
            spaceOrDot--;

            printhash(hash);
            hash++;

            printf("\n");
            number--;
        }
    }
}
void printspaceOrDot(int spaceOrDot,int option){
    if (option == 0){
        for(int i = 0; i < spaceOrDot; i++){
            printf(".");
        }
    }else{
        for(int i = 0; i < spaceOrDot; i++){
            printf(" ");
        }
    }; 
}
void printhash(int hash){
    for(int i = 0; i < hash; i++){
        printf("#");
    }
}