#include "mlx.h"

int main()
{
    void *ptr = mlx_init();
    void  *win_ptr = mlx_new_window(ptr, 500, 500, "burak");
    mlx_loop(ptr);
}