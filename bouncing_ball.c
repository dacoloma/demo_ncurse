#include <ncurses.h>
#include <unistd.h>

#define DELAY 10000

int main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	next_x;
	int	direction;

	x = 0;
	y = 0;
	max_x = 0;
	max_y = 0;
	next_x = 0;
	direction = 1;

	initscr();
	noecho();
	curs_set(FALSE);
	

	while (1)
	{
		getmaxyx(stdscr, max_y, max_x);
		clear();
		mvprintw(y, x, "o");
		refresh();

		usleep(DELAY);

		next_x = x + direction;
		if (next_x >= max_x || next_x < 0)
		{
			direction *= -1;
		}
		else
		{
			x += direction;
		}
	}

	endwin(); // Restore normal terminal behavior
}
