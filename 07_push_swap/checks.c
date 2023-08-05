#include "push_swap.h"

int	ft_checkorder(int *a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] < a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_check_for_numbs(int argc, char *argv[])
{
	int row;
	int col;

	row = 1;
	while(row < argc)
	{
		col = 0;
		if (argv[row][col] == '-' || argv[row][col] == '+')
			col += 1;
		if (argv[row][col] == '\0')
			ft_error();
		while (argv[row][col] != '\0')
		{
			if (argv[row][col] < '0' || argv[row][col] > '9')
				ft_error();
			col++;
		}
		row++;
	}
}

void	ft_check_for_doubles(int argc, int *arr)
{
	int i;
	int j;
	
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arr[i] == arr[j])
				ft_error();
			j++;
		}
		i++;
	}
}
