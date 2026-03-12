
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

/*int	*parse_rgb(char *rgb)
{
	int i = 0;

	while (rgb[i] != '\0')
	{
		if (rgb )
	}
}*/



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
	int	r;
	int	g;
	int	b;
	int	rgb[3];

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
			r = atoi(line + i);
			if (r >= 0 && r <= 255)
		if (line[i] == ',')
			i++;
				
	}
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
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
			texture = strdup(line + i);
			printf ("Texture founded: %s\n", texture);
			return (texture);
		}
		i++;
	}
	return (texture);
}

void	*verify_parse(char *line)
{
	int	i;
	t_img	*img;

	i = 0;
	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
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
			return (img->floor = parse_rgb(line));
		else if (line[i] == 'C')
			return (img->ceiling = parse_rgb(line));
		i++;
	}
	return (NULL);
}

int	parse_cub_file(char *file)
{
	int	fd;
	char	*line;

	fd = -1;
	line = NULL;
	//open cub file
	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("Unable to read .cub file.\n");
	
	while ((line = get_next_line(fd)))
	{
		verify_parse(line);
		free(line);
	}
	return (0);
	//read cub file
	//store lines properly
	//verify and check .cub extension

}
