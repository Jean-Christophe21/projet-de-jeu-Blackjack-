#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu_croupier.h"
#include "fonction_jeu_croupier.c"



int main()
{
    // déclaration des joueurs
    joueur mon_joueur ;
    croupier mon_croupier ;
    mon_croupier.carte_suivante = NULL ;
    // création de la liste des cartes
    list_card_jeu = creation_liste_carte() ;

    //  initialisation des cartes du joueur 
    mon_joueur.carte1 = distribution_une_seule_carte(list_card_jeu) ;
    mon_joueur.carte2 = distribution_une_seule_carte(list_card_jeu) ;

    //  initialisation des cartes du croupier
    mon_croupier.carte1 = distribution_une_seule_carte(list_card_jeu) ;
    mon_croupier.carte2 = distribution_une_seule_carte(list_card_jeu) ;

    printf("================================JEU BLACKJACK====================================\n");
    printf("\nVotre adversaire sera le Croupier");
    printf("\n Pret pour Gagner,Let's go!\n");
    printf("\nPassont a la distribution des cartes. \nvous recevez deux cartes. \n");
    printf("\nMr vous aves les cartes visible:\n");

    // affichage des cartes du joueur 
    affichage_des_cartes(mon_joueur.carte1) ;
    affichage_des_cartes(mon_joueur.carte2) ;
    printf("\nEt le croupier aura une carte visible:\n");
    affichage_des_cartes(mon_croupier.carte1) ;
    
   // appel de la fonction de gestion du comportement du croupier 
    comportement_croupier(&mon_croupier) ;   // passage par addresse nécéssaire pour modifier les champs de mon_croupier
    // affichage des cartes supplémentaire du croupier
    printf("voici les cartes supplémentaires du croupier :\n") ;
    carte_suppl *ptr1 = NULL , *ptr2 = NULL ;
    ptr1 = mon_croupier.carte_suivante ;
    if(ptr1 == NULL){
        printf("Le croupier n'a pas tiré de carte supplémentaire.\n") ;
    }
    else{
        while(ptr1 != NULL)
        {
            affichage_des_cartes(ptr1->carte) ;
            ptr1 = ptr1->next ;
        }
    }
    
    // libération des mémoires allouées
    libération_memoire(list_card_jeu) ;

    ptr1 = mon_croupier.carte_suivante ;
    while(ptr1 != NULL){
        ptr2 = ptr1 ;
        ptr1 = ptr1->next ;
        free(ptr2) ;
    }



    return 0 ;
}
