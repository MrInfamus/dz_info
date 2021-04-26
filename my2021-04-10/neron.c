#include <stdlib.h>
#include <stdio.h>

#define PIECE_TO_WIN 5
#define KREST 'X'
#define NOLE 'O'
#define VOIDE 0

#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x > y) ? y : x)
#define ABS(x) ((x < 0) ? -x : x)

typedef struct kresField
{
	int **cells;
	int n;
	int m;
} kresField;

void initkresField(kresField* field, int n, int m)
{
	field->n = n;
	field->m = m;
	field->cells = (int**)malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++)
	{
		field->cells[i] = (int*)malloc(m*sizeof(int));
	}
}

int checklimit(kresField *field, int i, int j)
{
	return i >= 0 && j >= 0 && i < field->m && j < field->n;
}

int getCell(kresField *field, int i, int j)
{
	if(checklimit(field, i, j)) return field->cells[i][j];
	printf("You out out of limit!\n");
	exit(-1);
}

void DoTurn(kresField *field, int i, int j, int item)
{
	if(checklimit(field, i, j)){field->cells[i][j] = item; return;}
	printf("You out out of limit!\n");
	exit(-1);
}

int EndGame(kresField *field, int i, int j)
{
	int id = i - PIECE_TO_WIN, iu = i + PIECE_TO_WIN, jd = j - PIECE_TO_WIN, ju = j + PIECE_TO_WIN;
	/*
	printf("id:%d iu:%d jd:%d ju:%d\n", id, iu, jd, ju);

	if(id < 0) id = 0;
	if(jd < 0) jd = 0;
	if(iu > field->n) iu = field->n;
	if(ju > field->m) ju = field->m;
	*/

	//check diagonales
	int gcounter = 0;
	int lcounter = 0;

	printf("id:%d iu:%d jd:%d ju:%d\n", id, iu, jd, ju);
	
	int down = MAX(id, jd);
	int up = MIN(iu, ju);

	printf("down:%d up:%d\n", down, up);
	
	if(up-down >= PIECE_TO_WIN){
		for(int p = down; p < up; p++)
		{
			int gitem = getCell(field, p, p);
			int litem = getCell(field, field->m - p, p);

			printf("sys1 p:%d gitem: %d litem: %d counter: %d\n", p, gitem, litem, gcounter);

			if(gitem == KREST){if(gcounter < 0) gcounter = 1; else gcounter++;}
			if(gitem == NOLE){if(gcounter > 0) gcounter = -1; else gcounter--;}

			if(gcounter >= PIECE_TO_WIN) return 1;
			if(gcounter <= -PIECE_TO_WIN) return -1;

			if(gitem == VOIDE) gcounter = 0;

			if(litem == KREST){if(lcounter < 0) lcounter = 1; else lcounter++;}
			if(litem == NOLE){if(lcounter > 0) lcounter = -1; else lcounter--;}

			if(lcounter >= PIECE_TO_WIN) return 1;
			if(lcounter <= -PIECE_TO_WIN) return -1;

			if(litem == VOIDE) lcounter = 0;
		}	
	}
	return 0;
	
}

typedef struct Qtable
{
	int n; //count actions 
	int m; //count status

	int **data;
} Qtable;

void initQtable(Qtable *table, int m, int n)
{
	table->m = m;
	table->n = n;
	table->data = (int**)malloc(m*sizeof(int*));
	for(int i = 0; i < m; i++)
	{
		table->data[i] = (int*)malloc(n*sizeof(int));
	}
}

int main()
{
	printf("12--");

	return 0;
}