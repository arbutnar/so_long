#include "push_swap.h"

void	ft_push(int *ar_one, int *ar_two, int *size_one, int *size_two)
{
	int temp;

	if (*size_one < 1)
		return ;
	temp = ar_one[0];
	ft_rotate(ar_one, *size_one);
	*size_one -= 1;
	*size_two += 1;
	ft_rev_rotate(ar_two, *size_two);
	ar_two[0] = temp;
}

void	ft_push_a(t_struct *data)
{
	ft_push(data->b, data->a, &data->size_b, &data->size_a);
	ft_printf("pa\n");
}

void	ft_push_b(t_struct *data)
{
	ft_push(data->a, data->b, &data->size_a, &data->size_b);
	ft_printf("pb\n");
}
