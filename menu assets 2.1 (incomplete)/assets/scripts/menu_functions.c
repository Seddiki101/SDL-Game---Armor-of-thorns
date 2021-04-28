#include "menu_header.h"


// Previously modified by :
//
// Last modified by : ilyes
//
// 215600 is funny. Funny numbers go brrrrrrrrrrrrrrrrr



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void DrawOverlay (SDL_Surface *screen, SDL_Surface *overlay, SDL_Rect positionOverlay, SDL_Rect Holder1, SDL_Rect Holder2, SDL_Rect Holder3, int arg) {
    // Draws the overlay...
    if (arg == 1) {
        positionOverlay.x = Holder1.x;
        positionOverlay.y = Holder1.y;
    }
    else if (arg == 2) {
        positionOverlay.x = Holder2.x;
        positionOverlay.y = Holder2.y;
    }
    else {
        positionOverlay.x = Holder3.x;
        positionOverlay.y = Holder3.y;
    }
    SDL_BlitSurface (overlay, NULL, screen, &positionOverlay);
    SDL_Flip (screen);
}

int DrawMenu (SDL_Surface *screen, SDL_Rect position, int arg) {
    // Draw the main Menu
    // Is not very performance friendly
    // Still here because It would be a waste to throw away all of that stuff
    // Using it will be a rather **interesting** decision to say the least
    SDL_Surface *background = NULL, *text1 = NULL;
    SDL_Rect positionText1;

    SDL_Color colourWhite  = {0, 0, 0};
    TTF_Font *police; police = TTF_OpenFont ("assets/Roman.ttf", 20);
    text1 = TTF_RenderText_Blended (police, "Armor of Thorns", colourWhite);
    positionText1.x = 1080;
    positionText1.y = 690;

    background = IMG_Load ("assets/menu/background01.png");

    if (!arg) {
        SDL_Surface *play = NULL, *option = NULL, *quit = NULL;
        SDL_Rect positionPlay, positionOption, positionQuit;

        play = IMG_Load ("assets/menu/play_unselected.png");
        option = IMG_Load ("assets/menu/options_unselected.png");
        quit = IMG_Load ("assets/menu/quit_unselected.png");
        positionPlay.x = 50;
        positionPlay.y = 400;
        positionOption.x = 50;
        positionOption.y = 500;
        positionQuit.x = 50;
        positionQuit.y = 600;

        SDL_BlitSurface (play, NULL, screen, &positionPlay);
        SDL_BlitSurface (option, NULL, screen, &positionOption);
        SDL_BlitSurface (quit, NULL, screen, &positionQuit);

        SDL_Flip (screen);
        TTF_CloseFont (police);
        SDL_FreeSurface (background);
        SDL_FreeSurface (play);
        SDL_FreeSurface (option);
        SDL_FreeSurface (quit);
        SDL_FreeSurface (text1);
        return 0;
    }

    else if (arg == 1) {
        SDL_Surface *PLAY = NULL, *option = NULL, *quit = NULL;
        SDL_Rect positionPLAY, positionOption, positionQuit;

        PLAY = IMG_Load ("assets/menu/play_selected.png");
        option = IMG_Load ("assets/menu/options_unselected.png");
        quit = IMG_Load ("assets/menu/quit_unselected.png");
        positionPLAY.x = 50;
        positionPLAY.y = 400;
        positionOption.x = 50;
        positionOption.y = 500;
        positionQuit.x = 50;
        positionQuit.y = 600;

        SDL_BlitSurface (PLAY, NULL, screen, &positionPLAY);
        SDL_BlitSurface (option, NULL, screen, &positionOption);
        SDL_BlitSurface (quit, NULL, screen, &positionQuit);

        SDL_Flip (screen);
        TTF_CloseFont (police);
        SDL_FreeSurface (background);
        SDL_FreeSurface (PLAY);
        SDL_FreeSurface (option);
        SDL_FreeSurface (quit);
        SDL_FreeSurface (text1);
        return 1;
    }

    else if (arg == 2) {
        SDL_Surface *play = NULL, *OPTION = NULL, *quit = NULL;
        SDL_Rect positionPlay, positionOPTION, positionQuit;

        play = IMG_Load ("assets/menu/play_unselected.png");
        OPTION = IMG_Load ("assets/menu/options_selected.png");
        quit = IMG_Load ("assets/menu/quit_unselected.png");
        positionPlay.x = 50;
        positionPlay.y = 400;
        positionOPTION.x = 50;
        positionOPTION.y = 500;
        positionQuit.x = 50;
        positionQuit.y = 600;

        SDL_BlitSurface (play, NULL, screen, &positionPlay);
        SDL_BlitSurface (OPTION, NULL, screen, &positionOPTION);
        SDL_BlitSurface (quit, NULL, screen, &positionQuit);

        SDL_Flip (screen);
        TTF_CloseFont (police);
        SDL_FreeSurface (background);
        SDL_FreeSurface (play);
        SDL_FreeSurface (OPTION);
        SDL_FreeSurface (quit);
        SDL_FreeSurface (text1);
        return 2;
    }

    else {
        SDL_Surface *play = NULL, *option = NULL, *QUIT = NULL;
        SDL_Rect positionPlay, positionOption, positionQUIT;

        play = IMG_Load ("assets/menu/play_unselected.png");
        option = IMG_Load ("assets/menu/options_unselected.png");
        QUIT = IMG_Load ("assets/menu/quit_selected.png");
        positionPlay.x = 50;
        positionPlay.y = 400;
        positionOption.x = 50;
        positionOption.y = 500;
        positionQUIT.x = 50;
        positionQUIT.y = 600;

        SDL_BlitSurface (play, NULL, screen, &positionPlay);
        SDL_BlitSurface (option, NULL, screen, &positionOption);
        SDL_BlitSurface (QUIT, NULL, screen, &positionQUIT);

        SDL_Flip (screen);
        TTF_CloseFont (police);
        SDL_FreeSurface (background);
        SDL_FreeSurface (play);
        SDL_FreeSurface (option);
        SDL_FreeSurface (QUIT);
        SDL_FreeSurface (text1);
        return 3;
    }
    return -1;
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int AskConfirmationQuit (SDL_Surface *screen, Mix_Chunk *tick, int *running) {
    // Start a prompt upon doing certain actions like pressing the "Quit" button

    SDL_Surface *Prompt = NULL, *yes = NULL, *no = NULL, *YES = NULL, *NO = NULL;
    SDL_Rect positionPrompt, positionYes, positionNo;
    SDL_Event event;

    Prompt = IMG_Load ("assets/menu/prompt.png");   // no image yet
    yes = IMG_Load ("assets/menu/prompt_yes.png");  // no image yet
    no = IMG_Load ("assets/menu/prompt_no.png");    // no image yet
    YES = IMG_Load ("assets/menu/prompt_YES.png");  // no image yet
    NO = IMG_Load ("assets/menu/prompt_NO.png");    // no image yet

    positionPrompt.x = 420;
    positionPrompt.y = 280;
    positionYes.x = 420;
    positionYes.y = 280;
    positionNo.x = 420;
    positionNo.y = 280;

    SDL_BlitSurface (Prompt, NULL, screen, &positionPrompt);
    SDL_BlitSurface (yes, NULL, screen, &positionYes);
    SDL_BlitSurface (no, NULL, screen, &positionNo);
    SDL_Flip (screen);

    int waiting = 1;
    int loop = 0;
    int pressed = 0;

    while (waiting) {
        while (SDL_PollEvent (&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        if (loop) {
                            waiting = 0;
                            (*running) = 0;
                        }
                        else {
                            waiting = 0;
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_LEFT) {
                        if (loop) {
                            loop--;
                            Mix_PlayChannel (-1, tick, 0);
                            SDL_BlitSurface (Prompt, NULL, screen, &positionPrompt);
                            SDL_BlitSurface (yes, NULL, screen, &positionYes);
                            SDL_BlitSurface (NO, NULL, screen, &positionNo);
                            SDL_Flip (screen);
                        }
                        else {
                            loop++;
                            Mix_PlayChannel (-1, tick, 0);
                            SDL_BlitSurface (Prompt, NULL, screen, &positionPrompt);
                            SDL_BlitSurface (YES, NULL, screen, &positionYes);
                            SDL_BlitSurface (no, NULL, screen, &positionNo);
                            SDL_Flip (screen);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_RIGHT) {
                        if (loop) {
                            loop--;
                            Mix_PlayChannel (-1, tick, 0);
                            SDL_BlitSurface (Prompt, NULL, screen, &positionPrompt);
                            SDL_BlitSurface (yes, NULL, screen, &positionYes);
                            SDL_BlitSurface (NO, NULL, screen, &positionNo);
                            SDL_Flip (screen);
                        }
                        else {
                            loop++;
                            Mix_PlayChannel (-1, tick, 0);
                            SDL_BlitSurface (Prompt, NULL, screen, &positionPrompt);
                            SDL_BlitSurface (YES, NULL, screen, &positionYes);
                            SDL_BlitSurface (no, NULL, screen, &positionNo);
                            SDL_Flip (screen);
                        }
                    }
                break;

                case SDL_MOUSEBUTTONUP:
                    if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > 50 && event.button.x < 260) && (event.button.y < 665 && event.button.y > 600)) {
                        // Button Yes
                        (*running) = 0; waiting = 0;
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > 460 && event.button.x < 710) && (event.button.y < 665 && event.button.y > 600)) {
                        // Button No
                        waiting = 0;
                    }
                break;

                case SDL_MOUSEMOTION:
                    // Funny colours when hovering the mouse
                    if ( ! (((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 465 && event.motion.y > 400)) || ((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 565 && event.motion.y > 500))) && pressed) {
                        pressed = 0;
                        // printf ("not on the buttons 1 smh : %d\n", pressed);
                    }
                    else if (((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 465 && event.motion.y > 400)) && (pressed != 1)) {
                        pressed = 1; loop = 0;
                        // printf ("just pressed 1 a button smh : %d\n", pressed);
                        Mix_PlayChannel (-1, tick, 0);
                        SDL_BlitSurface (Prompt, NULL, screen, &positionPrompt);
                        SDL_BlitSurface (yes, NULL, screen, &positionYes);
                        SDL_BlitSurface (NO, NULL, screen, &positionNo);
                        SDL_Flip (screen);
                    }
                    else if (((event.motion.x < 260 && event.motion.x > 50) && (event.motion.y < 565 && event.motion.y > 500)) && (pressed != 2)) {
                        pressed = 2; loop = 1;
                        // printf ("just pressed 2 a button smh : %d\n", pressed);
                        Mix_PlayChannel (-1, tick, 0);
                        SDL_BlitSurface (Prompt, NULL, screen, &positionPrompt);
                        SDL_BlitSurface (YES, NULL, screen, &positionYes);
                        SDL_BlitSurface (no, NULL, screen, &positionNo);
                        SDL_Flip (screen);
                    }
                break;
            }
        }
    }
    SDL_FreeSurface (Prompt); SDL_FreeSurface (yes); SDL_FreeSurface (no); SDL_FreeSurface (YES); SDL_FreeSurface (NO);
    return 1;
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int OptionMenu (SDL_Surface *screen, Mix_Chunk *tick, int *fullscreen) {
    // Launch the Option menu inside the Menu

    SDL_Surface *OptionMenu = NULL, *Checkedmark = NULL, *Uncheckedmark = NULL, *VolumeBar = NULL, *Volume = NULL;
    SDL_Rect positionOptionMenu, positionCheckedmark, positionUncheckedmark, positionVolumeBar, positionVolume;
    SDL_Event event;

    OptionMenu = IMG_Load ("assets/menu/options_menu.png");
    VolumeBar = IMG_Load ("assets/menu/icon_volumebar.png");
    Volume = IMG_Load ("assets/menu/icon_volume.png");
    Checkedmark = IMG_Load ("assets/menu/icon_checkedmark.png.png");
    Uncheckedmark = IMG_Load ("assets/menu/icon_uncheckedmark.png");

    positionOptionMenu.x = 400;
    positionOptionMenu.y = 100;
    positionCheckedmark.x =70;
    positionCheckedmark.y =120;
    positionUncheckedmark.x =70;
    positionUncheckedmark.y =120;
    positionVolumeBar.x = 0;
    positionVolumeBar.y = 400;
    positionVolume.x = 50;
    positionVolume.y = 250;

    SDL_BlitSurface (OptionMenu, NULL, screen, &positionOptionMenu);
    SDL_BlitSurface (VolumeBar, NULL, screen, &positionVolumeBar);
    SDL_BlitSurface (Volume, NULL, screen, &positionVolume);
    if (fullscreen) {
        SDL_BlitSurface (Checkedmark, NULL, screen, &positionCheckedmark);
    }
    else {
        SDL_BlitSurface (Uncheckedmark, NULL, screen, &positionUncheckedmark);
    }
    SDL_Flip (screen);

    int waiting = 1;
    while (waiting) {
        while (SDL_PollEvent (&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        waiting = 0;
                    }
                break;

                case SDL_MOUSEBUTTONUP:
                    if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > 50 && event.button.x < 260) && (event.button.y < 665 && event.button.y > 600)) {
                        // Fullscreen setting (box)
                        if (fullscreen) {
                            fullscreen--;
                            SDL_BlitSurface (OptionMenu, NULL, screen, &positionOptionMenu);
                            SDL_BlitSurface (VolumeBar, NULL, screen, &positionVolumeBar);
                            SDL_BlitSurface (Volume, NULL, screen, &positionVolume);
                            SDL_BlitSurface (Uncheckedmark, NULL, screen, &positionUncheckedmark);
                            SDL_Flip (screen);
                        }
                        else {
                            fullscreen++;
                            SDL_BlitSurface (OptionMenu, NULL, screen, &positionOptionMenu);
                            SDL_BlitSurface (VolumeBar, NULL, screen, &positionVolumeBar);
                            SDL_BlitSurface (Volume, NULL, screen, &positionVolume);
                            SDL_BlitSurface (Checkedmark, NULL, screen, &positionCheckedmark);
                            SDL_Flip (screen);
                        }
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > 460 && event.button.x < 710) && (event.button.y < 665 && event.button.y > 600)) {
                        // Audio setting (bar)
                    }
                break;
            }
        }
    }
    SDL_FreeSurface (OptionMenu); SDL_FreeSurface (Checkedmark); SDL_FreeSurface (Uncheckedmark);
    SDL_FreeSurface (VolumeBar); SDL_FreeSurface (Volume);
    return 1;
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void GIFloader (char prefix[], char suffix[], SDL_Surface *screen, SDL_Rect position, int maximum, int repeat) {
    // As the name implies, load a gif
    // Load the gif until the "maximum" is reached
    // Maximum should be the total number of image of the gif
    // If half of the gif should be loaded then the maximum would take half of the total number of images

    int i;
    char arg[4];
    char name[50];
    SDL_Surface *gif = NULL;
    while ((i < maximum) && (repeat > 0)) {
        if (i > maximum) {
            i = 0;
            repeat--;
        }
        sprintf (arg, "%d", i);
        if (i > 99) {
            strcpy (name, prefix);
            strcat (name, arg);
            strcat (name, suffix);
            gif = IMG_Load (name);
            SDL_BlitSurface (gif, NULL, screen, &position);
            printf ("%s has been loaded\n", name);
        }
        else if (i > 9) {
            strcpy (name, prefix);
            strcat (name, "0");
            strcat (name, arg);
            strcat (name, suffix);
            gif = IMG_Load (name);
            SDL_BlitSurface (gif, NULL, screen, &position);
            printf ("%s has been loaded\n", name);
        }
        else {
            strcpy (name, prefix);
            strcat (name, "00");
            strcat (name, arg);
            strcat (name, suffix);
            gif = IMG_Load (name);
            SDL_BlitSurface (gif, NULL, screen, &position);
            printf ("%s has been loaded\n", name);
        }
        i++;
        SDL_Flip (screen);
    }
}

