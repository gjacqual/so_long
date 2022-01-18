/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:25:30 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/18 16:21:37 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_mlx_win()
{
	// free(game->map);
	exit(1);
}

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

// int	render_next_frame(void *YourStruct);

/* Initializing the game window */
void	xwindow_init(void)
{
	t_vars	vars;
	
	// void	*img;
	t_image img;
	char	*sprite_grass = "./images/grass.xpm";
	char	*sprite_rock = "./images/rock.xpm";
	char	*sprite_chest = "./images/chest.xpm";
	char	*sprite_orb = "./images/blue_orb.xpm";
	char	*sprite_player = "./images/player.xpm";
	char	*sprite_skelet = "./images/skelet.xpm";
	// char *score;


	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		error("Window initialization failed");
	vars.mlx_win = mlx_new_window(vars.mlx, 800, 600, "So_long Gjacqual");
	
	// img.img = mlx_new_image(vars.mlx, 800, 600);
	img.grass = mlx_xpm_file_to_image(vars.mlx, sprite_grass, &img.img_width, &img.img_height);
	img.rock = mlx_xpm_file_to_image(vars.mlx, sprite_rock, &img.img_width, &img.img_height);
	img.exit = mlx_xpm_file_to_image(vars.mlx, sprite_chest, &img.img_width, &img.img_height);
	img.orb = mlx_xpm_file_to_image(vars.mlx, sprite_orb, &img.img_width, &img.img_height);
	img.player = mlx_xpm_file_to_image(vars.mlx, sprite_player, &img.img_width, &img.img_height);
	img.enemy = mlx_xpm_file_to_image(vars.mlx, sprite_skelet, &img.img_width, &img.img_height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.grass, 30, 0);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.rock, 50, 50);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.exit, 100, 100);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.orb, 150, 150);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.player, 200, 200);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.enemy, 250, 250);

	mlx_string_put(vars.mlx, vars.mlx_win, 10, 15, 0x005616, "Move count:");
	
	mlx_hook(vars.mlx_win, 17, 0, close_mlx_win, &vars);
	// mlx_key_hook(vars.mlx_win, key_hook, &vars);
	// mlx_loop_hook(vars.mlx, render_next_frame, YourStruct);
	mlx_loop(vars.mlx);
}
