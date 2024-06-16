#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (0);
	}
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
	return (0);
}

int	main()
{
	t_data	data;
	int		posX = 150;
	int		posY = 100;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "coom");

	while (posY < 100 + SQUARE_SIZE)
	{
		posX = 100;
		while (posX < 100 + SQUARE_SIZE)
			mlx_pixel_put(data.mlx, data.mlx_win, posX++, posY, 0x8d35c4);
		posY++;
	}

	/*
	*	hook event listener
	*/
	mlx_hook(data.mlx_win, 2, 1L<<0, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0L, close_win, &data);
	mlx_loop(data.mlx);
	return (0);
}
