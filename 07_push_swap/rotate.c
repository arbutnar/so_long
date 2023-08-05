#include "push_swap.h"

void	ft_rotate(int *arr, int size)
{
	int	i;
	int	temp;

	if (size < 2)
		return ;
	temp = arr[0];
	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = temp;
}

void	ft_rotate_a(t_struct *data)
{
	ft_rotate(data->a, data->size_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_struct *data)
{
	ft_rotate(data->b, data->size_b);
	ft_printf("rb\n");
}

void	ft_rotate_rotate(t_struct *data)
{
	ft_rotate(data->a, data->size_a);
	ft_rotate(data->b, data->size_b);
	ft_printf("rr\n");
}
