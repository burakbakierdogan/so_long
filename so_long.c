/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:31 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/21 07:30:25 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*player;
	void	*ground;
	int		x;
	int		y;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{

	if (keycode == 100)
	{
		if (vars -> x == 320)
			return (0);
		mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> ground, vars -> x,  vars -> y);
		vars -> x += 64;
		mlx_put_image_to_window(vars->mlx, vars -> win, vars -> player, vars -> x , vars -> y);
		return (0);
	}
	else if (keycode == 97)
	{
		if (vars -> x == 64)
			return (0);
		mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> ground, vars -> x, vars -> y);
		vars -> x -= 64;
		mlx_put_image_to_window(vars->mlx, vars -> win, vars -> player, vars -> x, vars -> y);
	}
	else if (keycode == 119)
	{
		if (vars -> y == 64)
			return (0);
		mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> ground, vars -> x, vars -> y);
		vars -> y -= 64;
		mlx_put_image_to_window(vars->mlx, vars -> win, vars -> player, vars -> x, vars -> y);
	}
	else if (keycode == 115)
	{
		if (vars -> y == 320)
			return (0);
		mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> ground, vars -> x, vars -> y);
		vars -> y += 64;
		mlx_put_image_to_window(vars->mlx, vars -> win, vars -> player, vars -> x, vars -> y);
	}

	return (0);
}

static	void	ft_test()
{
	void	*mlx;
	void	*mlx_window;
	int		x;
	int		y;
	void	*res;
	void	*res2;
	t_vars	vars;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 320, 256, "burak");
	x = 0;
	y = 0;
	res = mlx_xpm_file_to_image(mlx,"./circle.xpm", &x,&y);
	res2 = mlx_xpm_file_to_image(mlx,"./ground.xpm", &x,&y);
	vars.mlx = mlx;
	vars.win = mlx_window;
	vars.player = res;
	vars.ground = res2;
	vars.x = 128;
	vars.y = 128;
	x = 0;
	y = 0;
	mlx_put_image_to_window(mlx, mlx_window, vars.ground, 0, 0);
	while (y <= 448)
	{
		while (x <= 448)
		{
			mlx_put_image_to_window(mlx, mlx_window, vars.ground, x, y);
			x += 64;
		}
		x = 0;
		y += 64;
	}
	mlx_put_image_to_window(mlx, mlx_window, vars.player, 128, 128);


	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);

	mlx_loop(mlx);
}
*/
/*
static	void ft_test2()
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	void	*mlx = mlx_init();
	void	*mlx_window = mlx_new_window(mlx,320,256,"burak");
	void	*pic = mlx_xpm_file_to_image(mlx,"textures/wall.xpm",&x,&y);
	mlx_put_image_to_window(mlx, mlx_window, pic, 256, 192);
	mlx_loop(mlx);

}
*/
int main(int ac, char *argv[])
{
	t_map	map;
	char	**map_src;

	map_src = ft_error_management (open (argv[1], O_RDONLY), ac, argv[1]);
	ft_get_map_data(&map, map_src);
	ft_printf("%d\n", map.wall_nbr);
}