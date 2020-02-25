#include <ncurses.h>
#include <unistd.h>

#define DELAY 10000

int main(int argc, char *argv[])
{
	initscr();
	/*
	mvprintw(LINES - 1, COLS - 1, ".");
	*/

	attron(A_NORMAL);
    printw("Texte sans mise en forme\n");

    attron(A_STANDOUT);
    printw("Texte en meilleur surlignement\n");
    attroff(A_STANDOUT);

    attron(A_REVERSE);
    printw("Texte en inversion video\n");
    attroff(A_REVERSE);

    attron(A_DIM);
    printw("Texte a moitie brillant\n");
    attroff(A_DIM);

    attron(A_BOLD);
    printw("Texte en gras\n");
    attroff(A_BOLD);

    attron(A_UNDERLINE);
    printw("Texte en souligne\n");
    attroff(A_UNDERLINE);

    attron(A_INVIS);
    printw("Texte invisible\n");
    attroff(A_INVIS);

    attron(A_UNDERLINE | A_BOLD); // Pour appliquer plusieurs type de mises en forme, on utilise l'opérateur unaire |
    printw("Texte en gras souligne\n");

    attron(A_NORMAL);

    refresh();

	getch();
	endwin(); // Restore normal terminal behavior
	return (0);
}
