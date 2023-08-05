#include "push_swap.h"

void	ft_initialize(t_struct *data, int argc, char *argv[])
{
	char	*str;

	data->a = NULL;
	data->size_a = 0;
	data->b = NULL;
	data->size_b = 0;
	data->lis = NULL;
	data->size_lis = 0;
	if (argc == 2)
	{
		str = ft_strjoin("0 ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		data->size_a = ft_count_rows(argv) - 1;
	}
	else
		data->size_a = argc - 1;
	data->a = ft_convert(data->size_a, argv);
	if (ft_strncmp(argv[0], "0", 1) == 0)
		ft_free_matrix((void **)argv, data->size_a + 1);
}

int		*ft_semplifier(int *arr, int size)
{
	int *cpy;
	int i;
	int j;

	cpy = ft_cpyarray(arr, size);
	cpy = ft_sort(cpy, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while(j < size)
		{
			if (arr[i] == cpy[j])
			{
				arr[i] = j + 1;
				break;
			}
			j++;
		}
		i++;
	}
	free(cpy);
	return (arr);
}

int		*ft_sort(int *arr, int size)
{
	int i;
	int flag = 0;

	while(flag == 0)
	{
		flag = 1;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1], size);
				flag = 0;
			}
			i++;
		}
	}
	return (arr);
}

int *ft_convert(int argc, char **argv)
{
	int *arr;
	int i;

	ft_check_for_numbs(argc, argv);
	arr = malloc (sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_check_for_doubles(argc, arr);
	return (arr);
}

