#include "demo.h"

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
	arena->dim.lines = 0;//LINES;//ft_sqrt(MEM_SIZE) + 2;
	arena->dim.cols = 0;//COLS * 2 / 3;//ft_sqrt(MEM_SIZE) * 3 + 1;
	arena->coord.x = 0;
	arena->coord.y = 0;

	info->dim.lines = arena->dim.lines;
	info->dim.cols = COLS / 3;
	info->coord.x = arena->dim.cols;
	info->coord.y = 0;

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
	refresh();
}

static void	init_colors()
{
	start_color();
	init_pair(COLOR_P1, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_P2, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_P3, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_P4, COLOR_YELLOW, COLOR_BLACK);
}

static void		init_player(t_visu *visu, char *p1, char *p2, char *p3, char *p4)
{
	// attron(COLOR_PAIR(COLOR_P1));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P1));
	mvwprintw(visu->arena->window, 2, 1, p1);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P1));attroff(COLOR_PAIR(COLOR_P1));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P2));
	mvwprintw(visu->arena->window, 4, 1, p2);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P2));attroff(COLOR_PAIR(COLOR_P2));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P3));
	mvwprintw(visu->arena->window, 6, 1, p3);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P3));attroff(COLOR_PAIR(COLOR_P3));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P4));
	mvwprintw(visu->arena->window, 8, 1, p4);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P4));attroff(COLOR_PAIR(COLOR_P4));
	wrefresh(visu->arena->window);
}

int			 	main(void)
{
	t_visu	*visu;


	char	*p1="Player 1";
	char	*p2="Player 2";
	char	*p3="Player 3";
	char	*p4="Player 4";

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

	mvwprintw(visu->arena->window, 0, 1, "Arena");
	wrefresh(visu->arena->window);
	// refresh();
	
	mvwprintw(visu->info->window, 0, 1, "Info");
	wrefresh(visu->info->window);
	init_colors();
	init_player(visu, p1, p2, p3, p4);

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
