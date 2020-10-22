#include <unistd.h>

int 	matching(char *sfo, char *sfc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(sfo[i] != '\0' || sfc[j] != '\0')
	{
		if ((sfc[j] - sfo[i]) <= 2)
			return (1);
		j++;
		i++;
	}
	return (0);
}

int 	brackets(char *av)
{
	char 	sfo[512];
	char 	sfc[512];
	int 	i;
	int 	open;
	int		closed;

	i = 0;
	open = 0;
	closed = 0;
	if (av[i] == 0)
		return (1);
	while (av[i] != '\0')
	{
		if (av[i] == '(' || av[i] == '[' || av[i] == '{')
		{
			sfo[open] = av[i];
			open++;
		}
		if (av[i] == ')' || av[i] == ']' || av[i] == '}')
		{
			sfc[closed] = av[i];
			closed++;
		}
		i++;
	}
	return (matching(sfo, sfc));
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (brackets(av[i]))
				write(1, "OK", 2);
			else
				write(1, "Error", 5);
			i++;
		}
	}
	write(1, '\n', 1);
	return (0);
}