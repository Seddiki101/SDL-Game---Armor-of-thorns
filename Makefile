pro:main.o savexload.o 
	gcc main.o savexload.o -o pro -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
	
main.o:main.c
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
	
savexload.o:savexload.c
	gcc -c savexload.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 


