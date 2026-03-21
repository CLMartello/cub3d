
#include "../includes/cub3d.h"

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		while (ft_isspace(line[i]) == 1)
			i++;
		if (line[i] == '1')
			return (1);
		else
			break ;
	}
	return (0);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}