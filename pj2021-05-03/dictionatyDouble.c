#include <stdio.h>
#include <stdlib.h>


typedef struct IntDictionary
{
	int length;
	int *a;
	int *b;
} IntDictionary;

void initIntDictionary(IntDictionary *d, int length)
{
	d->length = length;
	d->a = (int*)malloc(length * sizeof(int));
	d->b = (int*)malloc(length * sizeof(int));
}

void finalizeIntDictionary(IntDictionary *d)
{
	free(d->a);
	free(d->b);
}

int FindInA(IntDictionary *d, int item)
{
	for(int i = 0; i < d->length; i++) if(d->a[i] == item) return i;
	return -1;
}

int FindInB(IntDictionary *d, int item)
{
	for(int i = 0; i < d->length; i++) if(d->b[i] == item) return i;
	return -1;
}

int Request(IntDictionary *d, int item)
{
	int r0 = FindInA(d, item);
	if(r0 == -1) return -1;
	return d->b[r0];
}

int ReversRequest(IntDictionary *d, int item)
{
	int r0 = FindInB(d, item);
	if(r0 == -1) return -1;
	return d->a[r0];
}

int main()
{
	IntDictionary d;
	initIntDictionary(&d, 3);
	int a[3] = {1,2,3};
	int b[3] = {3,4,5};
	d.a = a;
	d.b = b;
	typeof(d) v;
	initIntDictionary(&v, 3);

	printf("%d\n", Request(&d, 3));
	printf("%d\n", ReversRequest(&d, 4));

	return 0;
}