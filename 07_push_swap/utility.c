#include "push_swap.h"

int	ft_count_rows(char *argv[])
{
	int	row;

	row = 0;
	while (argv[row] != NULL)
		row++;
	return (row);
}

int	ft_find_index(int *arr, int size, int i)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (arr[x] == i)
			break ;
		x++;
	}
	return (x);
}

int	*ft_cpyarray(int *arr, int size)
{
	int	i;
	int	*cpy;

	cpy = malloc (sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}

//void	ft_print_array(int *arr, int size)
//{
//	int	i;
//
//	i = 0;
//	while (i < size)
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	printf("\n");
//}

void	ft_free_matrix(void *matrix[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_exit(t_struct *data, int i)
{
	if (data->a != NULL)
		free(data->a);
	if (data->b != NULL)
		free(data->b);
	if (data->lis != NULL)
		free(data->lis);
	exit(i);
}
