#include "lr.h"
#include "stdio.h"
#define N 10
#define SIZE 100

//#include "lr.c"
double P(int A, int C, float B) {
	return (A + (B * B)) / (C - A);
}

int labl1() {
	float P, A, B, C; //переменные A, B,C, P
	printf("A=");
	scanf_s("%f", &A);
	printf("B=");
	scanf_s("%f", &B);
	printf_s("C=");
	scanf_s("%f", &C);
	P = (A + (B * B)) / (C - A);
	printf_s("%f", P);
	return 0;
}
int labl1dop() {
	float B = 50; //переменная B
	int A = 10;
	int C = 30;
	printf_s("%f", P(A, C, B));
	return 0;
}
int labl2() {
	float a; //числитель
	float b; //знаменатель
	float c; //элемент ряда
	float s; //сумма ряда
	float n; //номер текущего элемента ряда.
	float i;
	int sign; //знак элемента ряда
	a = 3;
	b = 1;
	s = 0;
	i = 0;
	sign = 1;
	printf("n=");
	scanf_s("%f", &n);
	for (i; i < n;) {
		c = a / b;
		s = s + c * sign;
		sign = -sign;
		a = a + 1;
		b = b + 3;
		i = i + 1;
	}
	printf("s = %f", s);
	return 0;
}
int labl2dop() {
	float a, b, c, s, n, i; //числитель, знаменатель, элемент ряда, сумма ряда,номер текущего элемента ряда.
	int sign; //знак элемента ряда
	a = 3;
	b = 1;
	s = 0;
	i = 0;
	sign = 1;
	printf("n=");
	scanf_s("%f", &n);
	for (i; i < n; i++) {
		c = a / b;
		s = s + c * sign;
		sign = -sign;
		a++;
		b = b + 3;
	}
	printf("s = % f", s);
	return 0;
}
int labl3() {
#define IN 1 // внутри слова
#define OUT 0 // вне слова
#define CNTRLZ 26 
	int c, nw, state;
	int first_c = EOF, prev = ' ';
	state = OUT;
	nw = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == ',' || c == '\n' || c == CNTRLZ) {
			state = OUT;
			if (prev == first_c)++nw;
		}
		else if (state == OUT) {
			state = IN;
			first_c = c;
		}
		prev = c;
	}
	printf("\n result: %d\n", nw);
	return 0;
}
int labl3dop() {
#define IN 1 //внутри слова
#define OUT 0 //вне слова
#define CNTRLZ 26 
	int c, nw, state;
	int first_c = EOF, prev = ' ';
	state = OUT;
	nw = 0;
	char glassn[] = { 'q', 'e', 'y', 'u', 'i', 'o', 'a' };
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == ',' || c == '\n' || c == CNTRLZ) {
			state = OUT;
			if ((prev == first_c)) {
				for (int i = 0; i < sizeof(glassn); i++) {
					if (glassn[i] == prev) { // Если нашли искомый символ в массиве glassn
						nw++;
					}
				}
			}
		}
		else if (state == OUT) {
			state = IN;
			first_c = c;
		}
		prev = c;

	}
	printf("\n result: %d\n", nw);
	return 0;
}
int labl4() {
	char arr[] = "ab,dfd,df qwerty";
	int size = sizeof(arr) / sizeof(char);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == ',')
		{
			for (int j = i + 1; j < size - 1; j++)
			{
				if (arr[j] == ' ' || arr[j] == ',')
				{
					break;
				}
				else
				{
					arr[j] = '\0';
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%c", arr[i]);
	}

	return 0;

}
int labl4dop() {
	char arr[] = "ab,dfd,df, qwerty";
	int size = sizeof(arr) / sizeof(char);
	for (int i = 0; i < size; i++) {
		if (arr[i] == ',') {
			for (int j = i + 1; j < size - 1; j++) {
				if (arr[j] == ' ' || arr[j] == ',') {
					break;
				}
				else {
					arr[j] = '\0';
					arr[j] = ' ';
				}
			}
			// удаляем пробел после слова
			if (arr[i + 1] == ' ') {
				for (int k = i + 1; k < size - 1; k++) {
					arr[k] = arr[k + 1];
				}
				size--; // уменьшаем размер строки
			}
			// удаляем запятую после слова
			for (int k = i; k < size - 1; k++) {
				arr[k] = arr[k + 1];
			}
			size--; // уменьшаем размер строки
		}
	}
	for (int i = 0; i < size; i++) {
		printf("%c", arr[i]);
	}
	return 0;
}
int labl5() {
	int x[N];
	int d;
	int i;
	for (i = 0; i < N; i++)
		scanf_s("%d", &x[i]);
	d = x[1] - x[0];
	for (i = 1; i < N; i++)
		if ((x[i] - x[i - 1]) != d) {
			printf("this is not an arithmetic progression\n");
			return 0;
		}
	/*!
	 * check whether the sequence
	 * changes equally or not?
	*/
	printf("this is an arithmetic progression\n");
	return 0;
}
int labl5dop() {
#include <stdio.h>
#define V 20
	int x[V];
	int d;
	int i;
	// Считывание значений в массив
	for (i = 0; i < V; i++) {
		scanf_s("%d", &x[i]);
	}

	// Проверка на арифметическую прогрессию
	d = x[1] - x[0];
	for (i = 1; i < V; i++) {
		if ((x[i] - x[i - 1]) != d) {
			printf("this is not an arithmetic progression\n");
			return 0;
		}
	}
	printf("this is an arithmetic progression\n");

	// Проверка на "агрехи" в прогрессии
	for (i = 1; i < V - 2; i++) {
		if (x[i] < x[i - 1] && x[i + 1] > x[i] && x[i + 2] > x[i]) {
			printf("В прогрессии есть агрехи: %d на позиции %d\n", x[i], i);
		}
	}

	return 0;
}
int labl6() {
	int n, k;
	printf_s("Enter Number of Rows and Columns\n");
	scanf_s("%d %d", &n, &k);
	printf_s("Enter Array\n");
	int x[SIZE][SIZE];
	int min_s, min_el = 2147483647, max_s, max_el = -2147483647;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			scanf_s("%d", &x[i][j]);
			if (min_el >= x[i][j]) {
				min_el = x[i][j];
				min_s = i;
			}
			if (max_el <= x[i][j]) {
				max_el = x[i][j];
				max_s = i;
			}
		}
	}
	printf_s("\n");
	int res[SIZE][SIZE];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (i == min_s) {
				printf_s("%d ", x[max_s][j]);
				res[i][j] = x[max_s][j];
			}
			else if (i == max_s) {
				printf_s("%d ", x[min_s][j]);
				res[i][j] = x[min_s][j];
			}
			else {
				printf_s("%d ", x[i][j]);
				res[i][j] = x[i][j];
			}
		}
		printf_s("\n");
	}
	return 0;
}
int labl7() {
	unsigned long M;
	printf("Enter a long integer N: ");
	scanf_s("%lu", &M);

	int left_ones = 0, right_ones = 0;
	unsigned long temp = M;

	// Считаем количество единичных битов справа
	while (temp) {
		right_ones += temp & 1;
		temp >>= 1;
	}

	temp = M;
	int bit_position = 0;
	int found = 0;

	// Ищем разряд, для которого выполняется условие
	while (temp) {
		if (temp & 1) {
			right_ones--;
		}
		if (left_ones == right_ones) {
			found = 1;
			break;
		}
		left_ones += temp & 1;
		temp >>= 1;
		bit_position++;
	}

	if (found) {
		printf("Binary digit number: %d\n", bit_position);
	}
	else {
		printf("There is no such category.\n");
	}
	return 0;
}