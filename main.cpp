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

acteur find_acteur(string input,vector<acteur> listeActeurs)
{
    for (unsigned i = 0; i< listeActeurs.size(); i++)
    {
        if (listeActeurs[i].nom.find(input) != string::npos)
        {
            return listeActeurs[i];
        }

        if (listeActeurs[i].prenom.find(input) != string::npos)
        {
            return listeActeurs[i];
        }
    }
    cout << "ACTOR NOT FOUND" << endl;
    return create_acteur("Inconnu","Inconnu",0000);
}

realisateur find_realisateur(string input,vector<realisateur> listeRealisateurs)
{
    for (unsigned i = 0; i< listeRealisateurs.size(); i++)
    {
        if (listeRealisateurs[i].nom.find(input) != string::npos)
        {
            return listeRealisateurs[i];
        }

        if (listeRealisateurs[i].prenom.find(input) != string::npos)
        {
            return listeRealisateurs[i];
        }
    }
    cout << "REALISATOR NOT FOUND" << endl;
    return create_realisateur("Inconnu","Inconnu",0000);
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

bool genre_existe(string choix,string genres[8])
{
    for (unsigned int i = 0; i < 8; i++)
    {
        if (choix == genres[i])
            return true;
    }
    return false;
}

bool realisateur_existe(string choix, vector<realisateur> ListeRealisateurs)
{
    for (unsigned int i = 0; i < ListeRealisateurs.size(); i++)
    {
        if (choix == ListeRealisateurs[i].nom)
        {
            return true;
        }
        if (choix == ListeRealisateurs[i].prenom)
        {
            return true;
        }
    }
    return false;
}

bool acteur_existe(string choix, vector<acteur> ListeActeurs)
{
    for (unsigned int i = 0; i < ListeActeurs.size(); i++)
    {
        if (choix == ListeActeurs[i].nom)
        {
            return true;
        }
        if (choix == ListeActeurs[i].prenom)
        {
            return true;
        }
    }
    return false;
}

realisateur create_manually_realisator()
{
    realisateur newrealisateur;
    cout << endl << "Nom: ";
    cin >> newrealisateur.nom;
    cout << "Prenom: ";
    cin >> newrealisateur.prenom;
    cout << "Date de naissance: ";
    cin >> newrealisateur.date_de_naissance;

    return newrealisateur;
}

acteur create_manually_actor()
{
    acteur newacteur;
    cout << endl << "Nom: ";
    cin >> newacteur.nom;
    cout << "Prenom: ";
    cin >> newacteur.prenom;
    cout << "Date de naissance: ";
    cin >> newacteur.date_de_naissance;

    return newacteur;
}

realisateur choose_realisateur_to_add(vector<realisateur> ListeRealisateurs)
{
    string choix;
    cout << endl;
    for (unsigned int i = 0; i < ListeRealisateurs.size(); i++)
    {
        cout << ListeRealisateurs[i].nom << " "<< ListeRealisateurs[i].prenom << " - ";
    }
    do {
        cin >> choix;
    }while(!realisateur_existe(choix,ListeRealisateurs)); // while le genre existe

    for (unsigned int i = 0; i < ListeRealisateurs.size(); i++)
    {
        if (choix == ListeRealisateurs[i].nom)
        {
            return ListeRealisateurs[i];
        }
        if (choix == ListeRealisateurs[i].prenom)
        {
            return ListeRealisateurs[i];
        }
    }
    return create_realisateur("inconnu","inconnu",0000);
}

acteur choose_actor_to_add(vector<acteur> ListeActeurs)
{
    string choix;
    cout << endl;
    for (unsigned int i = 0; i < ListeActeurs.size(); i++)
    {
        cout << ListeActeurs[i].nom << " "<< ListeActeurs[i].prenom << " - ";
    }
    do {
        cin >> choix;
    }while(!acteur_existe(choix,ListeActeurs)); // while le genre existe

    for (unsigned int i = 0; i < ListeActeurs.size(); i++)
    {
        if (choix == ListeActeurs[i].nom)
        {
            return ListeActeurs[i];
        }
        if (choix == ListeActeurs[i].prenom)
        {
            return ListeActeurs[i];
        }
    }
    return create_acteur("inconnu","inconnu",0000);
}

string choose_genre(string genres[8])
{
    string choix;
    cout << endl;
    for (unsigned int i = 0; i < 8; i++)
    {
        cout << " - " <<genres[i];
    }
    cout << endl << "Votre choix: ";
    do {
        cin >> choix;
    }while(!genre_existe(choix,genres)); // while le genre existe

    return choix;

}

acteur user_add_actor(vector<acteur> ListeActeurs)
{
    int choix;
    cout << endl << "-- AJOUT ACTEUR --" << endl;
    cout << "1) Ajout acteur depuis BDD" << endl;
    cout << "2) Ajout acteur manuellement" << endl;

    do{
        cin >> choix;
    }while(choix > 3 || choix < 1);

    switch(choix)
    {
        case 1: return choose_actor_to_add(ListeActeurs);
        break;
        case 2: return create_manually_actor();
        break;
        default: return create_manually_actor();
    }
}

realisateur user_add_realisator(vector<realisateur> ListeRealisateurs)
{
    int choix;
    cout << endl << "-- AJOUT REALISATEUR --" << endl;
    cout << "1) Ajout realisateur depuis BDD" << endl;
    cout << "2) Ajout realisateur manuellement" << endl;

    do{
        cin >> choix;
    }while(choix > 3 ||choix < 1);

    switch(choix)
    {
        case 1: return choose_realisateur_to_add(ListeRealisateurs);
        break;
        case 2: return create_manually_realisator();
        break;
        default: return create_manually_realisator();
    }
}

void user_add_film(vector<film> &Listefilms, vector<acteur> &ListeActeurs, vector<realisateur> &ListeRealisateurs, string genres[8])
{
    film newfilm;
    cout << "-- MODE CREATION --" << endl;
    cout << "Titre du film: ";
    cin >> newfilm.titre;
    cout << "Genre du film: ";
    newfilm.genre = choose_genre(genres);
    cout << "Annee du film: ";
    cin >> newfilm.annee;
    cout << "Duree du film (en minutes): ";
    cin >> newfilm.duree;
    cout << "Realisateur: ";
    newfilm.nomrealisateur = user_add_realisator(ListeRealisateurs);
    cout << "Acteur: ";
    newfilm.noms.push_back(user_add_actor(ListeActeurs));

    Listefilms.push_back(newfilm);
}


void menu_cinema(vector<film> &Listefilms, vector<acteur> &ListeActeurs, vector<realisateur> &ListeRealisateurs, string genres[8])
{


    int choix_recherche;
    string choix;
    cout << "-- Cinema - Database --" << endl;

     do {
        cout << endl;
        cout << "1) Recherche de film par titre" << endl;
        cout << "2) Recherche de film par nom de l'acteur" << endl;
        cout << "3) Ajout d'un nouveau film" << endl << endl;

        do {
        cout << "Votre choix: " ;
        cin >> choix_recherche;
        }while(choix_recherche <1 || choix_recherche >3); // On evite les erreurs de saisie

        if (choix_recherche == 1 || choix_recherche == 2)
        {
            cout << "Votre recherche: ";
            cin >> choix;
        }

        switch(choix_recherche)
        {
            case 1: recherche_films_par_titre(choix, Listefilms);
            break;
            case 2: recherche_films_par_personne(choix,Listefilms);
            break;
            case 3: user_add_film(Listefilms,ListeActeurs,ListeRealisateurs,genres);
            break;
            default: return;
        }

    }while(1); // Ce menu se relance sans cesse
}

int main()
{
    string genres[8] = {"Action","Horreur","Comedie","Documentaire","Policier","Drame","Animation","Science-fiction"};
    vector<film> ListeFilms;
    vector<acteur> ListeActeurs;
    vector<realisateur> ListeRealisateurs;

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

    menu_cinema(ListeFilms,ListeActeurs,ListeRealisateurs,genres);
}
