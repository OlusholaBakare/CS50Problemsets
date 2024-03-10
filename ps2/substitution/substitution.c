#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char substitutionEncrypts(char givenCharacter, char givenBase, string givenKey);

int main(int argc, string argv[]){
    // Making sure the command line argument is 1 string and the string is 26 characters long 
    if (argc == 1){
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }else if (argc > 2){
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }else if (strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Getting the key
    string key = argv[1];

    // Getting the plaintext
    string plainText = get_string("PlainText:  ");

    // Looping through the plaintext to encrypt each character according to the key
    char base;
    char currentChar;
    for (int i = 0; i < 26; i++){
        if (islower(plainText[i])){
            base = 'a';
            currentChar = substitutionEncrypts(plainText[i],base,key);

            // Making sure the character stays in the same case as the original plaintext 
            plainText[i] = tolower(currentChar);
        }else if (isupper(plainText[i])){
            base = 'A';
            currentChar = substitutionEncrypts(plainText[i],base,key);

            // Making sure the character stays in the same case as the original plaintext 
            plainText[i] = toupper(currentChar);
        } 
    }

    // Printing out the resulting ciphertext
    printf("CipherText: %s\n",plainText);
}

// FUNCTIONS
char substitutionEncrypts(char givenCharacter, char givenBase, string givenKey){
    // Subtract the ascii value of the character before the base from the ascii value of the given character to get the aphabetical mapping of the of the character on a 1 to 26 scale
    char alphabeticalMapping = givenCharacter - (givenBase - 1);

    // Subtract the result from one to since computers deal with strings in zero indexed manner
    alphabeticalMapping--;

    // Get the corresponding value in the key and return it
    return givenKey[alphabeticalMapping];
}