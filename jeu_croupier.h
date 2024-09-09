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
    struct Liste_carte *suivant  ;
}liste_carte;

typedef struct{
    liste_carte * tete ;
} tete ;

typedef struct Joueur{
    card carte1 ;
    card carte2 ;
} joueur ;

typedef struct Croupier{
    card carte1 ;
    card carte2 ;
    struct Carte_suppl * carte_suivante ;   // permet de stocker les autres cartes au cas où le croupier aura a en tirer
    int val ;
}croupier ;   

typedef struct Carte_suppl{
    card carte ;
    struct Carte_suppl *next ;
} carte_suppl ;


int valeur_card(int indice_card) ;

tete creation_liste_carte(void) ;

void libération_memoire(tete pre_elmt);

card distribution_une_seule_carte(tete tete_list ) ;

void comportement_croupier(croupier *crou_pier);

void affichage_des_cartes(card carte) ;

int taille_liste(tete liste) ;

#endif