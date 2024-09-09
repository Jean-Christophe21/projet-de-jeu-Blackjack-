#ifndef __JEU_CROUPIER__
#define __JEU_CROUPIER__

typedef struct Card {
    int number;  // De 1 à 13 pour les valeurs (As, 2, 3, ..., Roi)
    int color;  // De 0 à 3 pour les couleurs (Cœur, Carreau, Trèfle, Pique)
} card;
typedef struct {
    char name[100] ;
    int nbr_cards[2]  ;
}player;

typedef struct Liste_carte
{
    card carte ;
    liste_carte* suivant = NULL ;
}liste_carte;

typedef struct{
    liste_carte * tete = NULL;
} tete ;

tete pre_elmt ;

int valeur_card(int indice_card) ;

card distribution_carte(liste_carte liste) ;

#endif