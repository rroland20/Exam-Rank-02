#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	char buff[255];

	i = 0;
	j = 0;
	if (argc != 3)
		return (write(1, "\n", 1));
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
	return (0);
}
