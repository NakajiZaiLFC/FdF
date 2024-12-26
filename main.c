#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>

#define ESC 65307
#define ON_DESTROY 17
#define SCALE 20
#define ISO_ANGLE_X 0.523599  // 30度
#define ISO_ANGLE_Y 0.523599  // 30度

typedef struct s_data {
    void *mlx;
    void *win;
} t_data;

typedef struct s_point {
    int x;
    int y;
} t_point;

// 3D座標を2Dアイソメトリック座標に変換
t_point iso_projection(int x, int y, int z)
{
    t_point p;
    p.x = 500 + (x - y) * cos(ISO_ANGLE_X) * SCALE;
    p.y = 300 + ((x + y) * sin(ISO_ANGLE_Y) - z) * SCALE;
    return p;
}

// Bresenhamのアルゴリズムで線を描画
void bresenham_line(t_data *data, t_point start, t_point end, int color)
{
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = (start.x < end.x) ? 1 : -1;
    int sy = (start.y < end.y) ? 1 : -1;
    int err = dx - dy;
    int x = start.x;
    int y = start.y;

    while (1)
    {
        mlx_pixel_put(data->mlx, data->win, x, y, color);
        if (x == end.x && y == end.y)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

void draw_3d_grid(t_data *data, int map[11][19])
{
    t_point start, end;
    int x, y;

    // 横線を描画
    for (y = 0; y < 11; y++)
    {
        for (x = 0; x < 18; x++)
        {
            start = iso_projection(x, y, map[y][x]);
            end = iso_projection(x + 1, y, map[y][x + 1]);
            bresenham_line(data, start, end, 0x00FFFFFF);
        }
    }

    // 縦線を描画
    for (x = 0; x < 19; x++)
    {
        for (y = 0; y < 10; y++)
        {
            start = iso_projection(x, y, map[y][x]);
            end = iso_projection(x, y + 1, map[y + 1][x]);
            bresenham_line(data, start, end, 0x00FFFFFF);
        }
    }
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(0);
    }
    return (0);
}

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}

int main(void)
{
    t_data data;
    int map[11][19] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,10,10,0,0,10,10,0,0,0,10,10,10,10,10,0,0,0},
        {0,0,10,10,0,0,10,10,0,0,0,0,0,0,0,10,10,0,0},
        {0,0,10,10,0,0,10,10,0,0,0,0,0,0,0,10,10,0,0},
        {0,0,10,10,10,10,10,10,0,0,0,0,10,10,10,10,0,0,0},
        {0,0,0,10,10,10,10,10,0,0,0,10,10,0,0,0,0,0,0},
        {0,0,0,0,0,0,10,10,0,0,0,10,10,0,0,0,0,0,0},
        {0,0,0,0,0,0,10,10,0,0,0,10,10,10,10,10,10,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    
    data.win = mlx_new_window(data.mlx, 1000, 1000, "3D Isometric Grid");
    if (!data.win)
        return (1);

    draw_3d_grid(&data, map);

    mlx_key_hook(data.win, key_hook, &data);
    mlx_hook(data.win, ON_DESTROY, 0, close_window, &data);
    mlx_loop(data.mlx);
    return (0);
}