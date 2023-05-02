#include "cub3d.h"

void	error_msg(char *str)
{
	printf("%s Error\n", str);
	exit(1);
}

int	check_fd(char *name)
{
	int fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		error_msg("File");
	return (fd);
}

int	fd_len(char *filename)
{
	int		len;
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	len = 0;
	while (str != NULL)
	{
		if (str[0] != '\n')
			len++;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (len);
}

int	rgb(char *str)
{
	char	**mtx;
	int		rgb;
	int		r;
	int		g;
	int		b;

	mtx = ft_split(str, ',');
	r = ft_atoi(mtx[0]);
	g = ft_atoi(mtx[1]);
	b = ft_atoi(mtx[2]);
	rgb = 65536 * r + 256 * g + b;
	return (rgb);
}

void	print_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i] != NULL)
	{
		printf("%s", mtx[i]);
		i++;
	}
}