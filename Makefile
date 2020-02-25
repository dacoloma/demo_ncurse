CFLAGS = -Wall -Wextra -Werror

LDFLAGS=-lncurses

LDFLAG = -lncurses

.PHONY = all clean re

SRC =	demo.c \
		ft_power.c \
		ft_sqrt.c

OBJ = $(SRC:%.c=%.o)

all: demo

demo: $(SRC) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o demo $(SRC) $(LDFLAGS)

%.o: %.c 
	$(CC) -o $@ -c $< 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) demo

re: clean all
