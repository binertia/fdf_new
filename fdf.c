#include "includes/fdf.h"
#include "includes/get_next_line.h"
#include "minilibx/mlx.h"

typedef	struct	s_node
{
	int				**set;
	struct s_node	*next;
}		t_node;

typedef	struct	s_max
{
	int				col;
	int				row;
}		t_max;

typedef struct	s_img
{
	void	*img;

}		t_img;

typedef struct	s_var
{
	void	*mlx;
	void	*win;
}		t_var;

void	init_mlxwin_img(t_var *var, t_img *img)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window( var->mlx, 800, 600, "fdf");

}

char	get_row();
t_node	*get_input(int fd, t_max *max)
{
	t_node	*head;
	char	*line;
	int		prev;

	prev = 0;
	head = NULL;
	max->col = 0;
	max->row = 0;
	if (fd == -1)
		return ((t_node *){0, NULL}); //:TODO: error exit (read file error)
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ; // EOF
		else if (check_line(line))
			return (0);
		update_map(&head);
	}
	return (head);
}


int	main(int ac, char *av[])
{
	t_img	img;
	t_max	max;
	t_node	*head;
	t_var	var;

	if (ac != 2)
		return (2); //:TODO: error exit (no args for program)
	head = get_input(open(av[1], O_RDONLY), &max);
	if (!head)
		return (2); //:TODO: error exit (no _______________)
	init_mlxwin_img(&var, img);
}
