#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <mem.h>

int8_t	is_sympols(char ch, char const *symbols)
{
	while (*symbols)
		if (ch == *symbols++)
			return (1);
	return (0);
}

void	character_replacement(char *inputStr, char const *delimiters, char symbol, int32_t num, uint32_t size)
{
	uint32_t i = 0;

	if (size > num)
		inputStr[num - 1] = symbol;
	while (inputStr[i])
	{
		if (is_sympols(inputStr[i], delimiters) && (i + num) < size)
		{
			if (is_sympols(inputStr[i + num], delimiters))
				character_replacement(inputStr + i + num, delimiters, symbol, num, strlen(inputStr + i + num));
			inputStr[i + num] = symbol;
		}
		i++;
	}
}

int		main(void)
{
	printf("Hello, Ingvar!\n");
	time_t start_time = clock();

	char inputStr[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	char *delimiters = {" c"};

	printf("%s\n", inputStr);
	character_replacement(inputStr, delimiters, '%', 2, strlen(inputStr));
	printf("%s\n", inputStr);

	double time = clock() - start_time;
	time /= CLOCKS_PER_SEC;
	printf("Time %f;\n", time);
	return 0;
}
