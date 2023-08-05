#include "push_swap.h"

void	ft_cpyrow(int *arr, int *cpy, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
}

void	ft_overload(int **matrix, int i, int row)
{
	int heads_index;

	heads_index = 0;
	while (heads_index <= row)
	{
		if (matrix[heads_index][heads_index] > i)   
			break;
		heads_index++;
	}
	ft_cpyrow(matrix[heads_index - 1], matrix[heads_index], heads_index);
	matrix[heads_index][heads_index] = i;
}

void	ft_lis(t_struct *data)
{
	int **matrix;
	int i;
	int row;
	int max;

	matrix = malloc (sizeof(int *) * data->size_a);
	matrix[0] = malloc (sizeof(int));
	matrix[0][0] = 1;
	row = 0;
	i = ft_find_index(data->a, data->size_a, 1) + 1;
	if (i == data->size_a)
		i = 0;
	max = 0;
	while (data->a[i] != 1)
	{
		if (data->a[i] > matrix[max][max])
		{
			row += 1;
			matrix[row] = malloc (sizeof(int) * (row + 1));
			ft_cpyrow(matrix[row - 1], matrix[row], row);
			matrix[row][row] = data->a[i];
			max++;
		}
		else if (data->a[i] < matrix[max][max])
		{
			ft_overload(matrix, data->a[i], row);
		}
		i++;
		if (i == data->size_a)
			i = 0;		
	}
	data->lis = ft_cpyarray(matrix[row], row + 1);
	data->size_lis = row + 1;
	ft_free_matrix((void **)matrix, row + 1);
}
