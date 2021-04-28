#include "assets/scripts/menu_header.h"

typedef struct
{
    char name[16];
    int KeyValue;
} Key;


void DefaultKeySettings (Key KeyMap[]) {
    strcpy (KeyMap[0].name, "right");
    KeyMap[0].KeyValue = 100;
    strcpy (KeyMap[1].name, "left");
    KeyMap[1].KeyValue = 97;
    strcpy (KeyMap[2].name, "jump");
    KeyMap[2].KeyValue = 119;
    strcpy (KeyMap[3].name, "interact");
    KeyMap[3].KeyValue = 101;

    strcpy (KeyMap[4].name, "right");
    KeyMap[4].KeyValue = 275;
    strcpy (KeyMap[5].name, "left");
    KeyMap[5].KeyValue = 276;
    strcpy (KeyMap[6].name, "jump");
    KeyMap[6].KeyValue = 273;
    strcpy (KeyMap[7].name, "interact");
    KeyMap[7].KeyValue = 48;
}

void SaveFile (Key KeyMap[]) {
    FILE *save;
    save = fopen ("keymap.ini", "w");
    char line[32];
    char temp[32];
    int i;

    fprintf (save, "[Player1]\n");
    for (i = 0; i < 4; i++) {
        fprintf (save, "%s=%d\n", KeyMap[i].name, KeyMap[i].KeyValue);
    }
    fprintf (save, "\n[Player2]\n");
    for (i = 4; i < 8; i++) {
        fprintf (save, "%s=%d\n", KeyMap[i].name, KeyMap[i].KeyValue);
    }
    fprintf (save, "\n;;;;;\n[Infos]\n;\n; Check ''SDL Key Values.txt'' to know all of SDL Key codes\n;\n;;;;;");
    fclose(save);
}

void FetchFromFile (Key KeyMap[]) {
    FILE *settings;
    settings = fopen ("keymap.ini", "r");
    if (settings == NULL) {
        DefaultKeySettings (KeyMap);
        SaveFile (KeyMap);
    }
    char line[32];
    char temp[32];
    int i = 0;
    char *token;

    while (fgets (line, sizeof (line), settings) && !(strstr (line, ";;;"))) {
        if (strchr (line, '[') && strchr (line, ']')) {
            while ((fgets (line, sizeof (line), settings)) && (*line != '\n')) {
                token = strtok(line, "=");
                sprintf (KeyMap[i].name, "%s", token);
                token = strtok (NULL, "=");
                sprintf (temp, "%s", token);
                KeyMap[i].KeyValue = atoi (temp);
                i++;
            }
        }
    }
    fclose(settings);
}


int KeyAssignationCheck (Key KeyMap[], int Key) {
    int i;
    for (i = 0; i < 7; i++) {
        if (KeyMap[i].KeyValue == Key) {
            // The key is already assigned
            return i;
        }
    }
    // The key is not assigned
    return -1;
}


int AskConfirmation (SDL_Surface *screen, SDL_Rect position, SDL_Event event) {
    // A prompt pops up if the selected key is already used
    SDL_Surface *background = NULL, *overlay = NULL;
    SDL_Rect positionYes, positionNo;

    background = IMG_Load ("assets/menu/.png");
    overlay = IMG_Load ("assets/menu/.png");

    position.x = 0;
    position.y = 0;
    positionYes.x = 500;
    positionYes.y = 500;
    positionNo.x = 400;
    positionNo.y = 500;

    SDL_BlitSurface (overlay, NULL, screen, &position);
    SDL_BlitSurface (background, NULL, screen, &position);
    SDL_Flip (screen);

    while (1) {
        while (SDL_WaitEvent (&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        SDL_FreeSurface (overlay);
                        SDL_FreeSurface (background);
                        return 1;
                    }
                    else if (event.key.keysym.sym == SDLK_ESCAPE) {
                        SDL_FreeSurface (overlay);
                        SDL_FreeSurface (background);
                        return 0;
                    }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > positionYes.x && event.button.x < (positionYes.x+210)) && (event.button.y > positionYes.y && event.button.y < (positionYes.y+65))) {
                        // The user selected yes
                        SDL_FreeSurface (overlay);
                        SDL_FreeSurface (background);
                        return 1;
                    }
                    else if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x > positionNo.x && event.button.x < (positionNo.x+210)) && (event.button.y > positionNo.y && event.button.y < (positionNo.y+65))) {
                        // The user selected no
                        SDL_FreeSurface (overlay);
                        SDL_FreeSurface (background);;
                        return 0;
                    }
                break;

                case SDL_QUIT:
                    exit (0);
            }
        }
    }
    SDL_FreeSurface (overlay);
    SDL_FreeSurface (background);
    printf ("Something didn't work properly\n");
    return -1;
}


