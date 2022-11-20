/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:31 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/20 10:37:37 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode)
		mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> img2, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars -> win, vars -> img1, 64, 0);
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
	mlx_window = mlx_new_window(mlx, 448, 480, "burak");
	x = 0;
	y = 0;
	res = mlx_xpm_file_to_image(mlx,"./dene.xpm", &x,&y);
	res2 = mlx_xpm_file_to_image(mlx,"./ground.xpm", &x,&y);
	vars.mlx = mlx;
	vars.win = mlx_window;
	vars.img1 = res;
	vars.img2 = res2;
	mlx_put_image_to_window(mlx, mlx_window, res2, 0, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 64, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 128, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 192, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 256, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 320, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 384, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 448, 0);
	mlx_put_image_to_window(mlx, mlx_window, res2, 0, 64);
	mlx_put_image_to_window(mlx, mlx_window, res2, 64, 64);
	mlx_put_image_to_window(mlx, mlx_window, res2, 128, 64);
	mlx_put_image_to_window(mlx, mlx_window, res2, 192, 64);
	mlx_put_image_to_window(mlx, mlx_window, res2, 256, 64);
	mlx_put_image_to_window(mlx, mlx_window, res2, 320, 64);
	mlx_put_image_to_window(mlx, mlx_window, res2, 384, 64);
	mlx_put_image_to_window(mlx, mlx_window, res2, 448, 64);
	mlx_put_image_to_window(mlx, mlx_window, res, 0, 0);

	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);

	mlx_loop(mlx);
}

int main(int ac, char *argv[])
{
	char	**map;
	int		i;

	if (ac != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	map = ft_error_management (open (argv[1], O_RDONLY));
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	ft_test();
}