#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 функционал MAPCAR применяет функциональный аргумент
 последовательно к каждому элементу.
 Результаты этих применений объединяются в список,
 который и возвращает функционал MAPCAR.

 здесь реализована работа MAPCAR с циклом for как в LISP в скобочной записи,
 правда только для списков натуральных чисел.
 для строковых списков реализация была бы аналогична
 */

int square(int a);
int mapcar(char arr[], int func(int));
char nums_in[1000];
char nums_out[1000] = "";
char temp_num[10] = "";
char clean[1] = "";
int temp_number;
int l;

int
main() {
    printf(
        "Введите список целых чисел аналогично используемым в Common Lisp:\n");
    fgets(nums_in, 1000, stdin);
    l = strlen(nums_in);
    mapcar(nums_in, square);
    puts(nums_out);
    return 0;
}

int
square(int a) {
    return a * a;
}

int
mapcar(char arr[], int func(int)) {   // with loop
    for (int i = 0; i < l; i++) {
        if (arr[i] == '(') {
            if (i == 0) {
                strcat(nums_out, "(");
            } else if (isdigit(arr[i - 1])) {
                temp_number = atoi(temp_num);   // преобразует строку в int
                temp_number = func(temp_number);   // вычисляет новое значение
                sprintf(temp_num, "%d", temp_number);   // запись числа в str
                strcat(nums_out, temp_num);   //  запись числа в итоговый str
                strcat(nums_out, "(");   // запись " " в итоговый str
                sprintf(temp_num, "%s", clean);
            } else {
                strcat(nums_out, "(");
            }

        } else if (arr[i] == ')') {
            if (isdigit(arr[i - 1])) {
                temp_number = atoi(temp_num);   // преобразует строку в int
                temp_number = func(temp_number);   // вычисляет новое значение
                sprintf(temp_num, "%d", temp_number);   // запись числа в str
                strcat(nums_out, temp_num);   //  запись числа в итоговый str
                strcat(nums_out, ")");   // запись " " в итоговый str
                sprintf(temp_num, "%s", clean);
            } else {
                strcat(nums_out, ")");
            }

        } else if (arr[i] == '1') {
            strcat(temp_num, "1");
        } else if (arr[i] == '2') {
            strcat(temp_num, "2");
        } else if (arr[i] == '3') {
            strcat(temp_num, "3");
        } else if (arr[i] == '4') {
            strcat(temp_num, "4");
        } else if (arr[i] == '5') {
            strcat(temp_num, "5");
        } else if (arr[i] == '6') {
            strcat(temp_num, "6");
        } else if (arr[i] == '7') {
            strcat(temp_num, "7");
        } else if (arr[i] == '8') {
            strcat(temp_num, "8");
        } else if (arr[i] == '9') {
            strcat(temp_num, "9");
        } else if (arr[i] == '0') {
            strcat(temp_num, "0");
        } else if (arr[i] == ' ') {
            if (isdigit(arr[i - 1])) {
                temp_number = atoi(temp_num);   // преобразует строку в int
                temp_number = func(temp_number);   // вычисляет новое значение
                sprintf(temp_num, "%d", temp_number);   // запись числа в str
                strcat(nums_out, temp_num);   //  запись числа в итоговый str
                strcat(nums_out, " ");   // запись " " в итоговый str
                sprintf(temp_num, "%s", clean);
            } else {
                strcat(nums_out, " ");
            }
        } else if (arr[i] == '.') {
            if (isdigit(arr[i - 1])) {
                temp_number = atoi(temp_num);   // преобразует строку в int

                temp_number = func(temp_number);   // вычисляет новое значение
                sprintf(temp_num, "%d", temp_number);   // запись числа в str
                strcat(nums_out, temp_num);   //  запись числа в итоговый str
                strcat(nums_out, ".");   // запись " " в итоговый str

                sprintf(temp_num, "%s", clean);
            } else {
                strcat(nums_out, ".");
            }
        }
    }
    return 0;
}
