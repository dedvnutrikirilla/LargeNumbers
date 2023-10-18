all : 
	gcc -std=c11 -Wall -Werror -Wextra -Wpedantic -ggdb3 -I ./libmylong/inc -s test.c ./libmylong/src/*.c -o main 
