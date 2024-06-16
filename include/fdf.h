#ifndef FNF_H
# define FNF_H

/*
*	vars
*/
# define WIDTH 640
# define HEIGHT 360
# define SQUARE_SIZE 100

/*
*	libs
*/
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

# include "mlx.h"

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
}	t_data;

#endif