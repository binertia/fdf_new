#include "includes/fdf.h"

static void	*ft_new_list(int **content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->set = content;
	new->next = NULL;
	return (new);
}

void	ft_new_list_add_back(int **content, t_node **node)
{
	t_node	*temp;

	if (!content)
		return ;
	if (*node == NULL)
	{
		*node = ft_new_list(content);
		return ;
	}
	temp = *node;
	while (temp && temp -> next)
		temp = temp -> next;
	temp->next = ft_new_list(content);
}

void ft_free_list(t_node **map)
{
	t_node	*temp;

	temp = *map;
	while (temp)
	{
		t_node *free_time = temp;
		temp = temp->next;
		int i = 0;
		while (free_time->set[i])
		{
			free(free_time->set[i]);
			i++;
		}
		free(free_time->set[i]);
		free(free_time->set);
		free(free_time);
		free_time = NULL;
	}
}
