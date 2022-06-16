CC=gcc
NAME=game
SRC=$(wildcard src/*.c)
INCLUDES=-Iinclude
OBJS=$(patsubst src/%.c, out/%.o, $(SRC))
INCLUDE=$(wildcard include/*)



$(NAME): $(OBJS) $(INCLUDE) main.c
	$(CC) $(INCLUDES) main.c $(OBJS) -o $(NAME) -g -Wall -Werror -std=c99

prepare:
	mkdir -p src out include tests


out/%.o: src/%.c
	$(CC) -o $@ -c $^ $(INCLUDES) -g -Wall -Werror -std=c99

clean:
	rm $(NAME) $(OBJS)



