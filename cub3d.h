/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:16:07 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/10 20:18:33 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

int	parse_cub_file(char *file);
void	*verify_parse(char *line);
char	*parse_texture(char *line);
int	*parse_rgb(char *line);
void	valid_map(char *map);
char    *get_next_line(int fd);

#endif
