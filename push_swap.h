#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	int				size_a;
	struct s_stack	*top_a;
	struct s_stack	*bottom_a;
	int				size_b;
	struct s_stack	*top_b;
	struct s_stack	*bottom_b;
	struct s_stack	*top_copy_a;
	struct s_stack	*bottom_copy_a;
}	t_info;

t_info	*ft_info_new();
void	fill_stack(char *argv[], t_info *info);
t_stack	*stack_push_a(int split_num, t_info *info);
t_stack	*stack_push_copy_a(int split_num, t_info *info);
void	check_argv(char *argv[]);
int	ft_isspace(char c);
int ft_issign(char c);
void	sort_stack(t_info *info);
void	indexing_sort_stack(t_info *info);
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
void	ft_check_array_sort(int *array, int size, int i);
int get_str_size(int argc, char *argv[]);
int	ft_atoi(const char *str);
void	print_error(int num);
void	sand_watch(t_info *info);

void	test_print(t_info *info);

void	pa(t_info *info);
void	pb(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);

#endif