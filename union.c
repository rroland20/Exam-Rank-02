#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char buff[255];
	int i;
	int j;

	i = 0;
	j = 0;
	if(argc == 3)
	{
		while (i < 255)
		{
			buff[i] = 0;
			i++;
		}
		i = 1;
		while (argv[i][j])
		{
			if (buff[(int)argv[i][j]] == 0)
				buff[(int)argv[i][j]] = 1;
			if (buff[(int)argv[i][j]] == 1)
			{
				write(1, &argv[i][j], 1);
				buff[(int)argv[i][j]] = 2;
			}
			j++;
		}
		i++;
		j = 0;
		while (argv[i][j])
		{
			if (buff[(int)argv[i][j]] == 0)
				buff[(int)argv[i][j]] = 1;
			if (buff[(int)argv[i][j]] == 1)
			{
				write(1, &argv[i][j], 1);
				buff[(int)argv[i][j]] = 2;
			}
			j++;
		}
	}
	return (write(1, "\n", 1));
}