#include <stdio.h>

int strequal(const char str1[],const char str2[])
{
	for(int i = 0; str1[i] != '\0' ; i++)
	{
		if(str1[i] - str2[i]){
			return 0;
		}
	}
	return 1;
}

int mystrcmp(const char str1[],const char str2[])
{
	for(int i = 0; ; i++)
	{
		if(str1[i] == '\0' && str2[i] != '\0')
			return -1;
		else if(str2[i] == '\0' && str1[i] != '\0')
			return 1;

		if(str1[i] == str2[i] && str1[i] != '\0');
		else return (int)(str1[i] - str2[i]);
	}

}

int main()
{
	printf("result: %d\n",mystrcmp("Helllo", "Hello"));
	printf("result: %d\n",strequal("Helo", "Helo"));
	return 0;
}