#include "cub3d.h"

void	read_fd(char *filename, t_data *data)
{
	char	*str;
	int		fd;

	fd = check_fd(filename);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (!ft_strncmp(str, "NO", 2))
			data->NO = ft_strtrim(str, "NO ");
		else if (!ft_strncmp(str, "SO", 2))
			data->SO = ft_strtrim(str, "SO ");
		else if (!ft_strncmp(str, "WE", 2))
			data->WE = ft_strtrim(str, "WE ");
		else if (!ft_strncmp(str, "EA", 2))
			data->EA = ft_strtrim(str, "EA ");
		else if (!ft_strncmp(str, "F", 1))
		{
			str = ft_strtrim(str, "F ");
			data->F = rgb(str);
		}
		else if (!ft_strncmp(str, "C", 1))
		{
			str = ft_strtrim(str, "C ");
			data->C = rgb(str);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(&data);
	read_fd(argv[1], &data);
	// printf("%s", data.NO);
	// printf("%s", data.SO);
	// printf("%s", data.WE);
	// printf("%s", data.EA);
	// printf("%d\n", data.F);
	// printf("%d", data.C);
	// print_matrix(data.map);
	return 0;
}