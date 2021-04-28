#include "assets/scripts/menu_header.h"
#include "assets/scripts/menu_functions.c"


// Previously modified by :
//
// Last modified by : ilyes
//
// 177013 is funny. Funny numbers go brrrrrrrrrrrrrrrrr


// Note that all of this shit will be a function called something like "call menu" or idk a thing like that
// Also note that I like lasagnas because lasagna is really good ngl
// Yes.

// Stuff that require fixing :
// 1. Fix position of the volume button when clicking on it
// 2. Add a proper background to the option menu
// 4. Fix the horrible fullscreen spam
// 5. You can click on the buttons even tho the option menu isn't pulled off. Fix that (lil glitched linked to the fullscreen spam)


int main (int argc, char *argv[]) {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                   Surface Variables Initialisation                                           //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SDL_Surface *screen = NULL, *Car = NULL, *text2 = NULL, *text3 = NULL;
    SDL_Rect position, positionCar, positionText2, positionText3;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                         Font/Text Initialisation                                             //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    TTF_Init();
    SDL_Color colourBlack  = {255, 255, 255}; SDL_Color colourWhite  = {0, 0, 0};
    TTF_Font *police;
    police = TTF_OpenFont ("assets/Roman.ttf", 20);
    text2 = TTF_RenderText_Blended (police, "FullScreen", colourBlack);
    text3 = TTF_RenderText_Blended (police, "Sound", colourBlack);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                        Sound Variables Initialisation                                        //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic (MIX_MAX_VOLUME / 5);
    Mix_Music *music;
    Mix_Chunk *son_menutick, *son_menuopen, *son_menuclose;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                   Loading of the Sounds (in the memory)                                      //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    music = Mix_LoadMUS ("assets/sounds/mainmenu_soundtrack01.mp3");   // To load the music file
    Mix_PlayMusic (music, -1);                                         // To play the music n-1 times (-1 = infinite loop)
    son_menutick = Mix_LoadWAV ("assets/sounds/menu_tick.wav");
    son_menuopen = Mix_LoadWAV ("assets/sounds/menu_open.wav");
    son_menuclose = Mix_LoadWAV ("assets/sounds/menu_close.wav");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                       Settings for the Video                                                 //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SDL_Init (SDL_INIT_VIDEO);
    SDL_WM_SetCaption ("Armor of Thorns", NULL);
    SDL_WM_SetIcon (SDL_LoadBMP ("icon.bmp"), NULL);
    screen = SDL_SetVideoMode (1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect (screen, NULL, SDL_MapRGB (screen -> format, 0, 0, 0));

    Car = IMG_Load ("assets/menu/car.png");
    // Position of the screen / background
    position.x = 0;
    position.y = 0;
    // Position of the Car
    positionCar.x = -128;
    positionCar.y = 625;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                           Essential Variables                                                //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Some essentials variables for loop and stuff
    SDL_Event event;   // To read events
    int running = 1;   // For the Infinite loop
    int loop = 1;      // To create a loop with the up/down keys
    int pressed = 0;   // So the MOUSEMOTION doesn't spam everything
    int i = 0;         // Just some counters and an event,
    int buffer = 0;    // So that is it possible to load both the gif and read an event. To do so, call the function inside a loop with "buffer++" before the call

    // Just a template to generate random numbers
    // srand (time (0));
    // int random = Random (2, 0);

    // Draw the main menu
    DrawMenu (screen, position, 0);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                               Main Function                                                  //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (running) {
        while (SDL_PollEvent (&event)) {
            switch (event.type) {

                case SDL_KEYDOWN:
                    if ((event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE)) {
                        switch (loop) {
                            case 1:
                                // Execute the stuff for Play (exit the menu, starts the game)
                                //printf ("Yup, enter/space 1 works\n");
                            break;

                            case 2:
                                // Execute the stuff for Option (shows the option menu)
                                //printf ("Yup, enter/space 2 works\n");

                            break;

                            case 3:
                                //printf ("Yup, enter/space 3 works\n");
                                // Start a prompt asking if the user is sure to exit the game
                                // AskConfirmation (&running);
                                running = 0;
                            break;
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_UP) {
                        if (loop == 1) {
                            // Play -> Quit
                            //printf ("1. We do be '%d' loopin\n", loop);
                            loop = 3;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            DrawMenu (screen, position, 3);
                        }
                        else if (loop == 2) {
                            // Option -> Play
                            //printf ("2. We do be '%d' loopin\n", loop);
                            loop--;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            DrawMenu (screen, position, 1);
                        }
                        else {
                            // Quit -> Option
                            //printf ("3. We do be '%d' loopin\n", loop);
                            loop--;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            DrawMenu (screen, position, 2);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN) {
                        if (loop == 1) {
                            // Play -> Option
                            //printf ("4. We do be '%d' loopin\n", loop);
                            loop++;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            DrawMenu (screen, position, 2);
                        }
                        else if (loop == 2) {
                            // Option -> Quit
                            //printf ("5. We do be '%d' loopin\n", loop);
                            loop++;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            DrawMenu (screen, position, 3);
                        }
                        else {
                            // Quit -> Play
                            //printf ("6. We do be '%d' loopin\n", loop);
                            loop = 1;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            DrawMenu (screen, position, 1);
                        }
                    }
                    else {
                        DrawMenu (screen, position, 0);
                    }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    printf ("Mouse button %d pressed at (%d,%d)\n", event.button.button, event.button.x, event.button.y); // Helps for pinpointing locations
                    if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > 50 && event.button.x < 260) && (event.button.y < 465 && event.button.y > 400)) {
                        // Launch the game
                        loop = 1;
                        Mix_PlayChannel (-1, son_menutick, 0);
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > 50 && event.button.x < 260) && (event.button.y < 565 && event.button.y > 500)) {
                        // Open the option menu
                        loop = 2;
                        Mix_PlayChannel (-1, son_menuopen, 0);
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > 50 && event.button.x < 260) && (event.button.y < 665 && event.button.y > 600)) {
                        // Start a propmt asking if the user is sure to exit the game
                        // AskConfirmation (&running);
                        loop = 3;
                        Mix_PlayChannel (-1, son_menutick, 0);
                        running = 0;
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && !pressed) {
                        DrawMenu (screen, position, 0);
                    }
                break;

                case SDL_MOUSEMOTION:
                    // Funny colours when hovering the mouse
                    if ( ! (((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 465 && event.motion.y > 400)) || ((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 565 && event.motion.y > 500)) || ((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 665 && event.motion.y > 600))) && pressed) {
                        pressed = 0;
                        DrawMenu (screen, position, 0);
                    }
                    else if (((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 465 && event.motion.y > 400)) && (pressed != 1)) {
                        pressed = 1; loop = 1;
                        // printf ("just pressed 1 smh : %d\n", pressed);
                        Mix_PlayChannel (-1, son_menutick, 0);
                        DrawMenu (screen, position, 1);
                    }
                    else if (((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 565 && event.motion.y > 500)) && (pressed != 2)) {
                        pressed = 2; loop = 2;
                        // printf ("just pressed 2 smh : %d\n", pressed);
                        Mix_PlayChannel (-1, son_menutick, 0);
                        DrawMenu (screen, position, 2);
                    }
                    else if (((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 665 && event.motion.y > 600)) && (pressed != 3)) {
                        pressed = 3; loop = 3;
                        // printf ("just pressed 3 smh : %d\n", pressed);
                        Mix_PlayChannel (-1, son_menutick, 0);
                        DrawMenu (screen, position, 3);
                    }
                break;

                case SDL_QUIT:
                    exit (0);
            }
        }
        /*
        // To have a moving car in the background
        // Can't use in conjunction with other stuff so better leave it unactive
        if (positionCar.x < 1208) {
            //printf ("Car is moving : '%d', pog.\n", positionCar.x);
            positionCar.x += 10;
            DrawMainMenu (screen, background, play, option, quit, text1, position, positionPlay, positionOption, positionQuit, positionText1);
            SDL_BlitSurface(Car, NULL, screen, &positionCar);
            SDL_Flip (screen);
        }
        else {
            positionCar.x = -128;
        }
        */
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                             Memory Release and End                                           //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    TTF_CloseFont (police);
    TTF_Quit ();
    SDL_FreeSurface (text2); SDL_FreeSurface (text3);
    SDL_Quit ();

    return EXIT_SUCCESS;
}
