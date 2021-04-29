#include "CharCanvas.h"
#include <stdio.h>
#include <stdlib.h>

int readCharCanvasFromFile(CharCanvas *canvas, const char filepath[])
{
    FILE *fp;
    int h,w;

    if ((fp = fopen(filepath, "r")) == NULL) {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        return -1;
    }

    fscanf(fp, "%d %d\n", &h, &w);
    //printf("%d %D\n", h, w);

    ReSizeCharCanvas(canvas, h, w);

	for(int i = 0; i < canvas->height; i++)
	{
		int sym = '!';
		for(int j = 0; (sym = fgetc(fp)) != '\n'; j++){
			if(sym == EOF){ fclose(fp); return 1; }
			if(j < canvas->width) canvas->data[i][j] = sym;
		}
	}

	fclose(fp);
	return 0;

}

int readCharCanvasFromStream(CharCanvas *canvas, FILE *fp)
{
    int h,w;
    fscanf(fp, "%d %d\n", &h, &w);


    ReSizeCharCanvas(canvas, h, w);

	for(int i = 0; i < canvas->height; i++)
	{
		int sym = '!';
		for(int j = 0; (sym = fgetc(fp)) != '\n'; j++){
			if(sym == EOF){ fclose(fp); return 1; }
			if(j < canvas->width) canvas->data[i][j] = sym;
		}
	}

	fclose(fp);
	return 0;
}

int writeCharCanvasToFile(const CharCanvas *canvas, const char filepath[])
{
    FILE *fp;

    if ((fp = fopen(filepath, "w")) == NULL) {
    	return -1;
    }

    fprintf(fp, "%d %d\n", canvas->height, canvas->width);

	for(int i = 0; i < canvas->height; i++)
	{
		for(int j = 0; j < canvas->width; j++)
		{
			fputc(canvas->data[i][j], fp);
		}
		fputc('\n', fp);
	}
	fclose(fp);
	return 0;
}

int writeCharCanvasToStream(const CharCanvas *canvas, FILE *fp)
{
	fprintf(fp, "%d %d\n", canvas->height, canvas->width);

	for(int i = 0; i < canvas->height; i++)
	{
		for(int j = 0; j < canvas->width; j++)
		{
			fputc(canvas->data[i][j], fp);
		}
		fputc('\n', fp);
	}
	fclose(fp);
	return 0;
}	