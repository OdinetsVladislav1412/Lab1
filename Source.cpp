#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


int main()
{
	double max, min, summa = 0;
	int N, i, j, dr, prov;
	double* mas1;
	int* mas2;

	setlocale(LC_ALL, "rus");

	printf("Введите количество случайных чисел: ");
	scanf_s("%d", &N);
	printf("Минимальное значение: ");
	scanf_s("%lf", &min);
	printf("Максимальное значение: ");
	scanf_s("%lf", &max);

	if ((N <= 0) || (min >= max))
	{
		printf("Ошибка. Введены некорректные значения.");
		return 0;
	}

	mas1 = (double*)malloc(N * sizeof(double));
	mas2 = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
	{
		mas1[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;
		dr = ((int)((mas1[i]-(int)mas1[i]) * 1000000));
		mas2[i] = dr;
		summa += mas1[i];
	}


	for (i = 0; i < N; i++)
	{
		prov = 0;
		for (j = 0; j < N; j++)
		{
			if (i == mas2[j])
			{
				if (prov == 0)  
				{
					summa = summa - 2 * mas1[i]; 
					prov = 1;
				}
			}
		}
	}

	printf("Итоговое значение равно: %lf\n", summa);

	free(mas1);
	free(mas2);
	return 0;
}