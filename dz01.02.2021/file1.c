#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSYMBOL 20

int is_pallendrome(const char str[])
{
	int l = strlen(str);
	for(int i = 0; str[i] !='\0'; i++)
	{
		if(str[i] != str[l-i-1])
		{
			return 0;
		}
	}
	return 1;
}
void gen_mode_test(FILE* in)
{
	char fraz[MAXSYMBOL];
	while((fscanf(in, "%s", fraz))!=EOF)
	{
		if(is_pallendrome(fraz))
		{
			printf("%s 1\n", fraz);
		}/* else {
			printf("%s 0\n", fraz);
		}*/
	}
}

void test1()
{
	printf("komok %d\n", is_pallendrome("komok"));
	printf("radar %d\n", is_pallendrome("radar"));
	printf("ovalnii %d\n", is_pallendrome("ovalnii"));
	printf("Unity %d\n", is_pallendrome("Unity"));
	printf("ono %d\n", is_pallendrome("ono"));
}

int main()
{
	FILE* in = fopen("modtest.txt", "r");
	gen_mode_test(in);
	char a[5] = "komok";
	char b[] = "etst";
	printf("%d %d\n", is_pallendrome(a), is_pallendrome(b));
	return 0;
}