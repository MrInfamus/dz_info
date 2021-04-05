#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 10

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

int get_word(FILE* in, char *buf, int length)
{
	int i;
	int sym;
	for(i = 0; ( sym = fgetc(in) )!=' ' && sym!='\n'; i++)
	{
		if(sym==EOF)return EOF;
		if(length-1>i)
			buf[i] = sym;
	}
	buf[i] = '\0';
	return 0;
}

int main()
{
	FILE* in = fopen("test.txt", "r");
	char buf[BUF_SIZE];
	while (get_word(in, buf, BUF_SIZE) != EOF) {
		printf("%s\n", buf);
	}
	return 0;
}