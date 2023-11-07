#include "includes/fdf.h"

static int is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int is_hex_number(char *s)
{
	int	i;

	i = 0;
	if (*s == '\n')
		return (0);
	while (s[i] && (is_number(s[i]) || (s[i] >= 'a' && s[i] <= 'f') ||
					(s[i] >= 'A' && s[i] <= 'F') || s[i] == '\n'))
		i++;
	if (!s[i] || s[i] == ' ')
		return (i);
	return (0);
}

static int is_hex_color(char *s)
{
	if (*s && s[1] && *s == '0' && s[1] == 'x')
		s += 2;
	else
		return (0);
	while (*s)
	{
		if (is_number(*s))
			s++;
		else if (*s >= 'a' && *s <= 'f')
			s++;
		else if (*s >= 'A' && *s <= 'F')
			s++;
		else
			return (0);
	}
	if (*s == 'x')
		return (0);
	return (1);
}

int is_valid_line(char *s, int i)
{
	while (*s)
	{
		if (is_number(*s))
			i++;
		if (*s == ' ' || is_number(*s) || *s == '\n')
			s++;
		else if (*s == '-' && s[1] && is_number(s[1]))
			s++;
		else if (*s == ',' && s[1] && s[1] == '0' && s[2] && s[2] == 'x' && s[3])
		{
			if (is_hex_number(s + 3))
				s = s + 3 + (is_hex_number(s + 3));
			else
				return (0);
		}
		else if (*s == '0' && s[1] && s[1] == 'x' && s[2])
			s += 2;
		else
			break;
	}
	if (*s)
		return (0);
	return (i);
}

void	add_color(char *s, int **num_arr, int col)
{
	while (*s)
	{
		if (*s == ',')
		{
			if (is_hex_color(s + 1))
				num_arr[col][1] = ft_atoi_hex(s + 1);
			else
				num_arr[col][1] = 0xFF0000;
			return ;
		}
		s++;
	}
	if (!*s)
		num_arr[col][1] = 0x0;
	return ;
}
