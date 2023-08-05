#include "push_swap.h"

t_best	ft_best(t_best *best, t_struct *data)
{
	int		i;
	t_best	temp;

	i = 0;
	temp = best[i];
	while (i < data->size_b)
	{
		if (temp.moves > best[i].moves)
			temp = best[i];
		i++;
	}
	free(best);
	return (temp);
}

void	ft_info(t_struct *data, int i, t_best *cell, char flag)
{
	if (flag == 'a')
	{
		cell->value_a = data->a[i];
		if (i <= data->size_a / 2)
		{
			cell->move_a = i;
			cell->dir_a = 0;
			return ;
		}
		cell->move_a = data->size_a - i;
		cell->dir_a = 1;
	}
	else if (flag == 'b')
	{
		cell->value_b = data->b[i];
		if (i <= data->size_b / 2)
		{
			cell->move_b = i;
			cell->dir_b = 0;
			return ;
		}
		cell->move_b = data->size_b - i;
		cell->dir_b = 1;
	}
}

void	ft_find_value_a(t_struct *data, t_best *cell)
{
	int i;

	i = 0;
	if (data->a[data->size_a - 1] < cell->value_b && data->a[i] > cell->value_b)
	{
		ft_info(data, i, cell, 'a');
		return ;
	}
	i = 1;
	while (i < data->size_a)
	{
		if (data->a[i - 1] < cell->value_b && data->a[i] > cell->value_b)
		{
			ft_info(data, i, cell, 'a');
			return ;
		}
		i++;
	}
	ft_info(data, ft_find_index(data->a, data->size_a, 1), cell, 'a');
}

t_best	ft_fill_struct(t_struct *data)
{
	t_best	*best;
	int 	i;

	best = malloc (sizeof(t_best) * data->size_b);
	i = 0;
	while (i < data->size_b)
	{
		ft_info(data, i, &best[i], 'b');
		ft_find_value_a(data, &best[i]);
		if (best[i].dir_b == best[i].dir_a)
		{
			if (best[i].move_b > best[i].move_a)
				best[i].moves = best[i].move_b;
			else
				best[i].moves = best[i].move_a;
		}
		else
			best[i].moves = best[i].move_b + best[i].move_a;
		i++;
	}
	return (ft_best(best, data));
}

void	ft_algorithm(t_struct *data)
{
	t_best temp;

	while (data->size_b != 0)
	{
		temp = ft_fill_struct(data);
		while ((temp.value_a != data->a[0] && temp.value_b != data->b[0]) && temp.dir_a == temp.dir_b)
		{
			if (temp.dir_a == 0)
				ft_rotate_rotate(data);
			else
				ft_rev_rotate_rotate(data);
		}
		while (temp.value_a != data->a[0])
		{
			if (temp.dir_a == 0)
				ft_rotate_a(data);
			else
				ft_rev_rotate_a(data);
		}
		while (temp.value_b != data->b[0])
		{
			if (temp.dir_b == 0)
				ft_rotate_b(data);
			else
				ft_rev_rotate_b(data);
		}
		ft_push_a(data);
	}
	while (data->a[0] != 1)
	{
		if (ft_find_index(data->a, data->size_a, 1) <= data->size_a / 2)
			ft_rotate_a(data);
		else
			ft_rev_rotate_a(data);
	}
}
