#include <stdio.h>
#include <math.h>
float a, a1, b, b1, c, c1;
float AB, AC, BC, O;
float carre(float a)
{
    return a * a;
}

int main(void)
{
    printf("Entrez les coordonnées de vos 3 points\n");
    scanf("(%f,%f),(%f,%f),(%f,%f)", &a, &a1, &b, &b1, &c, &c1);
    printf("Considérons les points :\n");
    printf("A(%f,%f) B(%f,%f) C(%f,%f)\n", a, a1, b, b1, c, c1);
    AB = sqrt(carre(b - a) + carre(b1 - a1));
    AC = sqrt(carre(c - a) + carre(c1 - a1));
    printf("Le triangle ABC est tel que :\n|AB|=%f et |AC|=%f\n Cherchons |BC|\n", AB, AC);
    O = (a * b + a1 * b1) / (AB * AC);
    BC = sqrt(carre(AB) + carre(AC) - 2 * AB * AC * O);
    printf("D'après Chasles, on a:\n BC=BA+AC => BC=AC-AB\n");
    printf("d'où\n BC²=AB²+AC²-2AB×AC×cos(AB,AC)\n Par ailleurs\n");
    printf("BC=√[AB²+AC²-2AB×AC×cosO] avec O=(AB,AC)\n Cherchons l'angle O\n");
    printf("on a:\n (AB.AC)=|AB|×|AC|×cosO <=> a×b+a1×b1=|AB|×|AC|×cosO donc\n cosO=(a×b+a1×b1)/(|AB|×|AC|).\nAN:\ncosO=(%f*%f+%f*%f)/(%f*%f)=%f\n",
           a, b, a1, b1, AB, AC, O);
    printf("Ainsi en application numérique,\n");
    printf("BC=√[%f²+%f²-2*%f*%f*%f]=%f\n", AB, AC, AB, AC, O, BC);

    return 0;
}