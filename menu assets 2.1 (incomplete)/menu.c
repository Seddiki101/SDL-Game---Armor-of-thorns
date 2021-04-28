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

    SDL_Surface *screen = NULL, *background = NULL, *play = NULL, *option = NULL, *quit = NULL, *overlay = NULL, *Car = NULL,
                *text1 = NULL, *text2 = NULL, *text3 = NULL;

    SDL_Rect position, positionPlay, positionOption, positionQuit, positionOverlay, positionCar,
             positionText1, positionText2, positionText3;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                         Font/Text Initialisation                                             //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    TTF_Init();
    SDL_Color colourBlack  = {255, 255, 255}; SDL_Color colourWhite  = {0, 0, 0};
    TTF_Font *police;
    police = TTF_OpenFont ("assets/Roman.ttf", 20);

    text1 = TTF_RenderText_Blended (police, "Armor of Thorns", colourWhite);
    text2 = TTF_RenderText_Blended (police, "FullScreen", colourBlack);
    text3 = TTF_RenderText_Blended (police, "Sound", colourBlack);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                           Sound Settings                                                     //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic (MIX_MAX_VOLUME / 5);
    Mix_Music *music;
    Mix_Chunk *son_menutick, *son_menuopen, *son_menuclose;

    music = Mix_LoadMUS ("assets/sounds/mainmenu_soundtrack01.mp3");   // Loads the music from file
    Mix_PlayMusic (music, -1);                                         // Plays the music n-1 times (-1 = infinite loop)
    son_menutick = Mix_LoadWAV ("assets/sounds/menu_tick.wav");
    son_menuopen = Mix_LoadWAV ("assets/sounds/menu_open.wav");
    son_menuclose = Mix_LoadWAV ("assets/sounds/menu_close.wav");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                          Video Settings                                                      //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SDL_Init (SDL_INIT_VIDEO);
    SDL_WM_SetCaption ("Armor of Thorns", NULL);
    SDL_WM_SetIcon (SDL_LoadBMP ("icon.bmp"), NULL);
    screen = SDL_SetVideoMode (1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect (screen, NULL, SDL_MapRGB (screen -> format, 0, 0, 0));

    // Loads the images from file
    background = IMG_Load ("assets/menu/background01.png");
    play = IMG_Load ("assets/menu/play_unselected.png");
    option = IMG_Load ("assets/menu/options_unselected.png");
    quit = IMG_Load ("assets/menu/quit_unselected.png");
    overlay = IMG_Load ("assets/menu/overlay.png");
    Car = IMG_Load ("assets/menu/car.png");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                                Positions                                                     //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Position of the background
    position.x = 0;
    position.y = 0;
    // Positions of Play button (main menu)
    positionPlay.x = 50;
    positionPlay.y = 400;
    // Positions of Options button (main menu)
    positionOption.x = 50;
    positionOption.y = 500;
    // Positions of Quit button (main menu)
    positionQuit.x = 50;
    positionQuit.y = 600;
    // Positions of the text 1
    positionText1.x = 1080;
    positionText1.y = 690;
    // Positions of the text 2
    positionText2.x = 60;
    positionText2.y = 90;
    // Positions of the text 3
    positionText3.x = 60;
    positionText3.y = 220;
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

    // Draw the main menu
    SDL_BlitSurface (background, NULL, screen, &position);
    SDL_BlitSurface (play, NULL, screen, &positionPlay);
    SDL_BlitSurface (option, NULL, screen, &positionOption);
    SDL_BlitSurface (quit, NULL, screen, &positionQuit);
    SDL_BlitSurface (text1, NULL, screen, &positionText1);
    SDL_Flip (screen);


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
                            SDL_BlitSurface (background, NULL, screen, &position);
                            SDL_BlitSurface (play, NULL, screen, &positionPlay);
                            SDL_BlitSurface (option, NULL, screen, &positionOption);
                            SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                            SDL_BlitSurface (text1, NULL, screen, &positionText1);
                            DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 3);
                        }
                        else if (loop == 2) {
                            // Option -> Play
                            //printf ("2. We do be '%d' loopin\n", loop);
                            loop--;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            SDL_BlitSurface (play, NULL, screen, &positionPlay);
                            SDL_BlitSurface (option, NULL, screen, &positionOption);
                            SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                            SDL_BlitSurface (text1, NULL, screen, &positionText1);
                            DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 1);
                        }
                        else {
                            // Quit -> Option
                            //printf ("3. We do be '%d' loopin\n", loop);
                            loop--;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            SDL_BlitSurface (play, NULL, screen, &positionPlay);
                            SDL_BlitSurface (option, NULL, screen, &positionOption);
                            SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                            SDL_BlitSurface (text1, NULL, screen, &positionText1);
                            DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 2);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN) {
                        if (loop == 1) {
                            // Play -> Option
                            //printf ("4. We do be '%d' loopin\n", loop);
                            loop++;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            SDL_BlitSurface (play, NULL, screen, &positionPlay);
                            SDL_BlitSurface (option, NULL, screen, &positionOption);
                            SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                            SDL_BlitSurface (text1, NULL, screen, &positionText1);
                            DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 2);
                        }
                        else if (loop == 2) {
                            // Option -> Quit
                            //printf ("5. We do be '%d' loopin\n", loop);
                            loop++;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            SDL_BlitSurface (play, NULL, screen, &positionPlay);
                            SDL_BlitSurface (option, NULL, screen, &positionOption);
                            SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                            SDL_BlitSurface (text1, NULL, screen, &positionText1);
                            DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 3);
                        }
                        else {
                            // Quit -> Play
                            //printf ("6. We do be '%d' loopin\n", loop);
                            loop = 1;
                            Mix_PlayChannel (-1, son_menutick, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            SDL_BlitSurface (play, NULL, screen, &positionPlay);
                            SDL_BlitSurface (option, NULL, screen, &positionOption);
                            SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                            SDL_BlitSurface (text1, NULL, screen, &positionText1);
                            DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 1);
                        }
                    }
                    else {
                        SDL_BlitSurface (background, NULL, screen, &position);
                        SDL_BlitSurface (play, NULL, screen, &positionPlay);
                        SDL_BlitSurface (option, NULL, screen, &positionOption);
                        SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                        SDL_BlitSurface (text1, NULL, screen, &positionText1);
                        SDL_Flip (screen);
                    }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    //printf ("Mouse button %d pressed at (%d,%d)\n", event.button.button, event.button.x, event.button.y); // Helps for pinpointing locations
                    if ((event.button.button == SDL_BUTTON_LEFT) && !pressed) {
                        SDL_BlitSurface (background, NULL, screen, &position);
                        SDL_BlitSurface (play, NULL, screen, &positionPlay);
                        SDL_BlitSurface (option, NULL, screen, &positionOption);
                        SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                        SDL_BlitSurface (text1, NULL, screen, &positionText1);
                        SDL_Flip (screen);
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > positionPlay.x && event.button.x < (positionPlay.x+210)) && (event.button.y > positionPlay.y && event.button.y < (positionPlay.y+65))) {
                        // Launch the game
                        Mix_PlayChannel (-1, son_menutick, 0);
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > positionOption.x && event.button.x < (positionOption.x+210)) && (event.button.y > positionOption.y && event.button.y < (positionOption.y+65))) {
                        // Open the option menu
                        Mix_PlayChannel (-1, son_menuopen, 0);
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > positionQuit.x && event.button.x < (positionQuit.x+210)) && (event.button.y > positionQuit.y && event.button.y < (positionQuit.y+65))) {
                        // Start a propmt asking if the user is sure to exit the game
                        // AskConfirmation (&running);
                        Mix_PlayChannel (-1, son_menutick, 0);
                        running = 0;
                    }
                break;

                case SDL_MOUSEMOTION:
                    // Funny colours when hovering the mouse
                    if ( !( ((event.motion.x > positionPlay.x && event.motion.x < (positionPlay.x+210)) && (event.motion.y > positionPlay.y && event.motion.y < (positionPlay.y+65)))
                            || ((event.motion.x > positionOption.x && event.motion.x < (positionOption.x+210)) && (event.motion.y > positionOption.y && event.motion.y < (positionOption.y+65)))
                            || ((event.motion.x > positionQuit.x && event.motion.x < (positionQuit.x+210)) && (event.motion.y > positionQuit.y && event.motion.y < (positionQuit.y+65))) ) && pressed) {
                        pressed = 0;
                        SDL_BlitSurface (background, NULL, screen, &position);
                        SDL_BlitSurface (play, NULL, screen, &positionPlay);
                        SDL_BlitSurface (option, NULL, screen, &positionOption);
                        SDL_BlitSurface (quit, NULL, screen, &positionQuit);
                        SDL_BlitSurface (text1, NULL, screen, &positionText1);
                        SDL_Flip (screen);
                        // printf ("not on the buttons 1 smh : %d\n", pressed);
                    }
                    else if (((event.motion.x > positionPlay.x && event.motion.x < (positionPlay.x+210)) && (event.motion.y > positionPlay.y && event.motion.y < (positionPlay.y+65))) && (pressed != 1)) {
                        pressed = 1; loop = 1;
                        // printf ("just pressed 1 a button smh : %d\n", pressed);
                        Mix_PlayChannel (-1, son_menutick, 0);
                        DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 1);
                    }
                    else if (((event.motion.x > positionOption.x && event.motion.x < (positionOption.x+210)) && (event.motion.y > positionOption.y && event.motion.y < (positionOption.y+65))) && (pressed != 2)) {
                        pressed = 2; loop = 2;
                        // printf ("just pressed 2 a button smh : %d\n", pressed);
                        Mix_PlayChannel (-1, son_menutick, 0);
                        DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 2);
                    }
                    else if (((event.motion.x > positionQuit.x && event.motion.x < (positionQuit.x+210)) && (event.motion.y > positionQuit.y && event.motion.y < (positionQuit.y+65))) && (pressed != 3)) {
                        pressed = 3; loop = 3;
                        // printf ("just pressed 3 a button smh : %d\n", pressed);
                        Mix_PlayChannel (-1, son_menutick, 0);
                        DrawOverlay (screen, overlay, positionOption, positionPlay, positionOption, positionQuit, 3);
                    }
                break;

                case SDL_QUIT:
                    exit (0);
            }
        }
        /*
        // To have a moving car in the background
        // Can't use in conjunction with other stuff so better leave it inactive
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
    SDL_FreeSurface (background);
    SDL_FreeSurface (play); SDL_FreeSurface (option); SDL_FreeSurface (quit);
    SDL_FreeSurface (text1); SDL_FreeSurface (text2); SDL_FreeSurface (text3);
    SDL_Quit ();

    return EXIT_SUCCESS;
}
