/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksongchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:26:50 by ksongchu          #+#    #+#             */
/*   Updated: 2023/11/04 15:34:39 by ksongchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
//# include <sys/fcntl.h> // for arm64
# include "get_next_line.h"
# include "../minilibx/mlx.h"

# define FIXED_SCALE 16

typedef	struct	s_max
{
	int				col;
	int				row;
	int				box_size;
}		t_max;

typedef	struct	s_node
{
	int				**set;
	struct s_node	*next;
}		t_node;

t_node	*get_map(int fd, t_max *max);
void ft_free_list(t_node **map);
int is_valid_line(char *s, int i);
void	add_color(char *s, int **num_arr, int col);
void	ft_new_list_add_back(int **content, t_node **node);

#endif
