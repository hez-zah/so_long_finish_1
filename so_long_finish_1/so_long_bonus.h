/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:53:43 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/09 21:06:59 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include "mlx.h"

# define MOVE_INTERVAL 50
# define MOVE_INTERVAL_1 100
# define SIZE 60

# define WALL "image/Wall.xpm"
# define SPACE "image/Space.xpm"
# define COLLECT "image/collect.xpm"
# define PMAN_R "image/jerry_right.xpm"
# define PMAN_L "image/jerry_left.xpm"
# define PMAN_U "image/jerry_right.xpm"
# define PMAN_D "image/jerry_left.xpm"
# define ODOOR "image/Open_Door.xpm"
# define CDOOR "image/Close_Door.xpm"
# define ENEMY_R "image/Enemy_right.xpm"
# define ENEMY_L "image/Enemy_left.xpm"
// animation collect
# define COLLECT_1 "image/1.xpm"
# define COLLECT_2 "image/2.xpm"
# define COLLECT_3 "image/3.xpm"

typedef struct s_collec
{
	int	x_collect;
	int	y_collect;
}	t_collect;

typedef struct s_sleep
{
	int		x;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_sleep;

typedef struct s_map
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	void		*img;
	char		**map;
	int			collect;
	int			h_map;
	int			w_map;
	int			x_p;
	int			y_p;
	int			x_e;
	int			y_e;
	bool		call;
	int			move;
	int			war_collect;
	t_collect	*coll;
	t_sleep		e_var;
}	t_map;

// free
void	fr_stack(t_map *slong);
void	free_double(char **str);

// copy map
char	**copy_map(char **map);

// position enemy
bool	get_enemy_position(t_map **slong);

// handle error
bool	handl_close(char **map);
bool	handl_error(t_map **slong);

// put image
void	put_image(t_map *slong);

// event
int		ft_hook(int prees, t_map **slong);
int		ft_exit(t_map *slong);

// animation
int		animation_collect(t_map **slong);
// void    get_position_collect(t_map **slong);

#endif