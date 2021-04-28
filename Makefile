enigma:assets/scripts/enigma.o assets/scripts/enigma_functions.o assets/scripts/enigma_fill.o 
	gcc enigma.o -o program -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
assets/scripts/enigma.o:enigma.c
	gcc -c enigma.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
assets/scripts/enigma_functions.o:assets/scripts/enigma_functions.c
	gcc -c assets/scripts/enigma_functions.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
assets/scripts/enigma_fill.o:assets/scripts/enigma_fill.c
	gcc -c assets/scripts/enigma_fill.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf