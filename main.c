#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"

static int check_operator(char* s){ //Проверка оператора
	if (s == NULL || s[0] == '\0' || s[1] != '\0'){
		return 0;
	}
	char op = s[0];
	return (op == '+' || op == '-' || op == '*' || op == '%');
}

static void err(char* massage){ //Вывод ошибки
	fprintf(stderr, "Ошибка: %s\n", massage); //Вывод ошибки
	exit(1); //Прерывание программы из-за ошибки
}


int main(int argc, char* argv[]){
	if (argc < 5){ //Проверка количества введенных аргументов
		err("Недостаточно аргументов в коммандной строке");	
	}

	int k_pos=-1; //Поиск позиции флага
	for (int i = 0; i < argc; i++){
		if (strcmp(argv[i], "-k") == 0){
			if (k_pos != -1){ //Проверка на единственность флага
				err("Флаг использован больше 1-го раза");
			}
			k_pos=i;
		}
	}

	if (k_pos == -1){ //Проверка на наличие флага
		err("Флаг не был использован");
	}
	
	if (k_pos + 1 >= argc){ //Проверка на наличие ключа после флага
		err("После флага не был использован ключ");
	}
	if (k_pos + 2 != argc){ //Проверка на единственность ключа после флага
		err("После ключа были введены лишние аргументы");
	}

	int sum_args = k_pos - 1; //Количсетво аргументов перед ключом
	if (sum_args < 3 || sum_args % 3 != 0){ //Проверка на деление на 3, т.к. одно выражение состоит из трёх аргументов
		err("Задано неверное количество аргументов");
	}

	int trio_args = sum_args / 3; //Количество выражений

	for (int i = 0; i < trio_args; i++){
		int pos = i * 3 + 1; //Позиции тройки
		if (!check_operator(argv[pos+1])){ //Проверка на верное введённые операторы
			err("Использованы неизвестные операторы");
		}
	}

	int* results = (int*)malloc(trio_args * sizeof(int)); //Выделение памяти под результаты

	for (int i = 0; i < trio_args; i++){ //Вычисление выражений
		int pos = i * 3 + 1;
		int a = atoi(argv[pos]);
		char op = argv[pos+1][0];
		int b = atoi(argv[pos+2]);

		results[i]=calculate(a, op, b);
	}
	
	print_string(results, trio_args); //Вывод ответов
	
	char *endptr;
	long check_key = strtol(argv[k_pos + 1], &endptr, 10); //Ключ
	
	if (*endptr != '\0' || endptr == argv[k_pos + 1]){ //Проверка на целочисленность ключа
		err("Ключ должен быть целым число");
	}
	int key = (int) check_key; //Значение ключа

	char* result_str = build_answer(results, trio_args, key); //Результирующая строка
	
	printf("Результирующая строка: %s\n", result_str); //вывод результирующей строки
	
	//Освобождение выделенной динамической памяти
	free(result_str);
	result_str = NULL;
	
	free(results);
	results = NULL;	
}
