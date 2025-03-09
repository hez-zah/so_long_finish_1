/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:42:38 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 18:15:26 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	img_put(t_map *slong, char *type, int i, int j)
{
	slong->mlx_img = mlx_xpm_file_to_image(slong->mlx, type,
			&slong->h_map, &slong->w_map);
	mlx_put_image_to_window(slong->mlx, slong->mlx_win,
		slong->mlx_img, j * SIZE, i * SIZE);
}

static void	aid_put_image(t_map *slong, int i, int j)
{
	if (slong->map[i][j] == '1')
		img_put(slong, WALL, i, j);
	else if (slong->map[i][j] == '0')
		img_put(slong, SPACE, i, j);
	else if (slong->map[i][j] == 'P')
		img_put(slong, PMAN_D, i, j);
	else if (slong->map[i][j] == 'C')
		img_put(slong, COLLECT, i, j);
	else if (slong->map[i][j] == 'E')
		img_put(slong, CDOOR, i, j);
}

void	put_image(t_map *slong)
{
	int	i;
	int	j;

	i = -1;
	while (slong->map[++i])
	{
		j = -1;
		while (slong->map[i][++j])
			aid_put_image(slong, i, j);
	}
}
