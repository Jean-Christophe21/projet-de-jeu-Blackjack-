
#include <stdio.h>
#include <string.h>
#include <time.h>

#define N_CARDS 52

typedef struct {
    int number;  // De 1 à 13 pour les valeurs (As, 2, 3, ..., Roi)
    int color;  // De 0 à 3 pour les couleurs (Cœur, Carreau, Trèfle, Pique)
} Card;
typedef struct {
    char name[100];
    int nbr_cards;
}player;
// Fonction pour initialiser le jeu de cartes
void initialisation_card(Card cartes[]) {
    int index = 0;
    for (int color = 0; color < 4; color++) {
        for (int number = 1; number <= 13; number++) {
            cartes[index].number = number;
           cartes[index].color = color;
            index++;
        }
    }
}

// Fonction pour mélanger le jeu de cartes
//utilisation d'un algorithme de melange ,l'algorithme de Fisher-Yate
void algth_Fisher_Yate(Card cartes[]) {
    for (int i = N_CARDS - 1; i > 0; i--) {
        //rand() est une fonction qui genere un nombre entier aleatoire
        int j = rand() % (i + 1);
        Card temp = cartes[i];
        cartes[i] = cartes[j];
        cartes[j] = temp;
    }
}

// Fonction pour afficher une carte
void printCard(Card card) {
    const char* colors[] = {"Cœur", "Carreau", "Trèfle", "Pique"};
    const char* numbers[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    
    printf("%s %s\n", numbers[card.number - 1], colors[card.color]);
}

int main() {
    Card cartes[N_CARDS];
    char Nom_joueur[100];
    printf("\nBienvenue au jeu du Blackjack!\n");
    printf("Comment vous appelez-vous?\n");
    scanf("%s",Nom_joueur);
    player joueur;
    strcpy(joueur.name , Nom_joueur);
    printf("\nVotre adversaire sera le Croupier");
    printf("\n Pret pous Gagner,Let's go!\n");
    printf("\nPassont a la distribution des cartes. \nvous recevez deux cartes. \n");
    printf("\nMr vous aves les cartes visible:\n");
    for (int i = 0; i < 2; i++) {
        printCard(cartes[i]);
    }
    printf("\nEt le croupier aura une carte visible: ");
     for (int i = 0; i < 1; i++) {
        printCard(cartes[i]);
    }
    

    // Initialiser la génération de nombres aléatoires
    srand(time(NULL));
    
    // Initialiser et mélanger le jeu de cartes
    initialisation_card(cartes);
    algth_Fisher_Yate(cartes);
    
    // Afficher les cartes mélangées
  /* for (int i = 0; i < N_CARDS; i++) {
        printCard(cartes[i]);
    }*/
return 0;
}