#include <stdio.h>
#include <stdlib.h>
#include "jeu_croupier.h"

tete list_card_jeu ;  // variable globale qui va nous permettre d'accéder a la liste


// fonction concernant les listes chainées
tete creation_liste_carte(void)
{
    liste_carte *elmt1 = NULL  ;
    tete pre_elmt ;
    elmt1 = (liste_carte*)malloc(sizeof(liste_carte)) ;
    pre_elmt.tete = elmt1 ;    
    int number = 0 , color = 0 ;
    for (color = 0; color <=3 ; color++) {
        for (number = 1; number <= 13; number++) {
            elmt1->carte.number = number;
            elmt1->carte.color = color;
            if(number == 13 && color == 3 )
            {
                elmt1->suivant = NULL ;
            } 
            else{
                elmt1->suivant = (liste_carte*)malloc(sizeof(liste_carte))  ;
                elmt1 = elmt1->suivant ;
            }
        }
    }
    return pre_elmt ;
}

/// @brief permet de libérer la mémoire allouée pour la liste des cartes
/// @param pre_elmt 
void libération_memoire(tete pre_elmt)
{
    liste_carte *ptr1 , *ptr ;
    ptr = pre_elmt.tete ;
    while(ptr != NULL)
    {
        ptr1 = ptr->suivant ;
        free(ptr) ;
        ptr = ptr1 ;
    }
}


// Fonctions concernant la gestion des cartes

/// @brief cette fonction permet de récupérer la valeur d'une carte.
/// @param indice_card 
/// @return retourne la valeur de la carte qui est de 1 : as ; 2 à dix pour les cartes de numero 2 à 10  et  11, 12, 13 pour respectivement le valet la dame et le roi
int valeur_card(int indice_card)    
{

    if (indice_card < 1 || indice_card > 14 )   return -1 ;  // controle de l'entrée pour qu'aucun numero de carte ,ne doit-etre inf à 1 et sup à 14
    else 
    {
        if(indice_card <= 10 )
        {
            return indice_card ;
        }
        else if(indice_card < 14 && indice_card > 10 )
        {
            return 10 ;
        } 
    }
    return -1 ;
}



/// @brief affecte une carte au joueur et la supprime de la liste des cartes
/// @param tete_list  ce parametre est la tete de la liste des cartes
/// @return retoure une carte
card distribution_une_seule_carte(tete tete_list ) 
{
    int taille_liste_carte = taille_liste(tete_list) ;
    srand(time(NULL)) ;
    card carte_choisie ;
    carte_choisie.number = 0 ;
    carte_choisie.color = 0 ;
    liste_carte *ptr = NULL, *ptr1 = NULL ;
    ptr = tete_list.tete  ;
    int nbr_aleatoire = rand() % taille_liste_carte + 1 ;
    for(int cpt = 1 ; cpt <= taille_liste_carte ; cpt++ )
    {
        if(cpt == nbr_aleatoire )
        {
            carte_choisie.color = ptr->carte.color ;
            carte_choisie.number = ptr->carte.number ;
            break;
        }
        else {
            ptr1 = ptr ;
            ptr = ptr->suivant ;
        }
    }
    // suppression de l'élément sélectionné dans la liste
    if(nbr_aleatoire == 1 ){  // permet de gérer la suppression du 1er élément de la liste
        tete_list.tete = ptr->suivant ;
        free(ptr) ;
    }
    else{
        ptr1->suivant = ptr->suivant ;    
        free(ptr) ;
    }

    if(nbr_aleatoire == taille_liste_carte){
        ptr1->suivant = NULL ;
    }
    

    return carte_choisie ; 
}


