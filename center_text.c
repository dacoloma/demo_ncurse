#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DELAY 10000

int main(int argc, char *argv[])
{
	WINDOW	*border_box;
	char	*msg="Centrer ce texte";
	int		size = strlen(msg);

	initscr();
	curs_set(FALSE);
	while (1)
	{
		clear();
		mvprintw(LINES / 2, COLS / 2 - size / 2, msg);
		refresh();
		if (getch() != 410)
			break;
	}
	endwin(); // Restore normal terminal behavior
	free(border_box);
	return (0);
}
