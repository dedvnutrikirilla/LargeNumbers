NAME = libmylong
FLAGS = -std=c11 -Wall -Werror -Wextra -Wpedantic

all: install
install: LIBMYLONG

LIBMYLONG: objs
	ar rcs $(NAME).a obj/*.o
	ranlib $(NAME).a
	make clean
objs:
	gcc $(FLAGS) -c src/*.c -I inc/
	mkdir -p obj
	mv *.o obj/
clean:
	rm -rfd obj
uninstall:
	rm -rf $(NAME).a
	make clean
reinstall:
	make uninstall
	make

