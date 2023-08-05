#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_struct	data;

	if (argc == 1)
		return (0);
	ft_initialize(&data, argc, argv);
	if (ft_checkorder(data.a, data.size_a) == 1)
		ft_exit(&data, 0);
	ft_semplifier(data.a, data.size_a);
	data.b = malloc (sizeof(int) * data.size_a);
	if (data.a[0] == 1 || data.a[1] == 2 || data.a[2] == 3)
			if (data.a[2] != 5 && data.a[0] != 4)
				ft_swap_a(&data);
	ft_lis(&data);
	ft_go_away(&data);
	ft_algorithm(&data);
	ft_exit(&data, 0);
	//ft_print_array(data.a, data.size_a);
}