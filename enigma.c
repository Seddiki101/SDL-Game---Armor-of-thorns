#include "assets/scripts/enigma_header.h"
#include "assets/scripts/enigma_functions.c"


// Previously modified by :
//
// Last modified by : ilyes
//
// 351007 is funny. Funny numbers go brrrrrrrrrrrrrrrrr


int main (int retry) {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                   Surface Variables Initialisation                                           //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SDL_Surface *screen = NULL, *background = NULL, *overlay = NULL, *healthbar = NULL, *answertext1 = NULL, *answertext2 = NULL, *answertext3 = NULL, *Question = NULL, *Question2 = NULL;
    SDL_Rect position, positionHealthbar, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, positionAnswertext1, positionAnswertext2, positionAnswertext3, positionOverlay, positionQuestion, positionQuestion2;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                         Font/Text Initialisation                                             //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    TTF_Init();
    SDL_Color colourWhite  = {255, 255, 255}; SDL_Color colourBlack  = {0, 0, 0};
    TTF_Font *policeQuestion = NULL, *policeAnswer = NULL;
    policeQuestion = TTF_OpenFont ("assets/Roman.ttf", 16);
    policeAnswer = TTF_OpenFont ("assets/Roman.ttf", 30);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                           Sound Settings                                                     //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic (MIX_MAX_VOLUME / 5);
    Mix_Music *music ;
    Mix_Chunk *son_tick;

    music = Mix_LoadMUS ("assets/sounds/enigma_soundtrack01.wav");  // Loads the music from file
    Mix_PlayMusic (music, -1);                                      // Plays the music n-1 times (-1 = infinite loop)
    son_tick = Mix_LoadWAV ("assets/sounds/enigma_tick.wav");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                          Video Settings                                                      //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SDL_Init (SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode (1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption ("Armor of Thorns", NULL);
    SDL_WM_SetIcon (SDL_LoadBMP ("icon.bmp"), NULL);

    // Loads the images from file
    background = IMG_Load ("assets/enigma/background.png");
    overlay = IMG_Load ("assets/enigma/overlay.png");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                                Positions                                                     //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Position of the screen / background
    position.x = 0;
    position.y = 0;
    positionHealthbar.x = 9;
    positionHealthbar.y = 52;
    // Positions of the answers' box
    positionAnswerbox1.x = 69;
    positionAnswerbox1.y = 467;
    positionAnswerbox2.x = 485;
    positionAnswerbox2.y = 467;
    positionAnswerbox3.x = 911;
    positionAnswerbox3.y = 467;
    // Position of the Question
    positionQuestion.x = 478;
    positionQuestion.y = 162;
    positionQuestion2.x = 510;
    positionQuestion2.y = 249;

    int Width = 300; // X position
    int Height = 120; // Y position


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                           Essential Variables                                                //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SDL_Event event;
    int i;              // Super counter deluxe ++, also uses it to keep an eye on the size of the
    int running;        // For infinite loop
    int pressed;        // So the MOUSEMOTION doesn't spam everything
    int loop;           // left-right pog moment
    int NoRepeat[10];   // Used by "selector" function so that the same question isn't selected twice in a row
    int attempts;       // Store the answer to give the proper end screen
    int current;        // Store the current Question/Answers from Enigma[]
    enigma Enigma[10];


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//                                               Main Function                                                  //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    retry = 1;          // Don't worry about it
    srand (time (NULL));
    while (retry == 1) {
        FillEnigma (Enigma);
        attempts = 3;
        for (i = 0; i < 10 && attempts; i++) {
            Selector (NoRepeat, i, &current);
            AnswerSwitch (Enigma, &positionAnswertext1, &positionAnswertext2, &positionAnswertext3, current);
            Question = TTF_RenderText_Blended (policeQuestion, Enigma[current].question, colourWhite);
            Question2 = TTF_RenderText_Blended (policeQuestion, Enigma[current].question2, colourWhite);
            answertext1 = TTF_RenderText_Blended (policeAnswer, Enigma[current].answer1, colourWhite);
            answertext2 = TTF_RenderText_Blended (policeAnswer, Enigma[current].answer2, colourWhite);
            answertext3 = TTF_RenderText_Blended (policeAnswer, Enigma[current].answer3, colourWhite);
            //printf ("Current value : |%d| \nArrSize = |%d| \nCorrect answer : |%d| \n", current, i, Enigma[current].check);
            //printf ("Current Question : ''%s'' \nCurrent Answer1 : ''%s'' \nCurrent Answer2 : ''%s'' \nCurrent Answer3 : ''%s'' \n", Enigma[current].question, Enigma[current].answer1, Enigma[current].answer2, Enigma[current].answer3);

            if (attempts == 3) {
                healthbar = IMG_Load ("assets/enigma/healthbar_full.png");
            }
            else if (attempts == 2) {
                healthbar = IMG_Load ("assets/enigma/healthbar_middle.png");
            }
            else {
                healthbar = IMG_Load ("assets/enigma/healthbar_low.png");
            }

            SDL_BlitSurface (background, NULL, screen, &position);
            SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
            SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
            SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
            SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
            SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
            SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
            SDL_Flip (screen);

            loop = 1;
            pressed = 0;
            running = 1;
            while (running) {
                while (SDL_PollEvent (&event)) {
                    switch (event.type) {
                        case SDL_KEYDOWN:
                            if ((event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE)) {
                                switch (loop) {
                                    case 1:
                                        // Answer 1
                                        if (Enigma[current].check == 2) {
                                            running = 0;
                                        }
                                        else {
                                            attempts--;
                                            running = 0;
                                        }
                                    break;

                                    case 2:
                                        // Answer 2
                                        if (Enigma[current].check == 2) {
                                            running = 0;
                                        }
                                        else {
                                            attempts--;
                                            running = 0;
                                        }
                                    break;

                                    case 3 :
                                        // Answer 3
                                        if (Enigma[current].check == 3) {
                                            running = 0;
                                        }
                                        else {
                                            attempts--;
                                            running = 0;
                                        }
                                    break;
                                }
                            }
                            else if (event.key.keysym.sym == SDLK_RIGHT) {
                                if (loop == 1) {
                                    // 1 -> 2
                                    //printf ("1. We do be '%d' loopin\n", loop);
                                    loop++;
                                    Mix_PlayChannel (-1, son_tick, 0);
                                    SDL_BlitSurface (background, NULL, screen, &position);
                                    SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                    SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                    SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                    SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                    SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                    SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                    DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 2);
                                }
                                else if (loop == 2) {
                                    // 2 -> 3
                                    //printf ("1. We do be '%d' loopin\n", loop);
                                    loop++;
                                    Mix_PlayChannel (-1, son_tick, 0);
                                    SDL_BlitSurface (background, NULL, screen, &position);
                                    SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                    SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                    SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                    SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                    SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                    SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                    DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 3);
                                }
                                else {
                                    // 3 -> 1
                                    //printf ("2. We do be '%d' loopin\n", loop);
                                    loop = 1;
                                    Mix_PlayChannel (-1, son_tick, 0);
                                    SDL_BlitSurface (background, NULL, screen, &position);
                                    SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                    SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                    SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                    SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                    SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                    SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                    DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 1);
                                }
                            }
                            else if (event.key.keysym.sym == SDLK_LEFT) {
                                if (loop == 1) {
                                    // 1 -> 3
                                    //printf ("1. We do be '%d' loopin\n", loop);
                                    loop = 3;
                                    Mix_PlayChannel (-1, son_tick, 0);
                                    SDL_BlitSurface (background, NULL, screen, &position);
                                    SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                    SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                    SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                    SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                    SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                    SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                    DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 3);
                                }
                                else if (loop == 2) {
                                    // 2 -> 1
                                    //printf ("2. We do be '%d' loopin\n", loop);
                                    loop--;
                                    Mix_PlayChannel (-1, son_tick, 0);
                                    SDL_BlitSurface (background, NULL, screen, &position);
                                    SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                    SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                    SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                    SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                    SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                    SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                    DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 1);
                                }
                                else {
                                    // 3 -> 2
                                    //printf ("2. We do be '%d' loopin\n", loop);
                                    loop--;
                                    Mix_PlayChannel (-1, son_tick, 0);
                                    SDL_BlitSurface (background, NULL, screen, &position);
                                    SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                    SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                    SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                    SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                    SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                    SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                    DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 2);
                                }
                            }
                        break;

                        case SDL_MOUSEBUTTONDOWN:
                            //printf ("Mouse button %d pressed at (%d,%d)\n", event.button.button, event.button.x, event.button.y); // Helps for pinpointing locations
                            if ((event.button.button == SDL_BUTTON_LEFT) && !pressed) {
                                SDL_BlitSurface (background, NULL, screen, &position);
                                SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                SDL_Flip (screen);
                            }
                            else if ((event.button.button == SDL_BUTTON_LEFT) && ((event.button.x > positionAnswerbox1.x && event.button.x < (positionAnswerbox1.x+Width)) && (event.button.y > positionAnswerbox1.y && event.button.y < (positionAnswerbox1.y+Height)))) {
                                // Answer 1
                                if (Enigma[current].check == 1) {
                                    running = 0;
                                }
                                else {
                                    attempts--;
                                    running = 0;
                                }
                            }
                            else if ((event.button.button == SDL_BUTTON_LEFT) && ((event.button.x > positionAnswerbox2.x && event.button.x < (positionAnswerbox2.x+Width)) && (event.button.y > positionAnswerbox2.y && event.button.y < (positionAnswerbox2.y+Height)))) {
                                // Answer 2
                                if (Enigma[current].check == 2) {
                                    running = 0;
                                }
                                else {
                                    attempts--;
                                    running = 0;
                                }
                            }
                            else if ((event.button.button == SDL_BUTTON_LEFT) && ((event.button.x > positionAnswerbox3.x && event.button.x < (positionAnswerbox3.x+Width)) && (event.button.y > positionAnswerbox3.y && event.button.y < (positionAnswerbox3.y+Height)))) {
                                // Answer 3
                                if (Enigma[current].check == 3) {
                                    running = 0;
                                }
                                else {
                                    attempts--;
                                    running = 0;
                                }
                            }
                        break;

                        case SDL_MOUSEMOTION:
                            // printf ("\nMouse moved by %d,%d to (%d,%d)\n", event.motion.xrel, event.motion.yrel, event.motion.x, event.motion.y);
                            // Funny colours when hovering the mouse
                            if ( ! (((event.motion.x > positionAnswerbox1.x && event.motion.x < (positionAnswerbox1.x+Width)) && (event.motion.y > positionAnswerbox1.y && event.motion.y < (positionAnswerbox1.y+Height)))
                                || ((event.motion.x > positionAnswerbox2.x && event.motion.x < (positionAnswerbox2.x+Width)) && (event.motion.y > positionAnswerbox2.y && event.motion.y < (positionAnswerbox2.y+Height)))
                                || ((event.motion.x > positionAnswerbox3.x && event.motion.x < (positionAnswerbox3.x+Width)) && (event.motion.y > positionAnswerbox3.y && event.motion.y < (positionAnswerbox3.y+Height)))) && pressed) {
                                pressed = 0;
                                SDL_BlitSurface (background, NULL, screen, &position);
                                SDL_BlitSurface (healthbar, NULL, screen, &positionHealthbar);
                                SDL_BlitSurface (Question, NULL, screen, &positionQuestion);
                                SDL_BlitSurface (Question2, NULL, screen, &positionQuestion2);
                                SDL_BlitSurface (answertext1, NULL, screen, &positionAnswertext1);
                                SDL_BlitSurface (answertext2, NULL, screen, &positionAnswertext2);
                                SDL_BlitSurface (answertext3, NULL, screen, &positionAnswertext3);
                                SDL_Flip (screen);
                            }
                            else if (((event.motion.x > positionAnswerbox1.x && event.motion.x < (positionAnswerbox1.x+Width)) && (event.motion.y > positionAnswerbox1.y && event.motion.y < (positionAnswerbox1.y+Height))) && (pressed != 1)) {
                                pressed = 1;
                                // printf ("just pressed 1 a button smh : %d\n", pressed);
                                loop = 1;
                                Mix_PlayChannel (-1, son_tick, 0);
                                DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 1);
                            }
                            else if (((event.motion.x > positionAnswerbox2.x && event.motion.x < (positionAnswerbox2.x+Width)) && (event.motion.y > positionAnswerbox2.y && event.motion.y < (positionAnswerbox2.y+Height))) && (pressed != 2)) {
                                pressed = 2;
                                // printf ("just pressed 2 a button smh : %d\n", pressed);
                                loop = 2;
                                Mix_PlayChannel (-1, son_tick, 0);
                                DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 2);
                            }
                            else if (((event.motion.x > positionAnswerbox3.x && event.motion.x < (positionAnswerbox3.x+Width)) && (event.motion.y > positionAnswerbox3.y && event.motion.y < (positionAnswerbox3.y+Height))) && (pressed != 3)) {
                                pressed = 3;
                                // printf ("just pressed 2 a button smh : %d\n", pressed);
                                loop = 3;
                                Mix_PlayChannel (-1, son_tick, 0);
                                DrawOverlay (screen, overlay, positionOverlay, positionAnswerbox1, positionAnswerbox2, positionAnswerbox3, 3);
                            }
                        break;

                        case SDL_QUIT:
                            exit (0);
                    }
                }
            }
        }
        // End screen function
        EndScreen (screen, overlay, position, positionOverlay, son_tick, attempts, &retry);
    }

    TTF_CloseFont (policeQuestion);
    TTF_CloseFont (policeAnswer);
    TTF_Quit ();

    SDL_FreeSurface (background);
    SDL_FreeSurface (healthbar);
    SDL_FreeSurface (answertext1);
    SDL_FreeSurface (answertext2);
    SDL_FreeSurface (answertext3);
    SDL_FreeSurface (overlay);
    SDL_FreeSurface (Question);
    SDL_FreeSurface (Question2);
    SDL_Quit ();

    return retry;
}
