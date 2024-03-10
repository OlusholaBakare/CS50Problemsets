#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

int asciiValue(char givenValue);
int binaryValue(int givenValue);
string format(int givenValue);
void print_bulb(int bit);

int main(void){
    // Get the string
    string Message = get_string("Message: ");

    // string lenght
    int stringLenght = strlen(Message);

    // For every character in the string get the ascii value and then get the binary value and then print the corresponding bulb sequence
    int asciiNum;
    int binaryNum;
    string _8BitBinaryNum;
    for (int i = 0; i < stringLenght; i++){
        // getting the ascii value
        char character = Message[i];
        asciiNum = asciiValue(character);

        // getting the Binary value
        binaryNum = binaryValue(asciiNum);

        // getting the 8 bit formatted output
        _8BitBinaryNum = format(binaryNum);

        // printing the coresponding bulb sequence 
        for (int i = 0; i < 8; i++){
            if (_8BitBinaryNum[i] == '0'){
                print_bulb(0);
            }else if (_8BitBinaryNum[i] == '1'){
                print_bulb(1);
            }
        }
        printf("\n");
    }
}

// Functions

int asciiValue(char givenValue){
    int asciicorrespondent = givenValue;
    return asciicorrespondent;
}

int binaryValue(int givenValue){
    int BinaryNumbers[8];
    int n = 0;
    while (givenValue >= 1){
        BinaryNumbers[n] = givenValue % 2;
        n++;
        givenValue = givenValue / 2;
    } 
    char stringOfBinaryNumbers[9];
    stringOfBinaryNumbers[0] = '\0';
    char tempString[2];
    tempString[0] = '\0';
    for (int i = n - 1; i >= 0; i--){
        sprintf(tempString,"%i",BinaryNumbers[i]);
        strcat(stringOfBinaryNumbers,tempString);
    }
    return atoi(stringOfBinaryNumbers);
}

string format(int givenValue) {
    char eightBits[9];
    eightBits[0] = '\0';
    int numberOfnumbers;
    int numOfRequiredZeros;
    char varOfZeros[9];
    varOfZeros[0] = '\0';
    char *formattedValue = NULL; // Dynamically allocated memory

    sprintf(eightBits, "%i", givenValue);
    numberOfnumbers = strlen(eightBits);
    numOfRequiredZeros = BITS_IN_BYTE - numberOfnumbers;

    int n = 0;
    char tempZeroSpace[2];
    tempZeroSpace[0] = '\0';
    for (int i = 0; i < numOfRequiredZeros; i++) {
        sprintf(tempZeroSpace, "%i", n);
        strcat(varOfZeros, tempZeroSpace);
    }

    // Allocate memory for formattedValue
    formattedValue = (char *)malloc(strlen(varOfZeros) + strlen(eightBits) + 1);

    if (formattedValue != NULL) {
        strcpy(formattedValue, varOfZeros);
        strcat(formattedValue, eightBits);
    }

    return formattedValue;
}


void print_bulb(int bit){
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
