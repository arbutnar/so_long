#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"


typedef	struct	s_struct
{
	int *a;
	int size_a;
	int *b;
	int size_b;
	int	*lis;
	int	size_lis;

}				t_struct;

typedef	struct	s_best
{
	int value_b;
	int	value_a;
	int move_b;
	int move_a;
	int dir_b;
	int dir_a;
	int moves;
}				t_best;

t_best	ft_best(t_best *best, t_struct *data);
int		ft_move(int size, int i);
int		ft_directions(int size, int i);
void	ft_algorithm(t_struct *data);

int		ft_checkorder(int *a, int size);
void	ft_check_for_numbs(int argc, char *argv[]);
void	ft_check_for_doubles(int argc, int *arr);

void	ft_go_away(t_struct *data);

int		ft_count_rows(char *argv[]);
int		*ft_convert(int argc, char **argv);
int		*ft_sort(int *arr, int size_arr);
void	ft_initialize(t_struct *data, int argc, char *argv[]);
int		*ft_semplifier(int *arr, int size_arr);

void	ft_lis(t_struct *data);

void	ft_push(int *ar_one, int *ar_two, int *size_one, int *size_two);
void	ft_push_a(t_struct *data);
void	ft_push_b(t_struct *data);

void	ft_rev_rotate(int *arr, int size);
void	ft_rev_rotate_a(t_struct *data);
void	ft_rev_rotate_b(t_struct *data);
void	ft_rev_rotate_rotate(t_struct *data);

void	ft_rotate(int *arr, int size);
void	ft_rotate_a(t_struct *data);
void	ft_rotate_b(t_struct *data);
void	ft_rotate_rotate(t_struct *data);

void	ft_swap(int *a, int *b, int size);
void	ft_swap_a(t_struct *data);
void	ft_swap_b(t_struct *data);
void	ft_swap_swap(t_struct *data);

int		ft_count_rows(char *argv[]);
int		ft_find_index(int *arr, int size, int i);
int		*ft_cpyarray(int *arr, int size_arr);
//void	ft_print_array(int *arr, int size_arr);
void	ft_free_matrix(void *matrix[], int size);
void	ft_exit(t_struct *data, int i);

#endif