/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:36:42 by clumertz          #+#    #+#             */
/*   Updated: 2026/03/26 20:07:39 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((s1)[i] != (s2)[i])
			return ((s1)[i] - (s2)[i]);
		i++;
	}
	return (0);
}

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
	while (s[i] != '\0' && s[i] != '\n')
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
