#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = argc - 1;
	int j = 0;
	while (argv[i][j])
	{
		write(1, &argv[i][j],1);
		j++;
	}
	write(1, "\n",1);
	return (0);
}
