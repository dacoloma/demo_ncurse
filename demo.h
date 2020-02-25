#ifndef DEMO_H
# define DEMO_H
# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define COLOR_P1	1
# define COLOR_P2	2
# define COLOR_P3	3
# define COLOR_P4	4

# define MEM_SIZE	(4 * 1024)

int	ft_sqrt(int nb);
int	ft_power(int nb, int power);

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;
typedef struct	s_dim
{
	int	lines;
	int	cols;
}				t_dim;
typedef struct	s_win
{
	t_coord	coord;
	t_dim	dim;
	WINDOW	*window;
}				t_win;

typedef struct	s_visu
{
	t_win	*arena;
	t_win	*info;
}				t_visu;

#endif
