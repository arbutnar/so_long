#include "push_swap.h"

void	ft_swap(int *a, int *b, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_a(t_struct *data)
{
	ft_swap(&data->a[0], &data->a[1], data->size_a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_struct *data)
{
	ft_swap(&data->b[0], &data->b[1], data->size_b);
	ft_printf("sb\n");
}

void	ft_swap_swap(t_struct *data)
{
	ft_swap(&data->a[0], &data->a[1], data->size_a);
	ft_swap(&data->b[0], &data->b[1], data->size_b);
	ft_printf("ss\n");
}