void GIFloaderBuffer (char prefix[], char suffix[], SDL_Surface *screen, SDL_Rect position, int *buffer, int *i, int maximum) {
    // As the name implies, load a gif
    // This one deactivate itself after one image load
    // To reactive make so that the "buffer" is positive before calling the function

    char arg[4];
    char name[50];
    SDL_Surface *gif = NULL;
    while (*buffer) {
        if (*i > maximum) {
            *i = 0;
        }
        sprintf (arg, "%d", *i);
        if (*i > 99) {
            strcpy (name, prefix);
            strcat (name, arg);
            strcat (name, suffix);
            gif = IMG_Load (name);
            SDL_BlitSurface (gif, NULL, screen, &position);
            printf ("%s has been loaded\n", name);
        }
        else if (*i > 9) {
            strcpy (name, prefix);
            strcat (name, "0");
            strcat (name, arg);
            strcat (name, suffix);
            gif = IMG_Load (name);
            SDL_BlitSurface (gif, NULL, screen, &position);
            printf ("%s has been loaded\n", name);
        }
        else {
            strcpy (name, prefix);
            strcat (name, "00");
            strcat (name, arg);
            strcat (name, suffix);
            gif = IMG_Load (name);
            SDL_BlitSurface (gif, NULL, screen, &position);
            printf ("%s has been loaded\n", name);
        }
        (*i)++;
        *buffer = 0;
        SDL_Flip (screen);
    }
}



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
