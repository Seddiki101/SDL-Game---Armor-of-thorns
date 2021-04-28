#include "enigma_header.h"
#include "enigma_fill.c"


// Previously modified by :
//
// Last modified by : ilyes
//
// 300542 is funny. Funny numbers go brrrrrrrrrrrrrrrrr



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void DrawOverlay (SDL_Surface *screen, SDL_Surface *overlay, SDL_Rect positionOverlay, SDL_Rect Holder1, SDL_Rect Holder2, SDL_Rect Holder3, int arg) {
    // Draw the overlay ...
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


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void FillEnigma (enigma Enigma[]) {
    // We fill all the possible questions and their answers here
    // Everything is randomly generated for maximum fun
    // Because of that everything is almost exclusively math-related question
    // But Maths are cool so that's fine
    // coolmathgames.com
    int i = 1;

    Enigma1 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma2 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma3 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma4 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma5 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma6 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma7 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma8 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma9 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n", i);
    i++;

    Enigma10 (Enigma);
    printf ("Enigma %d mounted, and LoAdEd!!\n\n", i);
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int Check (int arr[], int Size, int checked) {
    // Checks if an int is in an array of int
    int i;
    for (i = 0; i < Size; i++) {
        if (arr[i] == checked) {
            return 1;
        }
    }
    return 0;
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Selector (int NoRepeat[], int Size, int *current) {
    // Function that selects randomly a question (without choosing twice the same)
    int i;
    if (Size == 9) {
        (*current) = 9;
    }
    else {
        do {
            (*current) = Random (0, 8);
        } while (Check (NoRepeat, Size, *current));
    }
    NoRepeat[Size] = (*current);
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void AnswerSwitch (enigma Enigma[], SDL_Rect *positionAnswer1, SDL_Rect *positionAnswer2, SDL_Rect *positionAnswer3, int current) {
    // Switch position of the answers on the screen
    // 5/6 chances to happen
    int random, tempX, tempY;

    // Default Answers' positions
    (*positionAnswer1).x = 160;
    (*positionAnswer1).y = 510;
    (*positionAnswer2).x = 576;
    (*positionAnswer2).y = 510;
    (*positionAnswer3).x = 1002;
    (*positionAnswer3).y = 510;

    // The good answer is always the 3rd ---> check = 3
    // Change the check accordingly
    random = Random (0, 5);

    //printf ("Switch activated with arg : |%d|\n", random);
    switch (random) {
	case 0:
	    Enigma[current].check = 3;
	break;

        case 1:
	    Enigma[current].check = 3;
            tempX = (*positionAnswer2).x;
            tempY = (*positionAnswer2).y;
            (*positionAnswer2).x = (*positionAnswer1).x;
            (*positionAnswer2).y = (*positionAnswer1).y;
            (*positionAnswer1).x = tempX;
            (*positionAnswer1).y = tempY;
        break;

        case 2:
            Enigma[current].check = 2;
            tempX = (*positionAnswer3).x;
            tempY = (*positionAnswer3).y;
            (*positionAnswer3).x = (*positionAnswer2).x;
            (*positionAnswer3).y = (*positionAnswer2).y;
            (*positionAnswer2).x = tempX;
            (*positionAnswer2).y = tempY;
        break;

        case 3:
            Enigma[current].check = 2;
            tempX = (*positionAnswer3).x;
            tempY = (*positionAnswer3).y;
            (*positionAnswer3).x = (*positionAnswer2).x;
            (*positionAnswer3).y = (*positionAnswer2).y;
	    (*positionAnswer2).x = (*positionAnswer1).x;
            (*positionAnswer2).y = (*positionAnswer1).y;
            (*positionAnswer1).x = tempX;
            (*positionAnswer1).y = tempY;
        break;

        case 4:
            Enigma[current].check = 1;
            tempX = (*positionAnswer3).x;
            tempY = (*positionAnswer3).y;
            (*positionAnswer3).x = (*positionAnswer1).x;
            (*positionAnswer3).y = (*positionAnswer1).y;
            (*positionAnswer1).x = (*positionAnswer2).x;
            (*positionAnswer1).y = (*positionAnswer2).y;
            (*positionAnswer2).x = tempX;
            (*positionAnswer2).y = tempY;
        break;

        case 5:
            Enigma[current].check = 1;
            tempX = (*positionAnswer3).x;
            tempY = (*positionAnswer3).y;
            (*positionAnswer3).x = (*positionAnswer1).x;
            (*positionAnswer3).y = (*positionAnswer1).y;
            (*positionAnswer1).x = tempX;
            (*positionAnswer1).y = tempY;
        break;
    }
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void EndScreen (SDL_Surface *screen, SDL_Surface *overlay, SDL_Rect position, SDL_Rect positionOverlay, Mix_Chunk *son, int attempts, int *retry) {
    // Shows the End Screen
    SDL_Surface *background = NULL;
    SDL_Rect positionReturn, positionContinue;

    positionReturn.x = 69;
    positionReturn.y = 467;
    positionContinue.x = 911;
    positionContinue.y = 467;
    int Width = 300; // X position
    int Height = 120; // Y position

    SDL_Event event;

    int running = 1;
    int loop = 2;
    int pressed = 0;

    if (attempts) {
        background = IMG_Load ("assets/enigma/background_success.png");
    }
    else {
        background = IMG_Load ("assets/enigma/background_failure.png");
    }

    SDL_BlitSurface (background, NULL, screen, &position);
    SDL_Flip (screen);

    while (running) {
        while (SDL_PollEvent (&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if ((event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE)) {
                        switch (loop) {
                            case 1:
                                // Return
                                (*retry) = -1;
                                running = 0;
                            break;

                            case 2:
                                // Retry / Continue
                                if (attempts) {
                                    (*retry) = 0;
                                }
                                else {
                                    (*retry) = 1;
                                }
                                running = 0;
                            break;
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_RIGHT) {
                        if (loop == 1) {
                            // 1 -> 2
                            //printf ("1. We do be '%d' loopin\n", loop);
                            loop++;
                            Mix_PlayChannel (-1, son, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            DrawOverlay (screen, overlay, positionOverlay, positionReturn, positionContinue, position, 2);
                        }
                        else {
                            // 2 -> 1
                            //printf ("2. We do be '%d' loopin\n", loop);
                            loop--;
                            Mix_PlayChannel (-1, son, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            DrawOverlay (screen, overlay, positionOverlay, positionReturn, positionContinue, position, 1);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_LEFT) {
                        if (loop == 1) {
                            // 1 -> 2
                            //printf ("1. We do be '%d' loopin\n", loop);
                            loop++;
                            Mix_PlayChannel (-1, son, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            DrawOverlay (screen, overlay, positionOverlay, positionReturn, positionContinue, position, 2);
                        }
                        else {
                            // 2 -> 1
                            //printf ("2. We do be '%d' loopin\n", loop);
                            loop--;
                            Mix_PlayChannel (-1, son, 0);
                            SDL_BlitSurface (background, NULL, screen, &position);
                            DrawOverlay (screen, overlay, positionOverlay, positionReturn, positionContinue, position, 1);
                        }
                    }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    printf ("Mouse button %d pressed at (%d,%d)\n", event.button.button, event.button.x, event.button.y); // Helps for pinpointing locations
                    if ((event.button.button == SDL_BUTTON_LEFT) && !pressed) {
                        SDL_BlitSurface (background, NULL, screen, &position);
                        SDL_Flip (screen);
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && ((event.button.x > positionReturn.x && event.button.x < (positionReturn.x+Width)) && (event.button.y > positionReturn.y && event.button.y < (positionReturn.y+Height)))) {
                        // Return
                        (*retry) = -1;
                        running = 0;
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && ((event.button.x > positionContinue.x && event.button.x < (positionContinue.x+Width)) && (event.button.y > positionContinue.y && event.button.y < (positionContinue.y+Height)))) {
                        // Retry / Continue
                        if (attempts) {
                            (*retry) = 0;
                        }
                        else {
                            (*retry) = 1;
                        }
                        running = 0;
                    }
                break;

                case SDL_MOUSEMOTION:
                    // printf ("\nMouse moved by %d,%d to (%d,%d)\n", event.motion.xrel, event.motion.yrel, event.motion.x, event.motion.y);
                    // Funny colours when hovering the mouse
                    if ( ! (((event.motion.x > positionReturn.x && event.motion.x < (positionReturn.x+Width)) && (event.motion.y > positionReturn.y && event.motion.y < (positionReturn.y+Height)))
                        || ((event.motion.x > positionContinue.x && event.motion.x < (positionContinue.x+Width)) && (event.motion.y > positionContinue.y && event.motion.y < (positionContinue.y+Height)))) && pressed) {
                        pressed = 0;
                        SDL_BlitSurface (background, NULL, screen, &position);
                        SDL_Flip (screen);
                    }
                    else if (((event.motion.x > positionReturn.x && event.motion.x < (positionReturn.x+Width)) && (event.motion.y > positionReturn.y && event.motion.y < (positionReturn.y+Height))) && (pressed != 1)) {
                        // Return
                        pressed = 1;
                        // printf ("just pressed 1 a button smh : %d\n", pressed);
                        loop = 1;
                        Mix_PlayChannel (-1, son, 0);
                        DrawOverlay (screen, overlay, positionOverlay, positionReturn, positionContinue, position, 1);
                    }
                    else if (((event.motion.x > positionContinue.x && event.motion.x < (positionContinue.x+Width)) && (event.motion.y > positionContinue.y && event.motion.y < (positionContinue.y+Height))) && (pressed != 2)) {
                        // Continue
                        pressed = 2;
                        // printf ("just pressed 2 a button smh : %d\n", pressed);
                        loop = 2;
                        Mix_PlayChannel (-1, son, 0);
                        DrawOverlay (screen, overlay, positionOverlay, positionReturn, positionContinue, position, 2);
                    }
                break;

                case SDL_QUIT:
                    exit (0);
            }
        }
    }
    SDL_FreeSurface (background);
}



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
