LDFLAGS=-lncurses

LDFLAG = -lncurses

.PHONY = all clean re

all: demo

demo: demo.c
	$(CC) -o demo demo.c $(LDFLAGS)

clean:
	$(RM) demo

re: clean all
