#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "IntVector2d.h"

#pragma once
//----------------------------------------------------------------------------
// CharCanvas

typedef struct CharCanvas {
    char **data;
    int width;
    int height;
} CharCanvas;

void finalizeCharCanvas(CharCanvas *canvas)
{
    for(int i = 0; i < canvas->height; i++){free(canvas->data[i]);};
    free(canvas->data);
}

void fillCharCanvas(CharCanvas *canvas, char symbol) {
    int i;
    for (i = 0; i < canvas->height; i++) {
        int j;
        for (j = 0; j < canvas->width; j++) {
            canvas->data[i][j] = symbol;
        }
    }
}

void initCharCanvas(CharCanvas *canvas, int height, int width) {
    canvas->width = width;
    canvas->height = height;
    canvas->data = (char**)malloc(height * sizeof(char*));
    if(canvas->data == NULL) exit(-1);
    for(int i = 0; i < height; i++){
        canvas->data[i] = (char*)malloc(width * sizeof(char));
        if(canvas->data[i] == NULL) {
            finalizeCharCanvas(canvas);
            exit(-1);
        }
    }
    fillCharCanvas(canvas, ' ');
}

void initCharCanvasWithSymbol(CharCanvas *canvas, int width, int height, char symbol)
{
    canvas->width = width;
    canvas->height = height;
    canvas->data = (char**)malloc(height * sizeof(char*));
    if(canvas->data == NULL) exit(-1);
    for(int i = 0; i < height; i++){
        canvas->data[i] = (char*)malloc(width * sizeof(char));
        if(canvas->data[i] == NULL) {
            finalizeCharCanvas(canvas);
            exit(-1);
        }
    }
    fillCharCanvas(canvas, symbol); 
}

/**
 * This function is designed to reinitialize the array without losing data in it.
 * @param canvas CharCanvas*
 * @param height new height
 * @param width  new width
 * @param sim    the symbol for filling new sells in the canvas
 */
void ReSizeCharCanvasWithSymbol(CharCanvas *canvas, int height, int width, char sim)
{
    //if(canvas->height > height || canvas->width > width) exit(-1);
    canvas->data = (char**)realloc(canvas->data, height * sizeof(char*));
    //if(canvas->data == NULL) {finalizeCharCanvas(canvas); exit(-1);}
    for(int i = 0; i < height; i++)
    {
        canvas->data[i] = (char*)realloc(canvas->data[i], width * sizeof(char*));
        if(canvas->data[i] == NULL) {finalizeCharCanvas(canvas); exit(-1);}
    }
    for(int i = 0; i < canvas->height; i++)
    {
        for(int j = canvas->width; j < width; j++)
        {
            canvas->data[i][j] = sim;
        }
    }
    for(int i = canvas->height; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            canvas->data[i][j] = sim;
        }
    }

    canvas->height = height;
    canvas->width = width;
}


void ReSizeCharCanvas(CharCanvas *canvas, int height, int width)
{
    //if(canvas->height > height || canvas->width > width) exit(-1);
    canvas->data = (char**)realloc(canvas->data, height * sizeof(char*));
    //if(canvas->data == NULL) {finalizeCharCanvas(canvas); exit(-1);}
    for(int i = 0; i < height; i++)
    {
        canvas->data[i] = (char*)realloc(canvas->data[i], width * sizeof(char*));
        if(canvas->data[i] == NULL) {finalizeCharCanvas(canvas); exit(-1);}
    }
    for(int i = 0; i < canvas->height; i++)
    {
        for(int j = canvas->width; j < width; j++)
        {
            canvas->data[i][j] = ' ';
        }
    }
    for(int i = canvas->height; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            canvas->data[i][j] = ' ';
        }
    }

    canvas->height = height;
    canvas->width = width;
}

void printCharCanvas(const CharCanvas *canvas) {
    int i;
    for (i = 0; i < canvas->height; i++) {
        int j;
        for (j = 0; j < canvas->width; j++) {
            putchar(canvas->data[i][j]);
        }
        putchar('\n');
    }
}

bool checkPositionAtCharCanvas(const CharCanvas *canvas, IntVector2d position) {
    return position.x >= 0 && position.x < canvas->width
           && position.y >= 0 && position.y < canvas->height;
}

void pointAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    if (!checkPositionAtCharCanvas(canvas, position))
        return;

    canvas->data[position.y][position.x] = symbol;
    // it is not a mistake: 'x' corresponds to horizontal coordinate (width)
}

void printErrorForCharCanvas(int code)
{
    switch(code)
    {
        case(0): printf("No Error!\n");
        case(1): printf("Error! File cannot be opened.\n");
        default: printf("Undefined Erorr\n");
    }
}
