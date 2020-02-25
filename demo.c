#include "demo.h"

// static void	init_colors()
// {
// 	start_color();
// 	init_pair(COLOR_P1, COLOR_RED, COLOR_BLACK);
// 	init_pair(COLOR_P2, COLOR_CYAN, COLOR_BLACK);
// 	init_pair(COLOR_P3, COLOR_GREEN, COLOR_BLACK);
// 	init_pair(COLOR_P4, COLOR_YELLOW, COLOR_BLACK);
// }

static t_visu	*init_visu(void)
{
	t_visu	*visu;
	t_win	*arena;
	t_win	*info;

	visu = (t_visu *)malloc(sizeof(t_visu));
	if (visu == NULL)
		return (NULL);
	arena = (t_win *)malloc(sizeof(t_win));
	if (arena == NULL)
		return (NULL);
	info = (t_win *)malloc(sizeof(t_win));
	if (info == NULL)
		return (NULL);
	arena->dim.lines = ft_sqrt(MEM_SIZE) + 2;
	arena->dim.cols = ft_sqrt(MEM_SIZE) * 3 + 1;
	arena->coord.x = 3;
	arena->coord.y = 3;

	info->dim.lines = arena->dim.lines;
	info->dim.cols = 60;
	info->coord.x = 3;
	info->coord.y = 3;

	visu->arena = arena;

	visu->info = info;
	return (visu);
}

static void		create_windows(t_visu *visu)
{
	t_win	*arena;
	t_win	*info;

	arena = visu->arena;
	info = visu->info;
	arena->window = newwin(arena->dim.lines, arena->dim.cols, arena->coord.y, arena->coord.x);
	info->window = newwin(info->dim.lines, info->dim.cols, info->coord.y, info->coord.x);
}

int			 	main(void)
{
	t_visu	*visu;


	// char	*p1="Player 1";
	// char	*p2="Player 2";
	// char	*p3="Player 3";
	// char	*p4="Player 4";

	initscr();
	visu = init_visu();
	curs_set(FALSE);
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	create_windows(visu);

	box(visu->arena->window, ACS_VLINE, ACS_HLINE);
	box(visu->info->window, ACS_VLINE, ACS_HLINE);

	mvwprintw(visu->arena->window, 1, 1, "LEFT SCREEN");
	mvwprintw(visu->info->window, 1, 1, "RIGHT SCREEN");
	// init_colors();


	// attron(COLOR_PAIR(1));
	// attron(COLOR_PAIR(2));
	// print_in_middle(stdscr, LINES / 2, 0, 0, "Voila !!! In color ...");
	// attroff(COLOR_PAIR(2));

	getch();
	free(visu->arena->window);
	free(visu->info->window);
	free(visu->arena);
	free(visu->info);
	free(visu);
	endwin(); // Restore normal terminal behavior
	return (0);
}
