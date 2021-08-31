#include <unistd.h>

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
		i = 0;
		while (argv[2][i])
		{
			buff[(int)argv[2][i]] = 1;
			i++;
		}
		while (argv[1][j])
		{
			if (buff[(int)argv[1][j]] == 1)
			{
				write(1, &argv[1][j], 1);
				buff[(int)argv[1][j]] = 0;
			}
			j++;
		}
	}
	return (write(1, "\n", 1));
}