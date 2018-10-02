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
     vector<acteur> noms;
     int duree;
     string genre;
};

void add_acteur(acteur a, film &f);
film create_film(string _titre, int _annee, realisateur _nomrealisateur, int _duree, string _genre);
film stocker_film(string film[6]);
int lecture(vector<film> ListeFilms);
realisateur create_realisateur(string _nom, string _prenom, int _date_de_naissance);
acteur create_acteur(string _nom, string _prenom, int _date_de_naissance);
realisateur create_realisateur(string _nom, string _prenom, int _date_de_naissance);

#endif
