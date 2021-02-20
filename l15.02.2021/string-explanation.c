/*

string - строка - как способ хранения текста
line - строка - строчка - "текст на одной линии"

string: C-style - способ хранения строк:
- array / массив
- тип элементов: char (1 байт)
- последний элемент: '\0'

'\n' и '\0' - разные вещи!!!


"Hi!" <=> { 'H', 'i', '!', '\0' }

{ 'H', '\0', '!', '\0' } <=> "H"

"H" <=> 'H' ???  НЕТ!!!
{ 'H', '\0' }  не то же, что 'H' (код символа H)

Пустая строка:
"" <=>  { '\0' }

Длина строки:
"Hi"
 - длина: 2
 - минимальный размер массива, чтобы хранить: 3


*/
#include <stdio.h>

void my_print_string(const char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        putchar(str[i]); // printf("%c", str[i]);
    }
}


// Аналоги библиотечной 'strlen' ( 'stdlib.h', 'string.h' )
int mystrlen(const char str[]) {
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

int scan_string(char str[], int max_size) {
    int i;
    for(i = 0; i < max_size && (str[i] = getchar())!='\n'; i++);
    if(i >= max_size){str[i-1] = '\0'; return 0;}
    return 1;
}


#define MAX_SIZE 20

int main(void) {

    char str[MAX_SIZE];

    
    if(!scan_string(str, 10)) { printf("Error!!\n"); return -1;}
    else my_print_string(str);

    char str0[MAX_SIZE] = "Hi";
    char str1[MAX_SIZE] = "Hello!!!";

    printf("\n#1: \"%s\" %d\n", str1, mystrlen(str1));
    // . . .

    return 0;

}