int KeyPrompt (SDL_Surface *screen, SDL_Rect position, SDL_Event event, Key KeyMap[], int KeyPos) {
    // After clicking on a box, ask what the user to input a key
    SDL_Surface *background = NULL, *overlay = NULL,*prompt = NULL;
    SDL_Rect positionPrompt;

    background = IMG_Load ("assets/menu/.png");
    overlay = IMG_Load ("assets/menu/.png");
    prompt = IMG_Load ("assets/menu/.png");
    positionPrompt.x = 480;
    positionPrompt.y = 360;

    SDL_BlitSurface (overlay, NULL, screen, &position);
    SDL_BlitSurface (background, NULL, screen, &position);
    SDL_BlitSurface (prompt, NULL, screen, &positionPrompt);
    SDL_Flip (screen);

    int pos;

    while (1) {
        while (SDL_WaitEvent (&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    pos = KeyAssignationCheck (KeyMap, event.key.keysym.sym);
                    if ((pos >= 0) && (AskConfirmation (screen, position, event))) {
                        // The key is already assigned
                        // Ask if the user want to switch keys
                        KeyMap[pos].KeyValue = KeyMap[KeyPos].KeyValue;
                        KeyMap[KeyPos].KeyValue = event.key.keysym.sym;
                        SDL_FreeSurface (overlay);
                        SDL_FreeSurface (background);
                        SDL_FreeSurface (prompt);
                        return 1;
                    }
                    else {
                        // The key is not assigned
                        // So you assign the key
                        // Duh
                        KeyMap[KeyPos].KeyValue = event.key.keysym.sym;
                        SDL_FreeSurface (overlay);
                        SDL_FreeSurface (background);
                        SDL_FreeSurface (prompt);
                        return 0;
                    }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    if ((event.button.button == SDL_BUTTON_LEFT) && ((event.button.x > positionPrompt.x && event.button.x < (positionPrompt.x+375)) && (event.button.y > positionPrompt.y && event.button.y < (positionPrompt.y+100)))) {
                        SDL_FreeSurface (overlay);
                        SDL_FreeSurface (background);
                        SDL_FreeSurface (prompt);
                        return -1;
                    }
                break;

                case SDL_QUIT:
                    exit (0);
            }
        }
    }
    SDL_FreeSurface (overlay);
    SDL_FreeSurface (background);
    SDL_FreeSurface (prompt);
    printf ("Something went wrong\n");
    return -1;
}



int KeyMenu (SDL_Surface *screen, SDL_Rect position) {
    SDL_Surface *background = NULL, *overlay = NULL;
    SDL_Rect positionOverlay, positionApply, positionCancel, positionReturn, positionP1Right, positionP1Left, positionP1Jump, positionP1Interact, positionP2Right, positionP2Left, positionP2Jump, positionP2Interact;

    background = IMG_Load ("assets/menu/.png");
    positionOverlay.x = 0;
    positionOverlay.y = 0;
    positionApply.x = 0;
    positionApply.y = 0;
    positionCancel.x = 0;
    positionCancel.y = 0;
    positionReturn.x = 0;
    positionReturn.y = 0;

    positionP1Right.x = 0;
    positionP1Right.y = 0;
    positionP1Left.x = 0;
    positionP1Left.y = 0;
    positionP1Jump.x = 0;
    positionP1Jump.y = 0;
    positionP1Interact.x = 0;
    positionP1Interact.y = 0;

    positionP2Right.x = 0;
    positionP2Right.y = 0;
    positionP2Left.x = 0;
    positionP2Left.y = 0;
    positionP2Jump.x = 0;
    positionP2Jump.y = 0;
    positionP2Interact.x = 0;
    positionP2Interact.y = 0;


    Key KeyMap[8];
    SDL_Event event;
    int running = 1;

    SDL_BlitSurface (overlay, NULL, screen, &position);
    SDL_BlitSurface (background, NULL, screen, &position);
    SDL_Flip (screen);

    while (running) {
        while (SDL_WaitEvent (&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:


                case SDL_QUIT:
                    exit (0);

            }
        }
    }

    SDL_FreeSurface (overlay);
    SDL_FreeSurface (background);
    return 1;
}
