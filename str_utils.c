/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:36:42 by clumertz          #+#    #+#             */
/*   Updated: 2026/03/21 17:58:13 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static int	tex_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n' && s[i] != ' ')
		i++;
	return (i);
}

char	*get_line(char *str)
{
	int		i;
	int		len;
	char	*dest;

	len = tex_strlen(str);
	dest = malloc(len * sizeof(char) + 1);
	if (!dest)
		ft_error(NULL, ERR_MALLOC);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
