#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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

#define PI 3.14159265

void rayGradCharCanvas(CharCanvas *canvas, IntVector2d position, char symbol, int gradus)
{
    int u;
    if((gradus - 90) > 0){u = -1;gradus -= 180;}else{u = 1;}
    double k = tan(gradus * PI / 180);
    double b = position.y - k * position.x;
    //printf("u: %d gradus: %d k: %f b: %f\n", u, gradus, k, b);
    if(u==-1){
        if(gradus == 90){
            for(int j = 0; j < position.y; j++ )
            {
                pointAtCharCanvas(canvas, makeVector2d(position.x, j), symbol);
            }
            return;
        }
        for(double i = 0; i < position.x; i+=0.01)
        {
            //printf("%d %f\n", (int)i, i*k + b);
            pointAtCharCanvas(canvas, makeVector2d(ceil(i), ceil(i*k + b)), symbol);
        }
    } else {
        if(gradus == 90){
            for(int j = position.y+1; j <= canvas->width; j++ )
            {
                pointAtCharCanvas(canvas, makeVector2d(position.x, j), symbol);
            }
            return;
        }
        for(double i = position.x+1; i <= canvas->height; i+=0.01)
        {
            //printf("%d %f\n", (int)i, i*k + b);
            pointAtCharCanvas(canvas, makeVector2d(floor(i), floor(i*k + b)), symbol);
        }     
    }
}




#define ENDGAME '!'

int main(void) {
    int x, y, h, w; 
    char sim;

    CharCanvas canvas;
    IntVector2d v;

    printf("Enter Canvas's Height[1, %d] and Width[1, %d]:", MAX_HEIGTH, MAX_WIDTH);
    scanf("%d %d", &h, &w);

    if(h==0 || w==0 || h > MAX_HEIGTH || w > MAX_WIDTH) return -1;

    initCharCanvas(&canvas, h, w);

    //printf("Enter Command: 1)! exit\n2)+ point +\n3)X point X\n?: ");

    scanf("%c", &sim); //По другому не работает((((

    
    while(sim != ENDGAME)
    {
        if(sim == '+') {
            printf("Enter (x, y):");
            scanf("%d %d", &x, &y);
            v = makeVector2d(x, y);
            
            rayGradCharCanvas(&canvas, v, '-', 0);
            rayGradCharCanvas(&canvas, v, '-', 180);
            rayGradCharCanvas(&canvas, v, '|', 90);
            rayGradCharCanvas(&canvas, v, '|', 270);
            pointAtCharCanvas(&canvas, v, '+');
            printCharCanvas(&canvas);
        } else if(sim == 'X') {
            printf("Enter (x, y):");
            scanf("%d %d", &x, &y);
            v = makeVector2d(x, y);
            
            rayGradCharCanvas(&canvas, v, '\\', 45);
            rayGradCharCanvas(&canvas, v, '\\', 225);
            
            rayGradCharCanvas(&canvas, v, '/', 135);
            rayGradCharCanvas(&canvas, v, '/', -45);
            
            pointAtCharCanvas(&canvas, v, 'X');
            printCharCanvas(&canvas);
        }

        printf("Enter Command: 1)! exit\n2)+ point +\n3)X point X\n?: ");
        scanf("%c", &sim);
    }

    return 0;
}
