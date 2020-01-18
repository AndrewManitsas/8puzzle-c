#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void randArrayInitialization(int *array)
{
	time_t t;
	int i = 0, r = 0;
	int numbers[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	
	srand((unsigned) time(&t));

	for (i = 0; i < 9; i++)
	{
		r = rand() % 9;

		if (numbers[r] != 99)
		{
			*array = numbers[r];
			*array++;
			numbers[r] = 99;
		}
		else
		{
			do
			{
				r = rand() % 9;
			} while (numbers[r] == 99);
			
			*array = numbers[r];
			*array++;
			numbers[r] = 99;
		}
	}
}