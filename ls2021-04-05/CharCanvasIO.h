#include "CharCanvas.h"
#include <stdio.h>
#include <stdlib.h>

int readCharCanvasFromFile(CharCanvas *canvas, const char filepath[])
{
    FILE *fp;

    if ((fp = fopen(filepath, "r")) == NULL) {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

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
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

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