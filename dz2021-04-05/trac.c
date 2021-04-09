#include <stdio.h>
#include <stdarg.h>

#define log_info(M, ...) printf("[INFO] (%s:%d) " M "\n",\
    __FILE__, __LINE__, ##__VA_ARGS__)

#define NUMARGS(...)  (sizeof((int*){__VA_ARGS__})/sizeof(int))

void trac_blook_stupid(char* updisp, int s, int i, int j) 
{
	printf("%s\n+----------+---+---+\n|s         | i | j |\n+----------+---+---+\n|%d   | %d | %d |\n+----------+---+---+\n",updisp, s, i, j);
}


/**
 * +---+---+---+
 * | s | i | j |
 * +---+---+---+
 * |   |   |   |
 * +---+---+---+
 */


int main() {
	// 1 -> 2
	// 2 -> 5
	// 3 -> 8
	// 4 -> 11
	int s = 1, i;
	//int tracemas[3] = {s, i, j};
	trac_blook_stupid("int s = 1, i;", s, 0, -1);
	for (i = 0; i <= 3; i++) {
	    if (i%2 == 0){
	    	trac_blook_stupid("%2 T", s, i, -1);
	    	trac_blook_stupid(">PRINT", s, i, -1);
	        printf("Ev. i%d\n", i);
	        trac_blook_stupid("<PRINT", s, i, -1);
	    }
	    int j;
	    trac_blook_stupid("int j", s, 0, 0);
	    for (j = i + 1; j >= 1; j--){
	        s += (i + j) * s;
	        trac_blook_stupid("s = s + (i*j)*s", s, i, j);
	    }
	    trac_blook_stupid(">PRINT",s, i, j);
	    printf("%d%d", s, j);
	    trac_blook_stupid("<PRINT",s, i, j);

	}
	return 0;
}