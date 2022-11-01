#include "mlx.h"
#include "libft/libft.h"

int main()
{
    ft_printf("burakk\n");
    void *ptr = mlx_init();
     mlx_new_window(ptr, 500, 500, "burak");
    mlx_loop(ptr);
}