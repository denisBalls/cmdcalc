#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

int calculate(int a, char operation, int b){ //Калькулятор
	switch(operation){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '%':
			if (b==0){ //Проверка остатка от 0
				return 0;
			}
			return a%b;
		default:
			return 0;
	}
}

char* build_answer(int* results, int count, int key){ //Формирование ответа
	if (results == NULL || count <=0){
		return NULL;
	}
	char* str = (char*)malloc((size_t)(count+1));
	
	for (int i=0; i<count; i++){
		str[i]=(char)(results[i]-key);
	}
	str[count]='\0';
	return str;
}

void print_string(int* results, int count){ //Вывод
	for (int i=0; i<count; i++){
		printf("Ответ №%d: %d\n", i+1, results[i]);
	}
}
