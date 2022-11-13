#include "mlx.h"
#include "libft/libft.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
    t_data img;
    void *ptr = mlx_init();
    void *mlx_win =  mlx_new_window(ptr, 500, 500, "burak");
    img.img = mlx_new_image(ptr, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    
    int n = 500;
    int x = 0;
    int y = 0;
    while (y < 500)
    {
        while (n--)
        {    
            my_mlx_pixel_put(&img, x, y, 0x00FF0000);
            x += 1;
        }
        n = 600;
        x = 0;
        y++;
    }
  // mlx_put_image_to_window(ptr, mlx_win, img.img, 0, 0);
    n = 40;
    x = 40;
    y = 40;
    while (y < 80)
    {
        while (n--)
        {
            my_mlx_pixel_put(&img, x, y, 0xCBDCCB);
            x++;
        }
        n = 40;
        x = 40;
        y++;
    }
    mlx_put_image_to_window(ptr, mlx_win, img.img, 0, 0);
    mlx_loop(ptr);
    ptr = mlx_win;
}