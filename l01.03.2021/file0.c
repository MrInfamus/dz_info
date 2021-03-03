#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasharr.h"

DECLARE_PACKEGE(char)

int main()
{
	char *strok = "Hello, world!";
	Hasharr_char ha;
	hashArrInitByArr_char(&ha, strok, 13, 5);
	print_char(ha);
	printf("%d\n", length_char(ha));



	return 0;
}