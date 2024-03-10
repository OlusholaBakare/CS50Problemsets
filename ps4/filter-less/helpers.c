#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int currentGrayValue;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            currentGrayValue = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = currentGrayValue;
            image[i][j].rgbtGreen = currentGrayValue;
            image[i][j].rgbtBlue = currentGrayValue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int currentSepiaValueRed;
    int currentSepiaValueGreen;
    int currentSepiaValueBlue;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            currentSepiaValueRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            currentSepiaValueGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            currentSepiaValueBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            currentSepiaValueRed > 255 ? currentSepiaValueRed = 255 : 0;
            currentSepiaValueGreen > 255 ? currentSepiaValueGreen = 255 : 0;
            currentSepiaValueBlue > 255 ? currentSepiaValueBlue = 255 : 0;

            image[i][j].rgbtRed = currentSepiaValueRed;
            image[i][j].rgbtGreen = currentSepiaValueGreen;
            image[i][j].rgbtBlue = currentSepiaValueBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int currentTempValue;
    int alternateIndex;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width / 2; j++){
            alternateIndex = width - j;

            currentTempValue = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][alternateIndex].rgbtRed;
            image[i][alternateIndex].rgbtRed = currentTempValue;
            
            currentTempValue = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][alternateIndex].rgbtGreen;
            image[i][alternateIndex].rgbtGreen = currentTempValue;

            currentTempValue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][alternateIndex].rgbtBlue;
            image[i][alternateIndex].rgbtBlue = currentTempValue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++){
                for (int dj = -1; dj <= 1; dj++){
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width){
                        sumRed += image[ni][nj].rgbtRed;
                        sumGreen += image[ni][nj].rgbtGreen;
                        sumBlue += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            temp[i][j].rgbtRed = sumRed / count;
            temp[i][j].rgbtGreen = sumGreen / count;
            temp[i][j].rgbtBlue = sumBlue / count;
        }
    }

    // Copy the blurred result back to the original image
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
    
