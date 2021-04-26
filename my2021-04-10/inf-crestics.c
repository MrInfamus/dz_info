#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma once
//----------------------------------------------------------------------------
// IntCanvas

typedef struct IntCanvas {
    int **data;
    int width;
    int height;
} IntCanvas;

void finalizeIntCanvas(IntCanvas *canvas)
{
    for(int i = 0; i < canvas->height; i++){free(canvas->data[i]);};
    free(canvas->data);
}

void fillIntCanvas(IntCanvas *canvas, char symbol) {
    int i;
    for (i = 0; i < canvas->height; i++) {
        int j;
        for (j = 0; j < canvas->width; j++) {
            canvas->data[i][j] = symbol;
        }
    }
}

void initIntCanvas(IntCanvas *canvas, int height, int width) {
    canvas->width = width;
    canvas->height = height;
    canvas->data = (char**)malloc(height * sizeof(char*));
    if(canvas->data == NULL) exit(-1);
    for(int i = 0; i < height; i++){
        canvas->data[i] = (char*)malloc(width * sizeof(char));
        if(canvas->data[i] == NULL) {
            finalizeIntCanvas(canvas);
            exit(-1);
        }
    }
    fillIntCanvas(canvas, ' ');
}

void initIntCanvasWithSymbol(IntCanvas *canvas, int width, int height, char symbol)
{
    canvas->width = width;
    canvas->height = height;
    canvas->data = (char**)malloc(height * sizeof(char*));
    if(canvas->data == NULL) exit(-1);
    for(int i = 0; i < height; i++){
        canvas->data[i] = (char*)malloc(width * sizeof(char));
        if(canvas->data[i] == NULL) {
            finalizeIntCanvas(canvas);
            exit(-1);
        }
    }
    fillIntCanvas(canvas, symbol); 
}

/**
 * This function is designed to reinitialize the array without losing data in it.
 * @param canvas IntCanvas*
 * @param height new height
 * @param width  new width
 * @param sim    the symbol for filling new sells in the canvas
 */
void ReInitIntCanvasWithSymbol(IntCanvas *canvas, int height, int width, int sim)
{
    if(canvas->height > height || canvas->width > width) exit(-1);
    canvas->data = (char**)realloc(canvas->data, height * sizeof(char*));
    if(canvas->data == NULL) {finalizeIntCanvas(canvas); exit(-1);}
    for(int i = 0; i < height; i++)
    {
        canvas->data[i] = (char*)realloc(canvas->data[i], width * sizeof(char*));
        if(canvas->data[i] == NULL) {finalizeIntCanvas(canvas); exit(-1);}
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


void ReInitIntCanvas(IntCanvas *canvas, int height, int width)
{
    if(canvas->height > height || canvas->width > width) exit(-1);
    canvas->data = (char**)realloc(canvas->data, height * sizeof(char*));
    if(canvas->data == NULL) {finalizeIntCanvas(canvas); exit(-1);}
    for(int i = 0; i < height; i++)
    {
        canvas->data[i] = (char*)realloc(canvas->data[i], width * sizeof(char*));
        if(canvas->data[i] == NULL) {finalizeIntCanvas(canvas); exit(-1);}
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

void printIntCanvas(const IntCanvas *canvas) {
    int i;
    for (i = 0; i < canvas->height; i++) {
        int j;
        for (j = 0; j < canvas->width; j++) {
            printf("%d ", canvas->data[i][j]);
        }
        putchar('\n');
    }
}

bool checkPositionAtIntCanvas(const IntCanvas *canvas, IntVector2d position) {
    return position.x >= 0 && position.x < canvas->width
           && position.y >= 0 && position.y < canvas->height;
}

void pointAtIntCanvas(IntCanvas *canvas, IntVector2d position, char symbol) {
    if (!checkPositionAtIntCanvas(canvas, position))
        return;

    canvas->data[position.y][position.x] = symbol;
    // it is not a mistake: 'x' corresponds to horizontal coordinate (width)
}

int main()
{
    IntCanvas canvas;
    initIntCanvasWithSymbol(&canvas, 3, 5, '.');
    
}