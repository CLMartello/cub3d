/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:36:42 by clumertz          #+#    #+#             */
/*   Updated: 2026/03/12 19:50:20 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	tex_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n' && s[i] != ' ')
		i++;
	return (i);
}

char	*get_texture(char *str)
{
	int	i;
	int	len;
	char	*dest;

	len = tex_strlen(str);
	dest = malloc(len * sizeof(char) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
