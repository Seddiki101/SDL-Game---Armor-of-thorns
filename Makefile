ex7:main.o riddle.o 
	gcc main.o riddle.o -o ex7 -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
main.o:main.c
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
riddle.o:riddle.c
	gcc -c riddle.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 



