#include "push_swap.h"

void	ft_push_in_b(t_struct *data, int nb, int i)
{
	while (nb != data->a[0])
	{
		if (i <= data->size_a / 2)
			ft_rotate_a(data);
		else
			ft_rev_rotate_a(data);
	}
	ft_push_b(data);
}

int		ft_find_in_lis(int *arr, int size, int nb)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (arr[x] == nb)
			return (0);
		x++;
	}
	return (1);
}

void	ft_push_in_chunck(t_struct *data, int average)
{
	int	i;

	i = 0;
	while (i < data->size_a)
	{
		if (ft_find_in_lis(data->lis, data->size_lis, data->a[i]))
		{
			if (data->a[i] <= average)
			{
				ft_push_in_b(data, data->a[i], i);
				i = -1;
			}
		}
		i++;
	}
}

void	ft_go_away(t_struct *data)
{
	int	chunk_size;
	int	average;

	chunk_size = data->size_a / 4;
	average = chunk_size;
	while (data->size_a != data->size_lis && average != 0)
	{
		ft_push_in_chunck(data, average);
		average += chunk_size;
	}
}
