prog: main2.o function.o 
	gcc main2.o function.o -o prog -lSDL -lSDL_mixer -lSDL_ttf -lSDL_image -g
function.o:function.c
	gcc -c function.c -g
main2.o:main2.c
	gcc -c main2.c -g

