#include "struct.h"


film create_film(string _titre, int _annee, realisateur _nomrealisateur, int _duree, string _genre)
{
    // init var
    film newfilm;

    // init des variables en arguments
    newfilm.titre = _titre;
    newfilm.annee = _annee;
    newfilm.nomrealisateur = _nomrealisateur;
    newfilm.genre = _genre;
    newfilm.duree = _duree;

    // return la valeur
    return newfilm;
}

void add_acteur(acteur a, film &f)
{
    f.noms.push_back(a);
}

acteur create_acteur(string _nom, string _prenom, int _date_de_naissance)
{
    // init var
    acteur newacteur;

    // init des variables en arguments
    newacteur.nom = _nom;
    newacteur.date_de_naissance = _date_de_naissance;
    newacteur.prenom = _prenom;

    return newacteur;
}

realisateur create_realisateur(string _nom, string _prenom, int _date_de_naissance)
{

    realisateur newrealisateur;

    newrealisateur.nom = _nom;
    newrealisateur.date_de_naissance = _date_de_naissance;
    newrealisateur.prenom = _prenom;

    return newrealisateur;
}

void print_film_list(vector<film> ListeFilms)
{
    for (unsigned int i = 0; i<ListeFilms.size(); i++)
    {
        cout << i+1 << ") " << ListeFilms[i].titre << endl;
    }

}

void afficher_infos_acteur(acteur acteuraverif)
{
    cout << acteuraverif.nom << " " << acteuraverif.prenom << " ne en " << acteuraverif.date_de_naissance << endl;
}

void afficher_infos_film(film filmaverif)
{
    cout << endl << "Informations sur le film: " << endl ;
    cout << "Titre: " << filmaverif.titre << endl;
    cout << "Annee: " << filmaverif.annee << endl;
    cout << "Duree: " << filmaverif.duree << " minutes" << endl;
    cout << "Genre: " << filmaverif.genre << endl;
    cout << "Acteurs: " << endl;
    for (unsigned int i = 0; i < filmaverif.noms.size(); i++) // Depend du nombre d'acteurs dans le film
    {
        afficher_infos_acteur(filmaverif.noms[i]);
    }
}

void recherche_films_par_titre(string choix, vector<film> ListeFilms)
{
    for (unsigned int i = 0; i < ListeFilms.size(); i++)
    {
        if (ListeFilms[i].titre.find(choix) != string::npos)
        {
            afficher_infos_film(ListeFilms[i]);
        } else {
            cout << "Ce film n'est pas a l'affiche !" << endl;
        }
    }
}

void recherche_films_par_personne(string a1, vector<film> ListeFilms)
{
    for (unsigned int i = 0; i < ListeFilms.size(); i++)
    {
       for (unsigned int j = 0; j < ListeFilms[i].noms.size() ; j++) // Depend du nombre d'acteurs dans le film
       {
            if (ListeFilms[i].noms[j].nom.find(a1) != string::npos || ListeFilms[i].noms[j].prenom.find(a1) != string::npos)
            {
                cout << "Dans le film " << ListeFilms[i].titre<< " en tant qu'acteur" << endl;
            }
       }

        // Qu'un seul réalisateur
        if (ListeFilms[i].nomrealisateur.nom.find(a1) != string::npos || ListeFilms[i].nomrealisateur.prenom.find(a1) != string::npos)
        {
            cout << "Dans le film " << ListeFilms[i].titre<< " en tant que realisateur" << endl;
        }
    }
}

void menu_cinema(vector<film> ListeFilms)
{


    int choix_recherche;
    string choix;
    cout << "-- Cinema - Database --" << endl;

     do {
        cout << endl;
        cout << "1) Recherche de film par titre" << endl;
        cout << "2) Recherche de film par nom de l'acteur" << endl << endl;

        do {
        cout << "Votre choix: " ;
        cin >> choix_recherche;
        }while(choix_recherche <1 || choix_recherche >2); // On evite les erreurs de saisie

        cout << "Votre recherche: ";
        cin >> choix;

        switch(choix_recherche)
        {
            case 1: recherche_films_par_titre(choix, ListeFilms);
            break;
            case 2: recherche_films_par_personne(choix,ListeFilms);
            break;
            default: return;
        }

    }while(1); // Ce menu se relance sans cesse
}

int main()
{
    string genres[8] = {"Action","Horreur","Comedie","Documentaire","Policier","Drame","Animation","Science-fiction"};
    vector<film> ListeFilms;

    // Ajout du film "Le pianiste"
    realisateur Polanski = create_realisateur("Polanski","Roman",1939);

    acteur Brody = create_acteur("Brody","Adrian",1973);
    acteur Kretschmann = create_acteur("Kretschmann","Kretschmann",1962);
    acteur Fox = create_acteur("Fox","Emilia",1974);

    film LePianiste = create_film("Le Pianiste",2002,Polanski,140,genres[5]);
    add_acteur(Brody,LePianiste);
    add_acteur(Kretschmann,LePianiste);
    add_acteur(Fox,LePianiste);
    ListeFilms.push_back(LePianiste);

    menu_cinema(ListeFilms);
}
