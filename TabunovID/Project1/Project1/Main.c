// Задача 3. Дана квадратная матрица размера N × N.
// Найти суммы элементов всех ее нечетных столбцов.

#include <stdio.h>

int sum(int *line,int N) {

	int i, j, sum =0;
	for (i = 0; i < N; i++)//строка
	{
		for (j = 0; j < N; j+=2)//Столбец
		{
			printf("%d\n", *line);
			sum += *(line);
			line += 2;
		}
		if (N % 2 == 1) {
			line--;
			//sum+=
			//printf("%d\n", *line);
		}
	}

	return sum;
}

int main() {
	int line[] = { 3,2,6,9,9,7,8,1,5,4,3,1,2,5,2,7 };
	// int line[] = {3,2,6,9,1,9,7,8,1,8,5,4,3,1,1,2,5,2,7,9,1,8,1,9,5};
	int N = 4;
	printf("%d",sum(line, N));

	return 0;
}