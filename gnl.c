#include "gnl.h"

int get_next_line(char **line)
{
	char *buf;
	int read_in;
	int i;

	i = 0;
	if(!(buf = (char *)malloc(100000)) || !(line))
		return (-1);
	while ((read_in = read(0, &buf[i], 1) == 1) && buf[i] != '\n')
		i++;
	buf[i] = 0;
	if (read_in != -1)
		*line = buf;
	if (read_in > 0)
		return (1);
	if (read_in == 0)
		return (0);
	return (-1);
}

int main()
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
}