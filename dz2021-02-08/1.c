#include <stdio.h>
#define MAX_COUNT 20
void fill_array_natural (int n, int a[] )
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
}
void change_array(int mas[], int i0, int i1)
{
	int temp = mas[i0];
	mas[i0] = mas[i1];
	mas[i1] = temp;
}
void print_array(int mas[], int length)
{
	int i;

	printf("[");
	for(i = 0; i < length-1; i++)
	{
		printf("%d, ", mas[i]);
	}
	printf("%d]\n", mas[i]);
}
int main()
{
	int n;
	int a[MAX_COUNT];
	printf("Введите длину последовательности: ");
	scanf("%d", &n);

	if(n > MAX_COUNT)
	{
		printf("Превышено допустимое значение.\n");
		return -1;
	} else if(n <= 0) {
		printf("Бессмысленное действие или невыполнимое.\n");
		return -2;
	}


	fill_array_natural(n, a);
	printf("Формат ввода: \"%%d %%d\", где d = [0, ..., %d].\n", n-1);
	int x, y;
	while(1)
	{
		print_array(a, n);
		scanf("%d %d", &x, &y);
		if(x > n-1 || x < 0 || y > n-1 || y < 0){printf("Вы вышли из разрешоннного диапазона.\n");continue;}
		change_array(a, x, y);
		printf("\n");
	}
	return 0;
}