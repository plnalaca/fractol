#include "deneme.h"

#define WIDTH  1024
#define HEIGHT 1024

void draw_horizontal_line(t_list *win, int y, int color)
{
    int x;
    char *pixel;
    
    // Yatay çizgi için her x koordinatına piksel koy
    for (x = 0; x < WIDTH; x++)
    {
        // Pikselin bellekteki konumunu hesapla
        pixel = win->img_addr + (y * win->size_line + x * (win->bpp / 8));

        // Renk bilgilerini belleğe yaz
        *(unsigned int *)pixel = color;
    }
}

int main()
{
    t_list win;

    // MiniLibX başlatma
    win.mlx = mlx_init();
    win.window = mlx_new_window(win.mlx, WIDTH, HEIGHT, "new window");

    // Yeni bir görüntü oluştur
    win.img = mlx_new_image(win.mlx, WIDTH, HEIGHT);

    // Görüntü belleğini al
    win.img_addr = mlx_get_data_addr(win.img, &win.bpp, &win.size_line, &win.endian);

    // Çizgiyi oluştur (ekranın ortasında yatay bir çizgi)
    draw_horizontal_line(&win, HEIGHT / 2, 0xFFFFFF);

    // Görüntüyü pencereye çiz
    mlx_put_image_to_window(win.mlx, win.window, win.img, 100, 0);

    mlx_loop(win.mlx);
}
