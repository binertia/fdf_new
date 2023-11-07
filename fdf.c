#include "includes/fdf.h"
#include <stdio.h>


typedef struct	s_img
{
	// default
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	//custom
	int		box_size;
	int		current_x;
	int		current_y;
}		t_img;

typedef struct	s_var
{
	void	*mlx;
	void	*win;
	void	*img;
}		t_var;

void	setup_mlx(t_var *var, t_img *img)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1000, 800, "fdf");
	img->img = mlx_new_image(var->mlx, 1000, 800);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	var->img = &img;
}

void	ft_log_node(t_node *head)
{
	int	i;
	while (head)
	{
		i = -1;
		while (head->set[++i])
			printf("[%i : %i] ",head->set[i][0], head->set[i][1]);
		printf("\n");
		head = head -> next;
	}
}

void	ft_error_exit(char *s)
{
	perror(s);
	exit(1);
}

///////////// ===========================================

void	calc_init_draw(t_max max, t_img *img)
{
	if (max.col + max.row < 10)
		img->box_size = 60;
	else if (max.col + max.row < 40)
		img->box_size = 20;
	else
		img->box_size = 4;
	img->current_x = 600 + (int)((max.col - max.row) * img->box_size * sqrt(3) / 2);
	img->current_y = 200;
}
 
//======================================================

//t_data	calc_pos(t_img img, );

// t_data	calc_pos(t_arg curr, t_img *img, int *prev_dent, int *dent)
// {
// 	t_data	res;
// 	double	diff_x;
// 	int	diff_y;
//
// 	ft_init_color(&res, prev_dent, dent);
// 	diff_x = img->box_size * sqrt(3);
// 	diff_y = img->box_size;
// 	res.row = curr.row;
// 	res.col = curr.col;
// 	res.end_x = img->init_x + (curr.row * diff_x) - (curr.col * diff_x);
// 	res.start_x = img->init_x + (curr.row - 1) * diff_x - curr.col * diff_x;
// 	res.end_y = img->init_y + (curr.row + curr.col - (double)dent[0] ) * diff_y;
// 	res.start_y = img->init_y + ((curr.row - 1) + curr.col - (double)prev_dent[0] ) * diff_y;
// 	return (res);
// }

// void	draw_point_to_point(t_img **img, t_data curr)
// {
// 	t_calc	c;
//
// 	dif_x = (curr.end_x - curr.start_x) << FIXED_SCALE;
// 	dif_y = (curr.end_y - curr.start_y) << FIXED_SCALE;
//     if (abs(dif_x) > abs(dif_y))
//         steps = abs(dif_x >> FIXED_SCALE);
//     else
//         steps = abs(dif_y >> FIXED_SCALE);
//     x_inc = dif_x / steps;
//     y_inc = dif_y / steps;
//     x = curr.start_x << FIXED_SCALE;
//     y = curr.start_y << FIXED_SCALE;
// 	if ((y >> FIXED_SCALE) > 0 && (y >> FIXED_SCALE) < 1390 && (x >> FIXED_SCALE) > 0 && (x >> FIXED_SCALE) < 2560)
// 		my_mlx_pixel_put(*img,  x >> FIXED_SCALE, y >> FIXED_SCALE, curr.start_color);
// 	i = 0;
// 	while(i < steps)
// 	{
// 		ft_calc_curr_color(&curr);
//         x += x_inc;
//         y += y_inc;
// 		if ((y >> FIXED_SCALE) > 0 && (y >> FIXED_SCALE) < 1390 && (x >> FIXED_SCALE) > 0 && (x >> FIXED_SCALE) < 2560)
// 			my_mlx_pixel_put(*img, x >> FIXED_SCALE, y >> FIXED_SCALE, curr.start_color);
// 		i++;
//     }
// }

typedef	struct	s_pos
{
	int	col;
	int	row;
}			t_pos;

void	update_pos(int col, int row, t_pos *pos)
{
	pos->col = col;
	pos->row = row;
}

typedef	struct	s_data
{
	
}		t_data;

void	calc_pos(t_pos pos, int box_size, int prev_height, int curr_height)
{
}

void	drow_from_prev_col(t_img *img, int *col_arr, int row)
{
	int		col;
	int		*prev_height;
	t_pos	pos;
	t_data	*res_calc;

	col = 0;
	prev_height = NULL;
	while(col_arr[col])
	{
		update_pos(col, row, &pos);
		if (prev_height)
			calc_pos(pos, img->box_size, prev_height[0], col_arr[col]);
		if (col > 0)
			draw_point_to_point(&img, res_calc);
		*prev_height = curr[col];
		col++;
	}
}

void	draw_from_prev_row(t_img **img, int **curr_set,int **prev_set ,int current_col)
{
	int	i;
	t_data	res_calc;

	i = 0;
	while (prev_set[i] && curr_set[i])
	{
		res_calc = calc_pos();
		draw_point_to_point(img, );
		i++;
	}
}
		// i = 0;
		// while (head->set[i])
		// {
		// 	if (i != 0)
		// 		draw_point_to_point(&img, calc_pos((t_arg){i, j}, img, prev, head->num_arr[i]));
		// 	prev = head->num_arr[i];
		// 	i++;
		// }
void	draw_to_img(t_node *head,t_img *img)
{
	int	i;
	int	*prev;
	int	**previous_set;

	previous_set = NULL;
	i = 0;
	while (head)
	{
		draw_from_prev_col(&img, head->set[i], i);
		if (previous_set != NULL)
			draw_from_prev_row(&img, head->set, previous_set, i);
		previous_set = head->set;
		head = head -> next;
		i++;
	}
}
//=========================================

int	main(int ac, char *av[])
{
	t_img	img;
	t_max	max;
	t_node	*head;
	t_var	var;

	if (ac != 2)
		ft_error_exit("Invalid argument");
	head = get_map(open(av[1], O_RDONLY), &max);
	printf("finish get_map\n");
	if (!head)
		ft_error_exit("Map file is not useable");
	setup_mlx(&var, &img);
	calc_init_draw(max, &img);
	draw_to_img(head, &img);
	ft_log_node(head);
	ft_free_list(&head);
	return (0);
}

/////
///
/*
cc -Wall -Wextra -Werror -Iincludes   -c -o fdf.o fdf.c
fdf.c:97:41: error: unused parameter 'img' [-Werror,-Wunused-parameter]
void    init_mlxwin_img(t_var *var, t_img *img)
                                           ^
fdf.c:197:6: error: unused variable 'j' [-Werror,-Wunused-variable]
        int     j;
                ^
fdf.c:240:7: error: variable 'prev' set but not used [-Werror,-Wunused-but-set-variable]
        int             prev;
                        ^
fdf.c:277:8: error: unused variable 'img' [-Werror,-Wunused-variable]
        t_img   img;
                ^
fdf.c:280:8: error: unused variable 'var' [-Werror,-Wunused-variable]
        t_var   var;
                ^
5 errors generated.
make: *** [fdf.o] Error 1
*/
