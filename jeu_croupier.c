#include <stdio.h>
#include <stdlib.h>
#include "jeu_croupier.h"

/// @brief cette fonction permet de récupérer la valeur d'une carte.
/// @param indice_card 
/// @return retourne la valeur de la carte qui est de 1 : as ; 2 à dix pour les cartes de numero 2 à 10  et  11, 12, 13 pour respectivement le valet la dame et le roi
int valeur_card(int indice_card)    
{
/*chaque carte dispose d'un indice : 
*/

    if (indice_card < 1 || indice_card > 14 )   return -1 ;  // aucun numero de carte ,ne doit-etre inf à 1 et sup à 14
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
}


card distribution_carte(liste_carte liste) 
{

}



























int main()
{
    
    return 0 ;
}