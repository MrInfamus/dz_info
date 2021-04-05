#include <stdio.h>
#define MAX_COUNT 20
void fill_array_natural (int a[], int n )
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
void scan_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d. Enter a value: ", i+1); // 'i+1' - because for humans it is more natural to start with 1 :)
        scanf("%d", &a[i]);
    }
}

int dontfindname(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
		if(a[i]!=b[i])return 0;
	return 1;
}

int main()
{
	int n;
	printf("Введите длину массивов: ");
	scanf("%d", &n);

	if(n > MAX_COUNT)
	{
		printf("Превышено допустимое значение.\n");
		return -1;
	} else if(n <= 0) {
		printf("Бессмысленное действие или невыполнимое.\n");
		return -2;
	}

	int a[MAX_COUNT], b[MAX_COUNT];
	printf("Введите массив 1:\n");
	scan_array(a, n);
	printf("Введите массив 2:\n");
	scan_array(b, n);
	//Знаю что есть более продуктивная реализация, но с помощью универсальных функций не получится выполнить
	if(dontfindname(a,b,n)) printf("Они одинаковы.\n");
	else printf(";( Они разные.\n");
	return 0;
}
