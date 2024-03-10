#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ceasarEncrypts(char givenCharacter, char givenBase, long givenKey);

int main(int argc, string argv[]){ 
    if (argc == 1){
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }else if (atoi(argv[1]) <= 0){
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }else if (argc > 2){
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }else{
        long key = atoi(argv[1]);
        string plainText = get_string("PlainText:  ");
        int plainTextLenght = strlen(plainText);
        char base;
        
        for (int i = 0; i < plainTextLenght; i++){
            if (!isalpha(plainText[i])){
                continue;
            }else if (isupper(plainText[i])){
                base = 'A';
                plainText[i] = ceasarEncrypts(plainText[i],base,key);
            }else if (islower(plainText[i])){
                base = 'a';
                plainText[i] = ceasarEncrypts(plainText[i],base,key);
            }
        }
        printf("CipherText: %s\n",plainText);
        return 0;
    }
}

// FUNCTIONS
char ceasarEncrypts(char givenCharacter, char givenBase, long givenKey){
    return (givenCharacter - givenBase + givenKey) % 26 + givenBase;
}