/// @brief  gère le comportement du croupier
/// @param  crou_pier 
/// @return void
void comportement_croupier(croupier *crou_pier)
{
    int val1 = 0 , val2 = 0 ;                                        // destiné a contenir les valeurs des cartes
    carte_suppl *ptr = NULL ;
    if(crou_pier->carte1.number == 1 || crou_pier->carte2.number == 1)   // calcul des valeurs des cartes au cas où il y aura un as dans les cartes du croupier
    {
        if(crou_pier->carte1.number == 1 )                         // si cette condition est vrai donc 
        {
            val1 = 1 + valeur_card(crou_pier->carte2.number) ;
            val2= 11 + valeur_card(crou_pier->carte2.number) ;
            if(val2 > 17 && val2 < 21 ){
                crou_pier->val = val2 ;
                return ;
            }
            else if(val1 > 17 && val1 < 21 ){
                crou_pier->val = val1 ;
                return ;
            }
            else    // permet d'affecter la bonne valeure à val1 
            {
                if(val2 > 21 ) val2 = val1 ;   // signifie que le joueur pert avec val2 donc val2 = val1 qui est inferieur à val1
                if (val2 < 17) val1 = val2 ;   // permet d'affecter a la valeur des cartes la plus proche de 17
            }
        }
        else if(crou_pier->carte2.number == 1 ){     // gestion du cas où la carte supplémentaire sz=era un as
            val1 = 1 + valeur_card(crou_pier->carte1.number) ;
            val2= 11 + valeur_card(crou_pier->carte1.number) ;
            if(val2 > 17 && val2 < 21 ){
                crou_pier->val = val2 ;
                return ;
            }
            else if(val1 > 17 && val1 < 21 ){
                crou_pier->val = val1 ;
                return ;
            }
            else    // permet d'affecter la bonne valeure à val1 
            {
                if(val2 > 21 ) val2 = val1 ;   // signifie que le joueur pert avec val2 donc val2 = val1 qui est inferieur à val1
                if (val2 < 17) val1 = val2 ;   // permet d'affecter a la valeur des cartes la plus proche de 17
            }
        }
        else if(((crou_pier->carte2.number)) == 1 && ((crou_pier->carte2.number) == 1)){
            val1 = 12 ;        // 12 est la valeur la plus avantageuse pour le joueur plutot que 22 et 2 
        }
        
        if(val1 < 17){
            ptr = (carte_suppl*)malloc(sizeof(carte_suppl)) ;
                crou_pier->carte_suivante = ptr ;    
                while (val1 < 17)
                {
                    ptr->next = NULL ;
                    ptr->carte = distribution_une_seule_carte(list_card_jeu) ;

                    if(ptr->carte.number == 1 )
                    {
                        val2 = val1 ;
                        val1 += 11  ;
                        val2 += 1 ;
                        
                            if(val1 > 21)
                            {
                                val1 = val2 ;
                            }
    
                    }
                    else val1 += valeur_card(ptr->carte.number) ; 

                    if(val1 < 17){
                        ptr->next = (carte_suppl*)malloc(sizeof(carte_suppl)) ;
                        ptr = ptr->next ;
                    }
                    else {
                        ptr->next = NULL ;
                    }
                }
                crou_pier->val = val1 ;
                
            }    
        else crou_pier->val = val1 ;
     

    }
    else     //   permet de calculer la valeur des cartes si elles ne contiennent pas l'as (carte de numero 1)
    {
        val1 =valeur_card(crou_pier->carte1.number) + valeur_card(crou_pier->carte2.number) ;
        if(val1 < 17){
                ptr = (carte_suppl*)malloc(sizeof(carte_suppl)) ;
                crou_pier->carte_suivante = ptr ;
                while (val1 < 17)
                {
                    ptr->next = NULL ;
                    ptr->carte = distribution_une_seule_carte(list_card_jeu) ;

                    if(ptr->carte.number == 1 )
                    {
                        val2 = val1 ;
                        val1 += 11  ;
                        val2 += 1 ;
                        
                            if(val1 > 21)
                            {
                                val1 = val2 ;
                            }
    
                    }
                    else val1 += valeur_card(ptr->carte.number) ;

                    if(val1<17){
                        ptr->next = (carte_suppl*)malloc(sizeof(carte_suppl)) ;
                        ptr = ptr->next ;
                    }
                    else {
                        ptr->next = NULL ;
                    }
                }
                crou_pier->val = val1 ;
                
            }
        else crou_pier->val = val1 ;
    
    }
}


/// @brief permet l'affichage des noms des cartes suivant leur numero
/// @param carte_a_afficher 
void affichage_des_cartes(card carte_a_afficher)
{
    card carte = carte_a_afficher ;
    if( carte.number>1 && carte.number <= 10 ){
        printf("\t%d de ",carte.number ) ;
    }
    else{
        switch(carte.number){
            case(1) :
                printf("\tAs de ") ;
                break;
            case(11) : 
                printf("\tValet de ") ;
                break;
            case(12) : 
                printf("\tDame de ") ;
                break;
            case(13) : 
                printf("\tRoi de ") ;
                break;
        }
    }
    
    switch(carte.color){
        case(0) : 
                printf("Coeur\n") ;
                break;
        case(1) : 
                printf("Carreau\n") ;
                break;
        case(2) : 
                printf("Trefle\n") ;
                break;
        case(3) : 
                printf("Pique\n") ;
                break;
    }
}


/// @brief permet de déterminer la taille de la liste des cartes
/// @param liste 
/// @return retourne la taille de la liste
int taille_liste(tete liste)
{
    liste_carte *elmt = liste.tete ;
    int cpt = 0 ;
    if(elmt != NULL){
        while(elmt != NULL){
            cpt++ ;
            elmt = elmt->suivant ;
        }
    return cpt;
    }
    else return cpt ; 
}
