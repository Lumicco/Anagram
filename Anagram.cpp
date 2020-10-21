#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string melange(string motMystere_F)
    {
        string motMelange_F;
        srand(time(0));

        while(motMystere_F.size() > 0)
        {
            int nombre = rand() % (motMystere_F.size());
            motMelange_F += motMystere_F[nombre];

           /* cout << "Mystere = " << motMystere_F << endl;
            cout << "lettre = " << motMystere_F[nombre]<< endl;
            cout << "nombre = " << nombre << endl;
            cout << "Melange = " << motMelange_F << endl; */

            motMystere_F.erase(nombre,1);
        }


        return motMelange_F;
    }

int main()
{
    string reponse;

    do
    {// On choisit un mot

        ifstream dico(/*path to dico.txt file*/);
        string motMystere;

        if(dico)
        {
            srand(time(0));
            int nombre = rand() % 323577;


            while(nombre > 0)
            {
               getline(dico, motMystere);
               nombre--;
            }
        }
        else
        {
            cout << "ERREUR" << endl;
        }

        //On mélange les lettres du mot
        string motMelange( melange(motMystere) );

        //On demande quel est le mot
        cout << "Quel est le mot mystere ?" << endl << motMelange << endl << endl;

        string any;
        cin >> any;

        while(any != motMystere)
        {

            cout << "Ce n'est pas ca. Entrez un autre mot." << endl << endl;
            cin >> any;
        }

        cout << "Bravo !" << endl;
        cout << "Voulez-vous rejouer? O/N" << endl;

        cin >> reponse;
        cout << endl;
    }   while(reponse == "O"
            || reponse == "o"
            || reponse == "oui"
            || reponse == "Oui");


    return 0;
}
