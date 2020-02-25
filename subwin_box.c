#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 10000

int main(int argc, char *argv[])
{
	WINDOW	*border_box;
	WINDOW	*left;
	WINDOW	*right;

	initscr();
	curs_set(FALSE);
	border_box = subwin(stdscr, 10, 10, LINES / 2, COLS / 2);
	wborder(border_box, '|', '|', '-', '-', '+', '+', '+', '+');
	//box(border_box, ACS_VLINE, ACS_HLINE);
 
/*	left = subwin(stdscr, LINES, COLS / 2, 0, 0);
	right = subwin(stdscr, LINES, COLS / 2, 0, COLS / 2);
	
	box(left, ACS_VLINE, ACS_HLINE);
	box(right, ACS_VLINE, ACS_HLINE);

	mvwprintw(left, 1, 1, "LEFT SCREEN");
	mvwprintw(right, 1, 1, "RIGHT SCREEN");

    wrefresh(left);
    wrefresh(right);
	
	free(left);
	free(right);
	
	getch();
	endwin(); // Restore normal terminal behavior
*/
	refresh();
	getch();
	endwin(); // Restore normal terminal behavior

	return (0);
}
