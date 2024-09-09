#include <stdio.h>
#include <stdlib.h>
#include "jeu_croupier.h"

int initialisation_card(Card cartes[]) {
    int index = 0;
    for (int color = 0; color < 4; color++) {
        for (int number = 1; number <= 13; number++) {
            cartes[index].number = number;
           cartes[index].color = color;
            index++;
        }
    }
}


void intitialisation_liste_carte(void)
{
    liste_carte *elmt1 = NULL , *elmt2 = NULL ;
    elmt1 = (*card)malloc(sizeof(card)) ;
    elmt2 = (*card)malloc(sizeof(card)) ;
    pre_elmt.tete = elmt1 ;
    int taille = 13 ;
    
}