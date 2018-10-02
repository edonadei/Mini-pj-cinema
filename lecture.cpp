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
		nom[j] = all[i];
		i++;
		j++;
	}
	return nom;
}

int take_date(string all)
{
	string nom;
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
		nom[j] = all[i];
		j++;
		i++;
	}
	return stoi(nom);
}

string take_prenom(string all)
{
	string prenom;
	int i =0;
	while (all[i] != ' ')
	{
		prenom[i] = all[i];
	}
	return prenom;
}

int lecture(vector<film> &ListeFilms)
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
				ListeFilms.push_back(stocker_film(movie));

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


film stocker_film(string tempfilm[6])
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
			acteurs[j][k] = tempfilm[3][i];
		}
		k++;
	}
	realisateur nouv_realisateur = create_realisateur(tempfilm[2],,0);
  film newfilm = create_film(tempfilm[0],stoi(tempfilm[1]),nouv_realisateur,stoi(tempfilm[4]),tempfilm[5]);
	add_acteur(create_acteur(acteurs[0]),newfilm);
	add_acteur(acteurs[1],newfilm);
	add_acteur(acteurs[2],newfilm);
	add_acteur(acteurs[3],newfilm);
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


int lecture_realisateur(vector<realisateur> &ListeRealisateurs)
{
	int i;
  ifstream fichier("realisateurs.txt", ios::in);
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
	  cerr << "Erreur à l'ouverture de acteurs.txt" << endl;
		return 1;
	}
	return 0;
}

