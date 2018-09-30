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


film stocker_film(string film[6])
{
	int i;
	int j = 0;
	int k = 0;
	string acteurs[4];
	film nouv;
	for (i = 0; i < film[3].length(); i++)
	{
		if (film[3][i] == ',')
		{
			j++;
			k=0;
		}
		else
		{
			acteurs[j][k] = film[3][i];
		}
		nouv =  create_film(film[0],film[1],film[2],film[4],film[5]);
		add_acteur(acteurs[0],nouv);
		add_acteur(acteurs[1],nouv);
		add_acteur(acteurs[2],nouv);
		add_acteur(acteurs[3],nouv);
		k++;
		return nouv;
}




