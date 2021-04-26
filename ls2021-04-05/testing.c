#include "CharCanvas.h"
#include "IntVector2d.h"
#include "CharCanvasIO.h"
#include <stdio.h>

int main()
{
	IntVector2d v = makeVector2d(0, 1);
	printIntVector2d(v);

	CharCanvas canvas, canvas0;

	initCharCanvasWithSymbol(&canvas, 10, 10, '!');

	initCharCanvas(&canvas0, 11, 10);
	pointAtCharCanvas(&canvas, v, '#');

	//writeCharCanvasToFile(&canvas, "test.txt");

	printCharCanvas(&canvas);
	printf("-----------------\n");
	readCharCanvasFromFile(&canvas0, "test.txt");
	
	printCharCanvas(&canvas0);

	return 0;
}