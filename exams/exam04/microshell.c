#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	error(char *str, char *err)
{
	while (*str)
		write(2, str++, 1);
	if (err)
		while (*err)
			write(2, err++, 1);
	write(2, "\n", 1);
	return (1);
}

int main(int argc, char **argv, char **env)
{
	//int pid;
	int i;
	
	(void)argc;
	//pid = 0;
	i = 0;
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(argv[0], "cd"))
		{
			if (i != 2)
				error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				error("error: cd: cannot change directory to ", argv[1]);
		}
		else (i != 0 && (argv[i] == NULL || !strcmp(argv[i], ";")))
		{
			
		}
	}
	return 0;
}