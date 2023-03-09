#include "push_swap.h"

void	ft_validity(char *str, t_struct *data)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return ;
	if (ft_strncmp(str, "sa\n", 3) == 0 || ft_strncmp(str, "ss\n", 3) == 0)
		return ;
	if (ft_strncmp(str, "ra\n", 3) == 0 || ft_strncmp(str, "rr\n", 3) == 0)
		return ;
	if (ft_strncmp(str, "rra\n", 4) == 0 || ft_strncmp(str, "rrr\n", 4) == 0)
		return ;
	if (ft_strncmp(str, "pb\n", 3) == 0)
		return ;
	if (ft_strncmp(str, "sb\n", 3) == 0 || ft_strncmp(str, "ss\n", 3) == 0)
		return ;
	if (ft_strncmp(str, "rb\n", 3) == 0 || ft_strncmp(str, "rr\n", 3) == 0)
		return ;
	if (ft_strncmp(str, "rrb\n", 4) == 0 || ft_strncmp(str, "rrr\n", 4) == 0)
		return ;
	write (1, "Error\n", 6);
	ft_exit(data, 1);
}

void	ft_compare(char *str, t_struct *data)
{
	ft_validity(str, data);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_push(data->b, data->a, &data->size_b, &data->size_a);
	if (ft_strncmp(str, "sa\n", 3) == 0 || ft_strncmp(str, "ss\n", 3) == 0)
		ft_swap(&data->a[0], &data->a[1], data->size_a);
	if (ft_strncmp(str, "ra\n", 3) == 0 || ft_strncmp(str, "rr\n", 3) == 0)
		ft_rotate(data->a, data->size_a);
	if (ft_strncmp(str, "rra\n", 4) == 0 || ft_strncmp(str, "rrr\n", 4) == 0)
		ft_rev_rotate(data->a, data->size_a);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_push(data->a, data->b, &data->size_a, &data->size_b);
	if (ft_strncmp(str, "sb\n", 3) == 0 || ft_strncmp(str, "ss\n", 3) == 0)
		ft_swap(&data->b[0], &data->b[1], data->size_b);
	if (ft_strncmp(str, "rb\n", 3) == 0 || ft_strncmp(str, "rr\n", 3) == 0)
		ft_rotate(data->b, data->size_b);
	if (ft_strncmp(str, "rrb\n", 4) == 0 || ft_strncmp(str, "rrr\n", 4) == 0)
		ft_rotate(data->b, data->size_b);
}

void	ft_read_instruction(t_struct *data)
{
	char *str;

	str = get_next_line(0);
	while (str != NULL)
	{
		ft_compare(str, data);
		free(str);
		str = get_next_line(0);
	}
	if (ft_checkorder(data->a, data->size_a) == 1 && data->size_b < 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int		main(int argc, char *argv[])
{
	t_struct	data;

	if (argc == 1)
		return (0);
	ft_initialize(&data, argc, argv);
	if (ft_checkorder(data.a, data.size_a) == 1)
		ft_exit(&data, 0);
	ft_semplifier(data.a, data.size_a);
	data.b = malloc (sizeof(int) * data.size_a);
	ft_read_instruction(&data);
	ft_exit(&data, 0);
}