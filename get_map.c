#include "includes/fdf.h"

void	ft_free_char_set(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

int	fill_num_arr(int **num_arr, char **arr, int size, t_node **head)
{
	int	i;
	int	col_size;

	i = 0;
	col_size = 1;
	while (i < size)
	{
		num_arr[i] = (int *)malloc(sizeof(int) * 2);
		if (!num_arr[i])
			return (0); /// error handle
		num_arr[i][0] = ft_atoi(arr[i]);
		if (num_arr[i][0] > col_size)
			col_size = num_arr[i][0];
		add_color(arr[i], num_arr, i);
		i++;
	}
	num_arr[i] = NULL;
	ft_new_list_add_back(num_arr, head);
	ft_free_char_set(arr);
	return (col_size);
}
//--

int	update_map(t_node **head, int *max_col, char **s)
{
	int	i;
	int	**num_arr;

	i = 0;
	while (s[i])
		i++;
	num_arr = (int **)malloc(sizeof(int *) * (i + 1)); //
	if (!num_arr)
		return (0); //:TODO: handle malloc error
	*max_col = fill_num_arr(num_arr, s, i, head);
	//ft_free_char_set(s);
	return (0);
}

void	ft_exit_map_error(char **line, t_node *map)
{
	perror("Invalid Map");
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (map)
		ft_free_list(&map);
	exit(1);
}

t_node	*get_map(int fd, t_max *max)
{
	t_node	*head;
	char	*line;

	if (fd == -1)
		return (0); //:TODO: error exit (read file error)
	head = NULL;
	max->row = 0;
	max->col = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line || *line == '\n')
			break ; // EOF
		else if (!is_valid_line(line, 0))
			ft_exit_map_error(&line, head);
		update_map(&head, &max->col, ft_split(line, ' '));
		max->row++;
		free(line);
	}
	free(line);
	return (head);
}
