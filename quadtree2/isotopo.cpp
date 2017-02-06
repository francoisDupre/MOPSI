#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "point2d.h"
#include "town.h"
#include "questions.h"

using namespace std;


#ifndef srcPath
#define srcPath "."
#endif
// The path and name of the town file
string townFile = "villes.txt";

/*
 * Study French isotoponyms
 */
int main()
{
    /////
    ///// Read town file
    /////
    // Create an empty list of towns
    vector<Town> towns;
    // Read file
    cout << "Reading town file: " << townFile << endl;
    clock_t time1 = clock();
    int nb_towns = Town::read_file(townFile, towns);
    clock_t time2 = clock();
    // Sanity check
    if (nb_towns < 0)
    {
	cout << "Error while reading file" << endl;
	return 2;
    }
    if (nb_towns == 0)
    {
	cout << "No town found" << endl;
	return 1;
    }
    // Say how many towns have been read
    cout << "File read in: "
	 << ((float)(time2-time1)/CLOCKS_PER_SEC) << " s" << endl ;
    cout << "Number of towns in file: "
	 << towns.size() /* same as nb_towns */ << endl ;
    cout << "First town in file: " << towns[0] << endl ;

    // That's all folks
    cout << "\n \n-----------------------------------------------QUESTION 1-----------------------------------------------\n \n" << endl ;

    histogrammeNom(towns) ;

    cout << "\n \n-----------------------------------------------QUESTION 2-----------------------------------------------\n \n" << endl ;
    histogrammeCoordonnees(towns) ;

    cout << "\n \n-----------------------------------------------QUESTION 3-----------------------------------------------\n \n" << endl ;

    std::pair<std::set<Town>,std::set<Town>> villesQuiConviennent = villesVoisines(towns) ;
    set<Town> villesHomonymes = villesQuiConviennent.first ;
    set<Town> villesHomotopes = villesQuiConviennent.second ;
    vector<Town> Isotoponymes = villesIsotoponymes(towns) ;

    cout << "On appelle N l'ensemble des villes qui ont au moins un homonyme." << endl ;
    cout << "|N| = " << villesHomonymes.size() << endl ;
    cout << "On appelle C l'ensemble des villes qui ont au moins un homonyme." << endl ;
    cout << "|C| = " << villesHomotopes.size() << "\n" << endl ;
    cout << "L'intersection de N et de C a pour cardinal " << Isotoponymes.size() << endl ;

    cout << "\n \n-----------------------------------------------QUESTION 4-----------------------------------------------\n \n" << endl ;

    vector<Town> villes_proches = villesErreur(towns) ;
    cout << "Il existe " <<villes_proches.size() << " couples de villes que l'on risque de confondre" << endl ;

    // std::pair<std::set<Town>,std::set<Town>> villesProches = villesVoisines(towns) ;
    // std::set<Town> villesHomonymes = villesProches.first ;
    // std::set<Town> villesHomotopes = villesProches.second ;
}

