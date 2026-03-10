/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:49:56 by bhamani           #+#    #+#             */
/*   Updated: 2025/08/12 09:50:10 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_rgb(char **rgb)
{
	int	i;

	if (!rgb)
		return ;
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
}

int	check_duplicate_color(t_color *color, char *line)
{
	if (color->r != -1)
	{
		if (line[0] == 'F')
			print_error("Duplicate F (floor) color element");
		else
			print_error("Duplicate C (ceiling) color element");
		return (FALSE);
	}
	return (TRUE);
}
