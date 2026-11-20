#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

long long calculate(long long left_argument, char operator, long long right_argument){ //Калькулятор
	switch(operator){
		case '+':
			return left_argument + right_argument;
		case '-':
			return left_argument - right_argument;
		case '*':
			return left_argument * right_argument;
		case '%':
			if (right_argument == 0){ //Проверка остатка от 0
				return 0;
			}
			return left_argument % right_argument;
		default:
			return 0;
	}
}

char* build_answer(long long* results, int count, int key){ //Формирование ответа
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

void print_string(long long* results, int count){ //Вывод
	for (int i=0; i<count; i++){
		printf("Ответ №%d: %lld\n", i+1, results[i]);
	}
}
