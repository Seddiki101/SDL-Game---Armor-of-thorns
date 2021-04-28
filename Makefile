program:menu_keymapping.o
	gcc menu_keymapping.o -o program -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
menu_keymapping.o:menu_keymapping.c
	gcc -c menu_keymapping.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf

