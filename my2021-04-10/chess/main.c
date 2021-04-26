#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define BLACK   "\033[37;40m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"

//WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET

int main(){
	printf("+ -- -- --- -- -- +\n");
	printf("| %s♖%s %s♘%s %s♗%s %s♕%s %s♔%s %s♗%s %s♘%s %s♖%s |\n", WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET);
	printf("| %s♙%s %s♙%s %s♙%s %s♙%s %s♙%s %s♙%s %s♙%s %s♙%s |\n", BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET);
	printf("| %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s |\n", WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET);
	printf("| %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s |\n", BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET);
	printf("| %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s |\n", WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET);
	printf("| %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s %s▫%s %s▪%s |\n", BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET);
	printf("| %s♟%s %s♟%s %s♟%s %s♟%s %s♟%s %s♟%s %s♟%s %s♟%s |\n", WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET);
	printf("| %s♜%s %s♞%s %s♝%s %s♛%s %s♚%s %s♝%s %s♞%s %s♜%s |\n", BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET, BLACK, RESET, WHITE, RESET);
	printf("+ -- -- --- -- -- +\n");


	return 0;
}
