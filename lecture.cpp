#include "struct.h"

int lecture(vector<film> ListeFilms)
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
	realisateur nouv_realisateur = create_realisateur(tempfilm[2],"",0);
    film newfilm = create_film(tempfilm[0],stoi(tempfilm[1]),nouv_realisateur,stoi(tempfilm[4]),tempfilm[5]);
	add_acteur(acteurs[0],newfilm);
	add_acteur(acteurs[1],newfilm);
	add_acteur(acteurs[2],newfilm);
	add_acteur(acteurs[3],newfilm);
	return nouv;
}




