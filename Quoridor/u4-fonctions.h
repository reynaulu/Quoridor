// u4-fonctions.h
// Sentinelle d'inclusion
#ifndef _u4_fonctions_h
#define _u4_fonctions_h

// Definition des constantes
#define DUREE_CYCLE 0.015    // 0.500 secondes, depend du materiel utilise
#define RAYON_BOULE  20

//Declaration des enum

enum TYPECASE{BARRIERE = 0, PION = 1};
enum TYPEJOUEUR{HUMAIN = 0, ORDI = 1};
enum COULEUR{BLANC = 0, NOIR = 1};


// Declaration des donnees du projet

// Structure de definition d'une case de damier
struct Case
{
    enum TYPECASE Type;
    bool Occupe;
    enum COULEUR Pion;
} ;

//Structure de définition d'un joueur
struct Joueur
{
    int Ligne; //Ligne actuelle du pion jour
    int Colonne; //Colonne actuelle du pion joueur
    char image_pion[100]; //chargement fichier image pion
    enum TYPEJOUEUR Type;
    int NbBarrieres; //Nombre de barrières restant au joueur
    int Chemin[TAILLEMAX][2] //Stockage du chemin optimal a parcourir
    int NbCasesChemin; //Nb de cases du chemin le plus court
    bool CheminTrouve; //Verification si chemin valide (n'enferme pas le pion)
};

// Structure globale pour les variables fonctionnelles
struct Donnees
{
    struct Case Plateau[2N-1][2N-1];
    struct Joueur JoueurBlanc;
    struct Joueur JoueurNoir;

    enum COULEUR JoueurEnCours;
};



extern struct Donnees gDonnees;

// Déclaration des sous-programmes
void InitialiserDonnees() ;
void DeplacerBouleSansRebond() ;

// Utilitaires
void JouerSon(char *) ;         // Jouer un son
void Attente(double Seconds);   // Procedure d'attente

#endif // _u4_fonctions_h
