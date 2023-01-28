#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_issign(char c);
int		ft_atoi(const char *str);
void	print_error(int num);
void	free_stack(t_info *info);
char	**ft_split(char const *s, char c);
void	fill_stack(char *argv[], t_info *info);
void	sort_stack(t_info *info);
void	indexing_sort_stack(t_info *info);
void	sand_watch(t_info *info);
void	hard_sort(t_info *info);

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