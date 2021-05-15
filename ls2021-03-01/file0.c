#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasharr.h"

DECLARE_PACKEGE(char)
DECLARE_PACKEGE(Hasharr_char)

#define MAX(a, b) \
	(a > b ? a : b)

#define ToStr(a) \
	#a

int mypow(int a, int s){
	if(s==0) return 1;
	else return mypow(a, s-1)*a;
}
#define StrToInt(a) \
	for(int i = 0; a[i]!='\0'; i++) 
int main()
{/*
	char *strok = "Hello, world!";
	Hasharr_char ha;
	hashArrInitByArr_char(&ha, strok, 13, 5);
	append_char(&ha, '@');
	print_char(ha);
	printf("%d\n", length_char(ha));*/
	// 1 > 0 ? 0 : 1
	// if(1>0) return 1; else return 0;
	char *s = "1ooo2345";
	int a = 0;
	int t;
	int k = 0;
	int l = strlen(s); 
	for(int i = 0; i < l; i++) {
		switch(s[i]){
			case '0':{a+=                        0; break;}
			case '1':{a+= mypow(10, l - i - 1) * 1; break;}
			case '2':{a+= mypow(10, l - i - 1) * 2; break;}
			case '3':{a+= mypow(10, l - i - 1) * 3; break;}
			case '4':{a+= mypow(10, l - i - 1) * 4; break;}
			case '5':{a+= mypow(10, l - i - 1) * 5; break;}
			case '6':{a+= mypow(10, l - i - 1) * 6; break;}
			case '7':{a+= mypow(10, l - i - 1) * 7; break;}
			case '8':{a+= mypow(10, l - i - 1) * 8; break;}
			case '9':{a+= mypow(10, l - i - 1) * 9; break;}
			default :{l++;k++;}
		}
		
	}
	printf("%d\n", a);
	return 0;
}