#include "push_swap.h"

void	ft_rev_rotate(int *ar, int size)
{
	int	temp;

	if (size < 2)
		return ;
	size -= 1;
	temp = ar[size];
	while (size > 0)
	{
		ar[size] = ar[size - 1];
		size--;
	}
	ar[size] = temp;
}

void	ft_rev_rotate_a(t_struct *data)
{
	write(1, "rra\n", 4);
	ft_rev_rotate(data->a, data->size_a);
}

void	ft_rev_rotate_b(t_struct *data)
{
	write(1, "rrb\n", 4);
	ft_rev_rotate(data->b, data->size_b);
}

void	ft_rev_rotate_rotate(t_struct *data)
{
	write(1, "rrr\n", 4);
	ft_rev_rotate(data->a, data->size_a);
	ft_rev_rotate(data->b, data->size_b);
}
