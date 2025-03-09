#include "../so_long_bonus.h"

static void    position_war_collect(t_map **slong)
{
    int i;
    int j;
    int d;

    (*slong)->coll = malloc((*slong)->war_collect * sizeof(t_collect));
    i = -1;
    d = 0;
    while ((*slong)->map[++i])
    {
        j = -1;
        while ((*slong)->map[i][++j])
        {
            if ((*slong)->map[i][j] == 'X')
            {
                (*slong)->coll[d].x_collect = i;
                (*slong)->coll[d].y_collect = j;
                d++;
            }
        }
    }
}

void    put_war_img(t_map **slong)
{
    int i;

    i = -1;
    while (++i < (*slong)->war_collect)
    {
        mlx_put_image_to_window((*slong)->mlx, (*slong)->mlx_win, (*slong)->img,
		(*slong)->coll[i].y_collect * SIZE, (*slong)->coll[i].x_collect * SIZE);
    }
    
}

void	render_img(t_map **slong)
{
	int			img_w;
	int			img_h;

	(*slong)->e_var.imgs[0] = COLLECT_1;
	(*slong)->e_var.imgs[1] = COLLECT_2;
	(*slong)->e_var.imgs[2] = COLLECT_3;
	(*slong)->e_var.imgs[3] = COLLECT_2;
	(*slong)->e_var.imgs[4] = COLLECT_1;
	(*slong)->img = mlx_xpm_file_to_image(
			(*slong)->mlx, SPACE, &img_w, &img_h);
    put_war_img(slong);
	(*slong)->img = mlx_xpm_file_to_image(
			(*slong)->mlx, (*slong)->e_var.imgs[(*slong)->e_var.x],
			&img_w, &img_h);
    put_war_img(slong);
}

int animation_collect(t_map **slong)
{
    position_war_collect(slong);
    if ((*slong)->e_var.sleep-- <= 0)
	{
		(*slong)->e_var.x++;
		(*slong)->e_var.sleep = 5;
	}
	if ((*slong)->e_var.x == 3)
		(*slong)->e_var.x = 0;
	if ((*slong)->e_var.sleep_for_move-- <= 0)
		(*slong)->e_var.sleep_for_move = 30;
    render_img(slong);
    free((*slong)->coll);
    return (0);
}
