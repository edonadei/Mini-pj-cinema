#include <iostream>
#include <vector>

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

film create_film(string _titre, int _annee, realisateur _nomrealisateur, int _duree, string _genre, acteur _acteur1, acteur _acteur2, acteur _acteur3)
{
    // init var
    film newfilm;

    // init des variables en arguments
    newfilm.titre = _titre;
    newfilm.annee = _annee;
    newfilm.nomrealisateur = _nomrealisateur;
    newfilm.genre = _genre;
    newfilm.duree = _duree;
    newfilm.noms[0] = _acteur1;
    newfilm.noms[1] = _acteur1;
    newfilm.noms[2] = _acteur3;

    // return la valeur
    return newfilm;
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

void afficher_infos_film(film filmaverif)
{
    cout << "Informations sur le film: " << endl ;
    cout << "Titre: " << filmaverif.titre << endl;
    cout << "Annee: " << filmaverif.annee << endl;
    cout << "Duree: " << filmaverif.duree << endl;
    cout << "Genre: " << filmaverif.genre << endl;
    // Ici on gere affichage acteur
}

void menu_cinema(vector<film> ListeFilms)
{
    print_film_list(ListeFilms);
    string choix;
    cout << "Choisissez le titre du film voulu: ";
    cin >> choix;

    for (unsigned int i = 0; i < ListeFilms.size(); i++)
    {
        if (ListeFilms[i].titre == choix)
        {
            afficher_infos_film(ListeFilms[i]);
        } else {
            cout << "Ce film n'est pas a l'affiche !" << endl;
        }
    }
}

int main()
{
    string genres[8] = {"Action","Horreur","Comédie","Documentaire","Policier","Drame","Animation","Science-fiction"};
    vector<film> ListeFilms;

    // Ajout du film "Le pianiste"
    realisateur Polanski = create_realisateur("Polanski","Roman",1939);

    acteur Brody = create_acteur("Brody","Adrian",1973);
    acteur Kretschmann = create_acteur("Kretschmann","Kretschmann",1962);
    acteur Fox = create_acteur("Fox","Emilia",1974);

    film LePianiste = create_film("Le Pianiste",2002,Polanski,140,genres[5],Brody,Kretschmann,Fox);
    ListeFilms.push_back(LePianiste);

    menu_cinema(ListeFilms);
}
