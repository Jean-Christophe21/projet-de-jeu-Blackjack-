







I.Explication du jeu 
But du jeu :
Le but du Blackjack est d'obtenir un total de points aussi proche que possible de 21 sans le dépasser. Si le total des points du joueur dépasse 21, il perd la partie. Le joueur joue contre le croupier (la maison), et le gagnant est celui qui obtient un total de points plus élevé sans dépasser 21.
Matériel :
Un jeu standard de 52 cartes.
Déroulement du jeu :
1.Distribution des cartes :
Le jeu démarre avec le croupier et le joueur.
Chaque joueur reçoit deux cartes face visible, tandis que le croupier reçoit une carte face visible et une carte face cachée.
2.Tour du joueur :
Le joueur peut choisir parmi plusieurs options :
Hit : Demander une carte supplémentaire pour améliorer son total de points.
Stand : Rester avec son total actuel et passer au tour suivant.
Double Down : Doubler sa mise initiale et recevoir exactement une carte supplémentaire.
Split : Si les deux cartes initiales du joueur sont de même valeur, diviser la paire pour jouer deux mains distinctes.
Le joueur peut tirer des cartes supplémentaires (hit) autant de fois qu'il le souhaite, mais il perd automatiquement si son total de points dépasse 21.
3.Tour du croupier :
Une fois que tous les joueurs ont joué, c'est au tour du croupier.
Le croupier doit tirer des cartes supplémentaires jusqu'à ce que son total de points soit au moins de 17.
Si le total de points du croupier dépasse 21, tous les joueurs restants gagnent automatiquement.
4.Détermination du gagnant :
Une fois que le croupier a terminé de jouer, les totaux de points des joueurs et du croupier sont comparés.
Le joueur gagne si son total de points est plus élevé que celui du croupier sans dépasser 21.
Si le total de points du joueur est égal à celui du croupier, c'est un match nul (push).
Si le joueur dépasse 21 ou si le croupier a un total de points plus élevé, le joueur perd sa mise.
Principes importants :
As : Les As peuvent valoir 1 ou 11 points, selon ce qui est le plus avantageux pour le joueur.
Cartes numériques : Les cartes numériques (2 à 10) valent leur valeur nominale.
Cartes face : Les cartes face (valet, dame, roi) valent chacune 10 points.
Objectif :
Le joueur tente de battre le croupier en obtenant un total de points plus élevé sans dépasser 21, en utilisant les options de jeu disponibles de manière stratégique.
C'est un jeu qui combine la chance et la stratégie, ce qui en fait un choix populaire dans les casinos et un défi intéressant pour les joueurs de tous niveaux.

II.Pose du problème
Problème : Vous devez créer un programme en langage C qui permet de jouer au Blackjack. Le Blackjack est un jeu de cartes où le joueur doit atteindre un score le plus proche possible de 21 sans le dépasser. Dans ce jeu, les cartes sont représentées par des nombres de 1 à 10, et les cartes "10", "Valet", "Dame" et "Roi" valent chacune 10 points.
Le programme doit implémenter les règles suivantes :
1.Le jeu se joue avec un joueur contre l'ordinateur (croupier).
2.Le joueur et le croupier reçoivent chacun deux cartes au début du jeu.
3.Le joueur peut choisir de "tirer" une carte supplémentaire ou de "rester" avec ses cartes actuelles.
4.Si le joueur dépasse 21 points, il perd automatiquement la partie.
5.Le croupier doit tirer des cartes supplémentaires tant que son total est inférieur à 17 points.
6.Si le croupier dépasse 21 points, le joueur gagne automatiquement la partie.
7.Si ni le joueur ni le croupier ne dépasse 21 points, celui avec le score le plus élevé gagne.
Le programme doit afficher les résultats de chaque tour, le score du joueur et du croupier, et permettre au joueur de décider s'il veut tirer une nouvelle carte ou rester à tout moment.
Le programme sera divisé en 4 parties pour résoudre ce problème complexes.

III.Explication du programme
But du jeu :
Le but du Blackjack est d'obtenir un total de points aussi proche que possible de 21 sans le dépasser. Si le total des points du joueur dépasse 21, il perd la partie. Le joueur doit donc décider de tirer des cartes supplémentaires pour s'approcher de 21 ou de rester avec son total actuel. Le croupier est l’ordinateur.
Déroulement du jeu :
1.Initialisation du jeu :
Un jeu standard de 52 cartes est utilisé.
Le jeu démarre avec le croupier et le joueur.
Chaque joueur reçoit deux cartes face visible, tandis que seul une des cartes du croupier est visible.
2.Jeu du croupier :
Le croupier suit des règles prédéfinies pour jouer. Habituellement, il doit tirer des cartes supplémentaires jusqu'à ce qu'il atteigne un total de 17 ou plus.
3.Jeu du joueur :
Le joueur décide s'il veut tirer une carte supplémentaire (appelé "hit") pour améliorer son total ou rester avec son total actuel (appelé "stand").
Si le joueur dépasse 21 points après avoir tiré une carte supplémentaire, il perd automatiquement la partie.
4.Détermination du gagnant :
Une fois que le joueur a décidé de rester, le croupier révèle sa deuxième carte.
Le joueur et le croupier comparent alors leurs totaux de points.
Le joueur avec le total de points le plus proche de 21 sans le dépasser remporte la partie. Si le joueur et le croupier ont le même total, c'est un match nul.
Fonctionnement du programme :
Le programme que j'ai proposé est une implémentation simplifiée de ce jeu. Il est divisé en quatre parties principales :
1.Initialisation du jeu : Cette partie prépare le jeu en créant un paquet de cartes et en le mélangeant. Elle définit également les structures de données nécessaires pour représenter les cartes et les joueurs.
2.Jeu du croupier : Cette partie gère le comportement du croupier, y compris la distribution initiale des cartes et les décisions de jeu du croupier.
3.Jeu du joueur : Cette partie gère le comportement du joueur, y compris la décision de tirer ou de rester.
4.Résultat du jeu : Cette partie détermine le gagnant du jeu et affiche les résultats à l'écran.
Chaque partie du programme est conçue pour être réalisée par un membre différent de l'équipe, puis les parties individuelles sont intégrées pour former le jeu complet.
IV.La part de chacun
Chaque membre de l'équipe sera responsable de l'implémentation d'une partie spécifique du programme, et une fois les parties individuelles terminées, elles seront intégrées pour former le programme complet.
Partie 1 : Initialisation du jeu (Gervaise)
Cette partie initialise le jeu en créant un jeu de cartes et en les mélangeant.
Elle définit également les structures de données nécessaires pour représenter les cartes et les joueurs.
Partie 2 : Jeu du croupier (Jean Christophe)
Cette partie gère le comportement du croupier, y compris la distribution initiale des cartes et les décisions de jeu du croupier.
Partie 3 : Jeu du joueur (Samuel)
Cette partie gère le comportement du joueur, y compris la décision de tirer ou de rester.
Partie 4 : Résultat du jeu (Félicité)
Cette partie détermine le gagnant du jeu et affiche les résultats.