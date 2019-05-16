#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <mem.h>

void	character_replacement(char *inputStr, char const *delimiters, char symbol, int32_t num, uint32_t size)
{
	uint32_t i = 0;
	uint32_t j = 0;

	if (size > num)
		inputStr[num - 1] = symbol;
	while (inputStr[i])
	{
		j = 0;
		while (delimiters[j])
		{
			if ((inputStr[i] == delimiters[j]) && (i + num) < size)
			{
				if (inputStr[i + num] == symbol)
					character_replacement(inputStr + i + num, delimiters, symbol, num, strlen(inputStr + i + num));
				inputStr[i + num] = symbol;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
	printf("Hello, Ingvar!\n");
	time_t start_time = clock();

	char inputStr[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	char *delimiters = {" m"};

	printf("%s\n", inputStr);
	character_replacement(inputStr, delimiters, '%', 2, strlen(inputStr));
	printf("%s\n", inputStr);

	double time = clock() - start_time;
	time /= CLOCKS_PER_SEC;
	printf("Time %f;\n", time);
	return 0;
}
