#include "CharCanvas.h"
#include "IntVector2d.h"
#include "CharCanvasIO.h"
#include <stdio.h>

#define PATH "/Users/ivan/Desktop/project/dz_info/pj2021-04-05/"

int main()
{	
	CharCanvas canvas;
	initCharCanvas(&canvas, 0, 0);
	int result = readCharCanvasFromFile(&canvas, PATH"test.txt");
	int h, w;
	char c;
	
	if(result != 0) { 
		printf("Height: ");
		scanf("%d", &h);
		printf("Width: ");
		scanf("%d", &w);

		printf("Symbol for filling canvas: ");
		c = myGetChar();
		
		ReSizeCharCanvasWithSymbol(&canvas, h, w, c);
	}

	IntVector2d v = askAndScanIntVector2d();
	printIntVector2d(v);

	//initCharCanvas(&canvas0, 11, 10);
	pointAtCharCanvas(&canvas, v, '#');
	int codeError = writeCharCanvasToFile(&canvas, PATH"test.txt");
	if(codeError)printErrorForCharCanvas(codeError);

	printCharCanvas(&canvas);
	printf("-----------------\n");
	


	return 0;
}