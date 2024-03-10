#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validateNumber(string i);
void addingtoaddednums(int num, int addednums);
void addingtodoublednums(int num, int doublednums);

// Main Fuction

int main(void){
    /**
     * Validates a credit card number.
     *
     * @returns None
     */
	long cardNumber = get_long("Number: ");
	char cardString[20];
    sprintf(cardString, "%li", cardNumber);

	validateNumber(cardString);
}

// Surbodinate functions

void validateNumber(string i){
    /**
     * Validates a credit card number and determines its type.
     *
     * @param i The credit card number as a string.
     *
     * @returns None
     */
    string type;
	if (strlen(i) == 15 && (strncmp(i, "34", 2) == 0 || strncmp(i, "37", 2) == 0)){
        type = "AMEX"; 
    } else if (strlen(i) == 16 && (strncmp(i, "51", 2) == 0 || strncmp(i, "52", 2) == 0 || strncmp(i, "53", 2) == 0 || strncmp(i, "54", 2) == 0 || strncmp(i, "55", 2) == 0) || strncmp(i, "22", 2) == 0){
        type = "MASTERCARD";
    } else if ((strlen(i) == 13 || strlen(i) == 16) && (strncmp(i, "4", 1) == 0)){
        type = "VISA";
    } else {
        type = "INVALID";
    }  

    if (type == "INVALID"){
        printf("%s\n",type);
        return;
    } else {
        int lenght = strlen(i);
        int addednums = 0;
        int doublednums = 0;
        int number;
        
        if (lenght % 2 == 0){
            for (int j = 0; j < lenght; j++){
                if (j == 0 || j % 2 == 0){
                    number = i[j] - '0';
                    addingtodoublednums(number,doublednums);
                }else {
                    number = i[j] - '0';
                    addingtoaddednums(number,addednums);
                }
                
            }   
        }else {
            for (int j = 0; j < lenght; j++){
                if (j == 0 || j % 2 == 0){
                    number = i[j] - '0';
                    addingtoaddednums(number,addednums);
                }else {
                    number = i[j] - '0';
                    addingtodoublednums(number,doublednums);
                }
                
            }  
        } 
        
        int TotalSum = addednums + doublednums;
        int validity = TotalSum % 10;
        if (validity == 0){
            printf("%s\n",type);
        }
    }
}


void addingtoaddednums(int num, int addednums){
    /**
     * Adds a number to the existing sum of numbers.
     *
     * @param num The number to be added.
     * @param addednums The current sum of numbers.
     *
     * @returns None
     */
    addednums = addednums + num;
}


void addingtodoublednums(int num, int doublednums){
    /**
     * Adds the doubled value of a number to another number.
     *
     * @param num The number to be doubled and added.
     * @param doublednums The number to which the doubled value is added.
     *
     * @returns None
     */
    int firstdigit;
    int secondDigit;
    num = num * 2;
    if (num <= 9){
        doublednums = doublednums + num;
    }else {
        firstdigit = num / 10;
        secondDigit = num % 10;
        num = firstdigit + secondDigit;
        doublednums = doublednums + num;
    }
}





