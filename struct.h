#ifndef HEADER_FILE
#define HEADER_FILE

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct realisateur
{
    string nom;
    string prenom;
    string date_de_naissance;
};

struct acteur
{
    string nom;
    string prenom;
    int date_de_naissance;

    // Ici un commentaire utile
};

struct film
{
     string titre;
     int annee;
     realisateur nomrealisateur;
     acteur noms[3];
     int duree;
     string genre;
};

#endif
