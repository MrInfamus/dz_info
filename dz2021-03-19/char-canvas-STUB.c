#include <stdio.h>
#include <stdbool.h>

//----------------------------------------------------------------------------
// IntVector2d

struct IntVector2d {
    int x, y;
};

// typedef int weight_t; // example: it defines type 'weight_t' as a synonym for 'int'

typedef struct IntVector2d IntVector2d; // now we can use 'IntVector2d' instead of 'struct IntVector2d'

IntVector2d makeVector2d(int x, int y) {
    IntVector2d v;
    v.x = x;
    v.y = y;
    return v;
}

void printIntVector2d(IntVector2d v) {
    //TODO: print in the format: (x, y)
}

IntVector2d askAndScanIntVector2d(void) {
    //TODO: ask for and scan each of the coordinates
    return makeVector2d(0, 0); //TODO: remove this stub
}

//----------------------------------------------------------------------------
// CharCanvas

#define MAX_HEIGTH 100
#define MAX_WIDTH  200

typedef struct CharCanvas {
    char data[MAX_HEIGTH][MAX_WIDTH];
    int width;
    int height;
} CharCanvas;


void fillCharCanvas(CharCanvas *canvas, char symbol) {
    int i;
    for (i = 0; i < canvas->height; i++) {
        int j;
        for (j = 0; j < canvas->width; j++) {
            canvas->data[i][j] = symbol;
        }
    }
}

void initCharCanvas(CharCanvas *canvas, int width, int height) {
    canvas->width = width;
    canvas->height = height;
    fillCharCanvas(canvas, ' ');
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
    return    position.x >= 0 && position.x < canvas->width
           && position.y >= 0 && position.y < canvas->height;
}

void pointAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    if (!checkPositionAtCharCanvas(canvas, position))
        return;

    canvas->data[position.y][position.x] = symbol;
    // it is not a mistake: 'x' corresponds to horizontal coordinate (width)
}

void rayLeftAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

void rayRightAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

void rayUpAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

void rayDownAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

void rayLeftUpAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

void rayLeftDownAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

void rayRightUpAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

void rayRightDownAtCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol) {
    //TODO: implement
}

//----------------------------------------------------------------------------
// main

int main(void) {

    CharCanvas canvas;

    initCharCanvas(&canvas, 7, 4);
    printf(" #0:\n");
    printCharCanvas(&canvas);

    fillCharCanvas(&canvas, '.');
    printf(" #1:\n");
    printCharCanvas(&canvas);

    pointAtCharCanvas(&canvas, makeVector2d(2, 3), '@');
    printf(" #2:\n");
    printCharCanvas(&canvas);

    pointAtCharCanvas(&canvas, makeVector2d(4, 1), '%');
    printf(" #3:\n");
    printCharCanvas(&canvas);

    return 0;
}
