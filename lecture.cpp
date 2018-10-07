#include "struct.h"


string take_nom(string all)
{
	string nom;
	int i = 0;
	int j = 0;
	while (all[i] != ' ')
	{
		i++;
	}
	i++;
	while (i != all.length() && all[i] != ' ')
	{
		nom += all[i];
		i++;
		j++;
	}
	return nom;
}

int take_date(string all)
{
	string mot;
	int i = 0;
	int j = 0;
	while (all[i] != ' ')
	{
		i++;
	}
	i++;
	while (all[i] != ' ')
	{
		i++;
	}
	while (i < all.length())
	{
		mot += all[i];
		j++;
		i++;
	}
	return atoi(mot.c_str());
}

string take_prenom(string all)
{
	string prenom;
	int i =0;
	while (all[i] != ' ')
	{
		prenom += all[i];
		i++;
	}
	return prenom;
}

int lecture(vector<film> &ListeFilms,vector<acteur> &ListeActeurs,vector<realisateur> &ListeRealisateurs)
{
	int i;
	ifstream fichier("films.txt", ios::in);
	if (fichier)
	{
		string line;
	  string movie[6];
		i = 0;
		while(getline(fichier,line))
		{
			movie[i] = line;
			i++;
			if (i == 6)
			{
				i = 0;
				ListeFilms.push_back(stocker_film(movie,ListeActeurs,ListeRealisateurs));
				getline(fichier,line);

			}
			
		}

		fichier.close();
	}
	else
	{
		cerr << "Erreur à l'ouverture de films.txt" << endl;
		return 1;
	}
	return 0;
}


film stocker_film(string tempfilm[6],vector<acteur> &ListeActeurs,vector<realisateur> &ListeRealisateurs)
{
  int j = 0;
	int k = 0;
	string acteurs[4];
	for (unsigned i = 0; i < tempfilm[3].length(); i++)
	{
		if (tempfilm[3][i] == ',')
		{
			j++;
			k=0;
		}
		else
		{
			acteurs[j] += tempfilm[3][i];
		}
		k++;
	}
	realisateur nouv_realisateur = find_realisateur(take_nom(tempfilm[2]),ListeRealisateurs);
    film newfilm = create_film(tempfilm[0],atoi(tempfilm[1].c_str()),nouv_realisateur,atoi(tempfilm[4].c_str()),tempfilm[5]);
	add_acteur(find_acteur(take_nom(acteurs[0]),ListeActeurs),newfilm);
	add_acteur(find_acteur(take_nom(acteurs[1]),ListeActeurs),newfilm);
	add_acteur(find_acteur(take_nom(acteurs[2]),ListeActeurs),newfilm);
	if (acteurs[3].length() != 0)
	{
		add_acteur(find_acteur(take_nom(acteurs[3]),ListeActeurs),newfilm);
	}
	return newfilm;
}

int lecture_acteurs(vector<acteur> &ListeActeurs)
{
	int i;
	ifstream fichier("acteurs.txt", ios::in);
	if (fichier)
	{
		string line;
		while(getline(fichier,line))
		{
			acteur nouv = create_acteur(take_nom(line),take_prenom(line),take_date(line));
    	ListeActeurs.push_back(nouv);
		}
  fichier.close();
	}
	else
	{
		cerr << "Erreur à l'ouverture de acteurs.txt" << endl;
		return 1;
	}
	return 0;
}


int lecture_realisateurs(vector<realisateur> &ListeRealisateurs)
{
	int i;
  ifstream fichier("realisateur.txt", ios::in);
	if (fichier)
	{
		string line;
		while(getline(fichier,line))
		{
	   	realisateur nouv = create_realisateur(take_nom(line),take_prenom(line),take_date(line));
			ListeRealisateurs.push_back(nouv);
		}
		fichier.close();
	}
  else
	{
	  cerr << "Erreur à l'ouverture de realisateur.txt" << endl;
		return 1;
	}
	return 0;
}

int reecriture(vector<acteur> ListeActeurs,vector<film> ListeFilms,vector<realisateur> ListeRealisateurs)
{
	int i = remove("acteurs.txt");
	int j = remove("realisateur.txt");
	int k = remove("films.txt");
	int l;
	if (i != 0 || j != 0 || k != 0)
	{
		cerr << "Erreur à la suppression des fichiers" << endl;
	}
	ofstream acteurs("acteurs.txt",ios::out);
	ofstream realisateurs("realisateur.txt",ios::out);
	ofstream films("films.txt",ios::out);

	if (acteurs && realisateurs && films)
	{
		for (i = 0; i < ListeActeurs.size(); i++)
		{
			acteurs << ListeActeurs[i].prenom << " " <<	ListeActeurs[i].nom << " " << ListeActeurs[i].date_de_naissance << endl;
		}
		for (i = 0; i < ListeRealisateurs.size(); i++)
		{
			realisateurs << ListeRealisateurs[i].prenom << " " << ListeRealisateurs[i].nom << " " << ListeRealisateurs[i].date_de_naissance << endl;
		}
		for (i = 0; i < ListeFilms.size(); i++)
		{
			films << ListeFilms[i].titre << endl;
			films << ListeFilms[i].annee << endl;
			films << ListeFilms[i].nomrealisateur.prenom << " " << ListeFilms[i].nomrealisateur.nom << endl;
			for (l = 0; l < ListeFilms[i].noms.size(); l++)
			{
				films << ListeFilms[i].noms[l].prenom << " " << ListeFilms[i].noms[l].nom;
				if (l + 1 != ListeFilms[i].noms.size())
				{
					films << ",";
				}
			}
			films << endl;
			films << ListeFilms[i].duree << endl;
			films << ListeFilms[i].genre << endl;
			films << endl;
		}
		acteurs.close();
		realisateurs.close();
		films.close();
	}
	else
	{
		cerr << "Erreur ouverture fichier (dans reecriture)" << endl;
	}
	return 0;
}
