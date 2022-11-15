/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:31 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/15 05:29:14 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data -> addr + (y * data -> line_length + x * (data -> bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static	void	ft_test()
{
	t_data	img;
	void	*mlx;
	void	*mlx_window;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 500, 500, "burak");
	img.img = mlx_new_image(mlx, 500,500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	x = 0;
	y = 9;
	//ft_my_pixel_put(&img, x++, y, 0x00FF0000);
		while (x < 50)
		{
			while (y < 50)
				ft_my_pixel_put(&img, x, y++, 0x96FF00FF);
			y = 0;
			x++;
		}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
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