#include "enigma_header.h"


// Previously modified by :
//
// Last modified by : ilyes
//
// 165990 is funny. Funny numbers go brrrrrrrrrrrrrrrrr



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int Random (int lower, int upper) {
    // Generates a random int between two values
    return (rand() % (upper - lower + 1)) + lower;
}

float RandomFloat(float lower, float upper) {
   return ((upper - lower) * ((float)rand() / RAND_MAX)) + lower;
}

float SquareRoot (float number) {
    float temp, sqrt;
    sqrt = number / 2;
    temp = 0;
    while (sqrt != temp) {
        temp = sqrt;
        sqrt = ( number/temp + temp) / 2;
    }
    return sqrt;
}

float Power (float x, int y) {
    float temp;
    if (y == 0) {
       return 1;
    }
    temp = Power (x, y/2);
    if (y%2 == 0) {
        return temp*temp;
    }
    else {
        if (y > 0) {
            return x*temp*temp;
        }
        else {
            return (temp*temp)/x;
        }
    }
}

char *Strrev (char *str) {
    char *p1, *p2;
    if (! str || ! *str) {
        return str;
    }
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Enigma1 (enigma Enigma[]) {
    ////////////////////
    //   Question 1   //
    ////////////////////
    // Equation de premier degree
    float a, b, c, d, e;
    do {
        a = RandomFloat (-69, 69);
        b = RandomFloat (-69, 69);
    } while (!a);
    strcpy (Enigma[0].question, "Donner la valeure de x :");
    sprintf (Enigma[0].question2, "%.1fx + %.1f = 0", a, b);

    e = -b/a;
    do {
        c = e + RandomFloat (-10, 10);;
        d = e + RandomFloat (-10, 10);;
    } while ((c == e) || (d == e));
    sprintf (Enigma[0].answer1, "%.2f", c);
    sprintf (Enigma[0].answer2, "%.2f", d);
    sprintf (Enigma[0].answer3, "%.2f", e);
    Enigma[0].check = 3;
}


void Enigma2 (enigma Enigma[]) {
    ////////////////////
    //   Question 2   //
    ////////////////////
    // Equation de 2eme degree
    float a, b, c, d, e, delta;
    do {
        a = RandomFloat (-69, 69);
        b = RandomFloat (-69, 69);
        c = RandomFloat (-69, 69);
        delta = (b * b) - (4*a*c);
    } while (!a || (delta < 0));

    strcpy (Enigma[1].question, "Donner une racine de l'equation");
    if (b && c) {
        sprintf (Enigma[1].question2, "%.1fx^2 + %.1fx + %.1f", a, b, c);
    }
    else if (b && !c) {
        sprintf (Enigma[1].question2, "%.1fx^2 + %.1fx", a, b);
    }
    else if (!b && c) {
        sprintf (Enigma[1].question2, "%.1fx^2 + %.1f", a, c);
    }

    if (delta) {
        float x1 = (-b+SquareRoot(delta)) / (2*a);
        float x2 = (-b-SquareRoot(delta)) / (2*a);
        do {
            d = x1 + RandomFloat (-20, 20);
            e = x2 + RandomFloat (-20, 20);
        } while ((d == x1 || d == x2) || (e == x1 || e == x2));
        sprintf (Enigma[1].answer1, "%.2f", d);
        sprintf (Enigma[1].answer2, "%.2f", e);

        int bruh = Random (0, 1);
        if (bruh) {
            sprintf (Enigma[1].answer3, "%.2f", x1);
        }
        else {
            sprintf (Enigma[1].answer3, "%.2f", x2);
        }
    }
    else {
        float x = -b / (2*a);
        do {
            d = x + RandomFloat (-20, 20);
            e = x + RandomFloat (-20, 20);
        } while ((d == x) || (e == x));
        sprintf (Enigma[1].answer1, "%.2f", d);
        sprintf (Enigma[1].answer2, "%.2f", e);
        sprintf (Enigma[1].answer3, "%.2f", x);
    }
    Enigma[1].check = 3;
}

void Enigma3 (enigma Enigma[]) {
    ////////////////////
    //   Question 3   //
    ////////////////////
    // Tour de Hanoi
    // T(n) = 2^n - 1
    int i, n, a, b, x;
    n = Random (3, 26);
    strcpy (Enigma[2].question, "Combien de deplacement pour resoudre");
    sprintf (Enigma[2].question2, "une tour de hanoi de %d anneaux ?", n);

    x = 1;
    for (i = 0; i < n; i++) {
        x *= 2;
    }
    x--;
    do {
        a = x + Random (-420, 420);
        b = x + Random (-420, 420);
    } while ((a == x) || (b == x) || (a < 0) || (b < 0));
    sprintf (Enigma[2].answer1, "%d", a);
    sprintf (Enigma[2].answer2, "%d", b);
    sprintf (Enigma[2].answer3, "%d", x);
    Enigma[2].check = 3;
}

void Enigma4 (enigma Enigma[]) {
    ////////////////////
    //   Question 4   //
    ////////////////////
    // Donner l'aire d'un cercle de diametre x
    float x, a, b, c;
    x = RandomFloat (0, 69);
    strcpy (Enigma[3].question, "Donner l'aire d'un cercle");
    sprintf (Enigma[3].question2, "de diametre %.1f", x);
    float r = x / 2;
    c = 3.14159265359 * (r * r) ;
    do {
        a = c + RandomFloat (-30, 30);
        b = c + RandomFloat (-30, 30);
    } while ((a == c) || (b == c) || (b < 0) || (c < 0));
    sprintf (Enigma[3].answer1, "%.2f", a);
    sprintf (Enigma[3].answer2, "%.2f", b);
    sprintf (Enigma[3].answer3, "%.2f", c);
    Enigma[3].check = 3;
}

void Enigma5 (enigma Enigma[]) {
    ////////////////////
    //   Question 5   //
    ////////////////////
    // Binaire au decimal ou l'inverse
    int n, x, i;
    float a, b, c;
    char temp[2];
    char binary[128];
    n = Random (1, 16);

    do {
        x = Random (0, 1);
        sprintf (temp, "%d", x);
        strcpy (binary, temp);
        for (i = 0; i < n-1; i++) {
            x = Random (0, 1);
            sprintf (temp, "%d", x);
            strcat (binary, temp);
            if (x) {
                c += Power (2, i);
            }
        }
        Strrev (binary);
        strcpy (Enigma[4].question, "Donner la decimale de : ");
        strcpy (Enigma[4].question2, binary);
    } while (!c);
    do {
        a = c + Random (-69, 69);
        b = c + Random (-69, 69);
    } while ((a == c) || (b == c) || (a < 0) || (b < 0));
    sprintf (Enigma[4].answer1, "%.0f", a);
    sprintf (Enigma[4].answer2, "%.0f", b);
    sprintf (Enigma[4].answer3, "%.0f", c);
    Enigma[4].check = 3;
}

void Enigma6 (enigma Enigma[]) {
    ////////////////////
    //   Question 6   //
    ////////////////////
    // Quel est la probabilite que le chiffre suivant soit x sachant qu'on a : rand (n, m)
    // Tel que m>n et x compris entre n et m
    float x, n, m, a, chance;

    do {
        x = RandomFloat (-42, 42);
        n = RandomFloat (-69, 69);
        m = RandomFloat (-69, 69);
    } while ((n >= m) || (x <= n) || (x >= m));
    sprintf (Enigma[5].question, "Quel est la probabilite que x = %.0f", x);
    sprintf (Enigma[5].question2, "sachant que : %.0f = Random(%.0f,%.0f)", x, n, m);

    chance = (100 / (m - n));
    do {
        a = RandomFloat (0, 100);
    } while (((a > chance-0.5) && (a < chance+2)) || (a < chance-2) || (a > chance+5));

    sprintf (Enigma[5].answer1, "%.2f%%", a);
    strcpy (Enigma[5].answer2, "what ?");
    sprintf (Enigma[5].answer3, "%.2f%%", chance);
    Enigma[5].check = 3;
}

void Enigma7 (enigma Enigma[]) {
    ////////////////////
    //   Question 7   //
    ////////////////////
    // Combien de probabilite que la reponse n (entre 1 et 3) soit juste

    int n;
    float a, b, c;
    n = Random (1, 3);
    strcpy (Enigma[6].question, "Quel est la probabilite que");
    sprintf (Enigma[6].question2, "la reponse %d soit juste?", n);

    c = (5/6) * 100;
    do {
        a = RandomFloat (0, 100);
        b = RandomFloat (0, 100);
    } while ((a > c-10 && a < c+10) || (b > c-10 && b < c+10));
    sprintf (Enigma[6].answer1, "%.1f%%", a);
    sprintf (Enigma[6].answer2, "%.1f%%", b);
    sprintf (Enigma[6].answer3, "%.1f%%", c);

    Enigma[6].check = 3;
}

void Enigma8 (enigma Enigma[]) {
    ////////////////////
    //   Question 8   //
    ////////////////////
    // Est-ce que (random) = (random) ?

    int a, b, c;
    a = Random (-69, 69);
    b = Random (-69, 69);
    strcpy (Enigma[7].question, "Est-ce que");
    sprintf (Enigma[7].question2, "%d = %d ?", a, b);

    a = Random (0, 1);
    b = Random (0, 1);
    if (a) {
        strcpy (Enigma[7].answer1, "Perhaps");
    }
    else {
        strcpy (Enigma[7].answer1, "Yes");
    }
    if (b) {
        strcpy (Enigma[7].answer2, "Hmmmm");
    }
    else {
        strcpy (Enigma[7].answer2, "Perhaps");
    }

    if (a == b) {
        strcpy (Enigma[7].answer3, "Yes");
    }
    else {
        strcpy (Enigma[7].answer3, "No");
    }
    Enigma[7].check = 3;
}

void Enigma9 (enigma Enigma[]) {
    ////////////////////
    //   Question 9   //
    ////////////////////
    // Combien de patates recolte par secondes
    int n, a, b, c;
    n = Random (1, 420);
    sprintf (Enigma[8].question, "On a %d patates chaque seconde,", n);
    strcpy (Enigma[8].question2, "combien a-t-on de patates maintenant?");
    c = n * 5;
    do {
        a = n * Random (1, 15);
        b = n * Random (1, 15);
    } while ((a == c) || (b == c));
    sprintf (Enigma[8].answer1, "%d", a);
    sprintf (Enigma[8].answer2, "%d", b);
    sprintf (Enigma[8].answer3, "%d", c);

    Enigma[8].check = 3;
}

void Enigma10 (enigma Enigma[]) {
    ////////////////////
    //   Question 10  //
    ////////////////////
    // Quel etait la reponse de la question n ?
    // Cette question sera toujours la derniere

    int n, a, b, c;
    n = Random (1, 9);
    strcpy (Enigma[9].question, "Quel etait la bonne reponse");
    sprintf (Enigma[9].question2, "de la question %d ?", n);
    c = Enigma[n-1].check;
    do {
        a = Random (0, 3);
        b = Random (1, 3);
    } while ((a == c) || (b == c));
    sprintf (Enigma[9].answer1, "%d", a);
    sprintf (Enigma[9].answer2, "%d", b);
    sprintf (Enigma[9].answer3, "%d", c);
    Enigma[9].check = 3;
}
