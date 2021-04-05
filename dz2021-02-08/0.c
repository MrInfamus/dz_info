#include <stdio.h>
#define MAX_EL 10
void fill_array_natural (int n, int a[] )
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		printf("%d ",a[i] );
	}
}

int main()
{
	int a[MAX_EL];
	fill_array_natural(MAX_EL, a);
	return 0;
}