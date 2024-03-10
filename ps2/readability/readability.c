#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countLetters(string givenText,int givenTextLenght);
int countWords(string givenText,int givenTextLenght);
int countSentenes(string givenText,int givenTextLenght);
int colemanLiauIndex (float givenL, float givenS);

int main(void){
    // Getting the text the user gives and the lenght of the text
    string text = get_string("Text: ");
    int textLenght = strlen(text);

    // Getting the number of letters, words and sentences in the text
    float letters = countLetters(text,textLenght);
    float words = countWords(text,textLenght); 
    float sentences = countSentenes(text,textLenght);

    // Getting the number of letters per 100 words (L) and sentences per 100 words (S) using the formula (x / words) * 100
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;

    // Getting the Coleman-Liau index using the formula index = 0.0588 * L - 0.296 * S - 15.8
    int index = colemanLiauIndex(L,S);

    // Printing the approximate grade level needed to comprehend the text
    if (index < 1){
        printf("Before Grade 1\n");
    }else if (index >= 16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %i\n",index);
    }
}

// FUNCTIONS
int countLetters(string givenText,int givenTextLenght){
    int numOfLetters = 0;
    for (int i = 0; i < givenTextLenght; i++){
        isalpha(givenText[i]) ? numOfLetters++ : 0;
    }
    return numOfLetters;
}

int countWords(string givenText,int givenTextLenght){
    int numOfWords = 1;
    for (int i = 0; i < givenTextLenght; i++){
        isspace(givenText[i]) ? numOfWords++ : 0;
    }
    return numOfWords;
}

int countSentenes(string givenText,int givenTextLenght){
    int numOfSentences = 0;
    for (int i = 0; i < givenTextLenght; i++){
        givenText[i] == '.' || givenText[i] == '?' || givenText[i] == '!' ? numOfSentences++ : 0;
    }
    return numOfSentences;
}

int colemanLiauIndex (float givenL,float givenS){
    int index = round(0.0588 * givenL - 0.296 * givenS - 15.8);
    return index;
}