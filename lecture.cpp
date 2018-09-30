#include "struct.h"



int main()
{
  lecture();
  return 0;
}

int lecture()
{
	int i;
	ifstream fichier("films.txt", ios::in);
	if (fichier)
	{
		string line;
	  string[6] film;
		i = 0;
		while(getline(fichier,line))
		{
			film[i] = line;
			i++;
			if (i == 6) 
			{
				i = 0;
				stocker(film);
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


int stocker_film(string[6] film)
{
	int i;
	int j = 0;
	string[4] acteurs;
	for (i = 0; k = 0; i < film[3].length(); i++; k++)
	{
		if (film[3][i] == ',')
		{
			j++;
			k=0;
		}
		else
		{
			acteur[j][k] = film[i];
		}
	}
	create_film(film[0],film[1],film[2],film[4],film[5],acteurs[0],acteurs[1],acteurs[2],acteurs[3]);
	return 0;
}




