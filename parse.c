
#include "../includes/cub3d.h"

void	valid_map(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '1' || map[i] == '0')
			i++;
		if (map[i] == 'N' || map[i] == 'E' || map[i] == 'S' || map[i] == 'W')
			i++;
		else
			printf("Map not valid.\n");
	}
}

int	*parse_rgb(char *line)
{
	int	i;
	int	j;
	int	n;
	int	*rgb;

	i = 0;
	j = 0;
	rgb = malloc(3 * sizeof(int));
	if (!rgb)
		return (NULL);
	while (line[i] != '\0' && j < 3)
	{
		if (line[i] == ' ' || line[i] == ',')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			n = atoi(line + i);
			if (n >= 0 && n <= 255)
			{
				rgb[j] = n;
				j++;
				n = -1;	
			}
	                while (line[i] >= '0' && line[i] <= '9')
                        i++;

		}
		else
			return (NULL);
	}
	printf("R   founded: %d\n", rgb[0]);
	printf(" G  founded: %d\n", rgb[1]);
	printf("  B founded: %d\n", rgb[2]);
	return (rgb);
}

char	*parse_texture(char *line)
{
	int	i;
	char	*texture;

	i = 0;
	texture = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '.' && line[i + 1] == '/')
		{
			texture = get_texture(line + i);
			printf ("Texture founded: %s\n", texture);
			return (texture);
		}
		i++;
	}
	return (texture);
}

void	*verify_parse(char *line, t_img *img)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'N' && line[i + 1] == 'O')
			return (img->n_wall = parse_texture(line));
		else if (line[i] == 'S' && line[i + 1] == 'O')
			return (img->s_wall = parse_texture(line));
		else if (line[i] == 'W' && line[i + 1] == 'E')
			return (img->w_wall = parse_texture(line));
		else if (line[i] == 'E' && line[i + 1] == 'A')
			return (img->e_wall = parse_texture(line));
		else if (line[i] == 'F')
			return (img->floor = parse_rgb(line + 1));
		else if (line[i] == 'C')
			return (img->ceiling = parse_rgb(line + 1));
		i++;
	}
	return (NULL);
}

int	parse_cub_file(char *file)
{
	int	fd;
	char	*line;
        t_img   *img;

	fd = -1;
	line = NULL;
        img = malloc(sizeof(t_img));
        if (!img)
                return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("Unable to read .cub file.\n");
	while ((line = get_next_line(fd)))
	{
		verify_parse(line, img);
		free(line);
	}
	return (0);
	//read cub file
	//store lines properly
	//verify and check .cub extension

}
