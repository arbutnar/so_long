#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	background;
} t_zone;

typedef struct s_shape
{
	char type;
	float x;
	float y;
	float radius;
	char color;
} t_shape;

int	ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

int	error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

void clean_all(FILE *file, char **p)
{
	int i = 0;

	if (file)
		fclose(file);
	if (p == NULL)
		return ;
	while (p[i])
	{
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

void	print_drawing(t_zone *zone, char **drawing)
{
	int y;

	y = 0;
	while (y < zone->height)
	{
		ft_putstr(drawing[y]);
		ft_putchar('\n');
		y++;
	}
}

char **create_zone(t_zone *zone, FILE *file)
{
	char 	**mtx;
	int		i;
	int		j;

	if ((fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (NULL);
	if (!(mtx = (char **)malloc(sizeof(char *) * zone->height + 1)))
		return (NULL);
	i = 0;
	while (i < zone->height)
	{
		if (!(mtx[i] = (char *)malloc(sizeof(char) * zone->width + 1)))
			return (NULL);
		j = 0;
		while (j < zone->width)
		{
			mtx[i][j] = zone->background;
			j++;
		}
		mtx[i][j] = '\0';
		i++;
	}
	mtx[i] = NULL;
	return (mtx);
}

int	in_circle(float y, float x, t_shape *shape)
{
	float	distance;

	distance = sqrtf(powf(x - shape->x, 2.) + powf(y - shape->y, 2.));
	if (distance <= shape->radius)
	{
		if ((shape->radius - distance) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void	draw_circle(t_zone *zone, char **drawing, t_shape *shape)
{
	float ret;
	int y;
	int x;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			ret = in_circle((float)y, (float)x, shape);
			if ((shape->type == 'c' && ret == 2)
				|| (shape->type == 'C' && ret))
					drawing[y][x] = shape->color;
			x++;
		}
		y++;
	}
}

int	draw_shape(t_zone *zone, FILE *file, char **drawing)
{
	t_shape shape;
	int ret;

	while ((ret = fscanf(file, "%c %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.radius, &shape.color)) == 5)
	{
		if (shape.radius <= 0.00000000 || (shape.type != 'c' && shape.type != 'C'))
			return (0);
		draw_circle(zone, drawing, &shape);
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

	zone.width = 0;
	zone.height = 0;
	zone.background = 0;
	drawing = NULL;
	if (argc != 2)
		return (error_msg("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (error_msg("Error: Operation file corrupted\n"));
	drawing = create_zone(&zone, file);
	if (drawing == NULL)
	{
		clean_all(file, NULL);
		return(error_msg("Error: Operation file corrupted\n"));
	}
	if (!(draw_shape(&zone, file, drawing)))
	{
		clean_all(file, drawing);
		return (error_msg("Error: Operation file corrupted\n"));
	}
	print_drawing(&zone, drawing);
	clean_all(file, drawing);
	return 0;
}