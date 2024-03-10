#include "helpers.h"
#include <math.h>

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            
            int Gx = 0;
            int Gy = 0;
            int GxRed = 0;
            int GyRed = 0;
            int GxGreen = 0;
            int GyGreen = 0;
            int GxBlue = 0;
            int GyBlue = 0;
            int GTotal = 0;

            for (int di = -1; di <= 1; di++){
                for (int dj = -1; dj <= 1; dj++){
                    int ni = i + di;
                    int nj = j + dj;

                    if (di == -1 && dj == -1){
                        Gx = -1;
                        Gy = -1;
                    }else if (di == -1 && dj == 0){
                        Gx = 0;
                        Gy = -2;
                    }else if (di == -1 && dj == 1){
                        Gx = 1;
                        Gy = -1;
                    }else if (di == 0 && dj == -1){
                        Gx = -2;
                        Gy = 0;
                    }else if (di == 0 && dj == 0){
                        Gx = 0;
                        Gy = 0;
                    }else if (di == 0 && dj == 1){
                        Gx = 2;
                        Gy = 0;
                    }else if (di == 1 && dj == -1){
                        Gx = -1;
                        Gy = 1;
                    }else if (di == 1 && dj == 0){
                        Gx = 0;
                        Gy = 2;
                    }else if (di == 1 && dj == 1){
                        Gx = 1;
                        Gy = 1;
                    }
                    

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width){
                        

                        GxRed += image[ni][nj].rgbtRed * Gx;
                        GyRed += image[ni][nj].rgbtRed * Gy;

                        GxGreen += image[ni][nj].rgbtGreen * Gx;
                        GyGreen += image[ni][nj].rgbtGreen * Gy;

                        GxBlue += image[ni][nj].rgbtBlue * Gx;
                        GyBlue += image[ni][nj].rgbtBlue * Gy;
                    }
                }
            }

            GTotal = (GxRed * GxRed) + (GyRed * GyRed);
            GTotal = sqrt(GTotal);
            GTotal > 255 ? GTotal = 255 : 0;
            temp[i][j].rgbtRed = GTotal;

            GTotal = (GxGreen * GxGreen) + (GyGreen * GyGreen);
            GTotal = sqrt(GTotal);
            GTotal > 255 ? GTotal = 255 : 0;
            temp[i][j].rgbtGreen = GTotal;
            
            GTotal = (GxBlue * GxBlue) + (GyBlue * GyBlue);
            GTotal = sqrt(GTotal);
            GTotal > 255 ? GTotal = 255 : 0;
            temp[i][j].rgbtBlue = GTotal;
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
