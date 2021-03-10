ex4:pp.o fct.o 
	gcc pp.o fct.o -o ex4 -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
pp.o:pp.c
	gcc -c pp.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
fct.o:fct.c
	gcc -c fct.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 



