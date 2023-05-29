#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
	int width;
	int height;
	char background;
} t_zone;

typedef struct s_shape
{
	char type;
	float width;
	float height;
	float y;
	float x;
	char color;
} t_shape;

int	ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

int error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

void	clean_all(FILE *file, char **p)
{
	int i = 0;

	if (file)
		fclose(file);
	if (p == NULL)
		return ;
	while (p[i]) {
		free(p[i]);
		i++;
	}
	free(p);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_matrix(char **mtx, t_zone *zone)
{
	int y;

	y = 0;
	while (y < zone->height)
	{
		ft_putstr(mtx[y]);
		ft_putchar('\n');
		y++;
	}
}

char **draw_zone(t_zone *zone, FILE *file)
{
	char **mtx;
	int y;
	int x;

	if ((fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (NULL);
	mtx = (char **)malloc(sizeof(char *) * (zone->height + 1));
	if (!mtx)
		return (NULL);
	y = 0;
	while (y < zone->height)
	{
		x = 0;
		mtx[y] = (char *)malloc(sizeof(char) * (zone->width + 1));
		if (!mtx[y])
			return (NULL);
		while (x < zone->width)
		{
			mtx[y][x] = zone->background;
			x++;
		}
		mtx[y][x] = '\0';
		y++;
	}
	mtx[y] = NULL;
	return (mtx);
}

int in_rectangle(float y, float x, t_shape *shape)
{
	if (x < shape->x || x > (shape->x + shape->width)
		|| y < shape->y || y > (shape->y + shape->height))
			return (0);
	if ((x - shape->x) < 1.00000000 || (shape->x + shape->width) - x < 1.0000000
		|| (y - shape->y) < 1.000000000 || (shape->y + shape->height) - y < 1.00000000)
			return (2);
	return (1);
}

void	draw_rectangle(t_zone *zone, char **drawing, t_shape *shape)
{
	int y;
	int x;
	int ret;

	y = 0;
	while(y < zone->height)
	{
		x  = 0;
		while (x < zone->width)
		{
			ret = in_rectangle((float)y, (float)x, shape);
			if ((shape->type == 'r' && ret == 2) || (shape->type == 'R' && ret))
				drawing[y][x] = shape->color;
			x++;
		}
		y++;
	}
}

int	draw_shape(t_zone *zone, FILE *file, char **drawing)
{
	t_shape shape;
	int	ret;

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.width, &shape.height, &shape.color)) == 6)
	{
		if (shape.width <= 0.00000000 || shape.height <= 0.00000000
			|| (shape.type != 'r' && shape.type != 'R'))
				return (0);
		draw_rectangle(zone, drawing, &shape);
	}
	if (ret != -1)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_zone zone;
	FILE *file;
	char **drawing;

	if (argc != 2)
		return (error_msg("Error: arguments\n"));
	zone.width = 0;
	zone.height = 0;
	zone.background = 0;
	drawing = NULL;
	file = fopen(argv[1], "r");
	if (file == NULL)
		return (error_msg("Error: Operation file corrupted\n"));
	drawing = draw_zone(&zone, file);
	if (drawing == NULL)
	{
		clean_all(file, NULL);
		return (error_msg("Error: Operation file corrupted\n"));
	}
	if (!(draw_shape(&zone, file, drawing)))
	{
		clean_all(file, drawing);
		return (error_msg("Error: Operation file corrupted\n"));
	}
	print_matrix(drawing, &zone);
	clean_all(file, drawing);
	return 0;
}
			