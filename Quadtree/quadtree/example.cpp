#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cmath>
#include<limits>
#include<cstdlib>

using namespace std;

#ifndef srcPath
#define srcPath "."
#endif
#include "town.h"
#include "square.h"
#include "quadrant.h"
#include "neighbors.h"


/*
 * Example of use of "town.h" and "villes.txt":
 * - read file of metropolitan French towns with coordinates
 * - display reading time and number of towns read
 * - ask for town name
 * - lookup for town coordinates with this name and display them
 * - display distance between two random towns
 */
int main()
{
    ///// Read town file
    /////
    // Create an empty list of towns
    string townFile ("C:/Users/Francois/Documents/Structures/Quadtree/villes.txt");

    srand(time(NULL)) ;

    vector<Town> towns ;
    // Prepare limits
    float xmin = std::numeric_limits<float>::max();
    float ymin = std::numeric_limits<float>::max();
    float xmax = std::numeric_limits<float>::min();
    float ymax = std::numeric_limits<float>::min();
    // Read file
    cout << "Reading town file: " << townFile << endl;
    clock_t t1 = clock();
    int nb_towns = Town::read_file(townFile, towns, xmin, ymin, xmax, ymax);
    clock_t t2 = clock();
    // Say how many towns have been read
    if (nb_towns < 0)
    {
	cout << "No town found" << endl;
	return 1;
    }
    cout << "File read in " << ((float)(t2-t1)/CLOCKS_PER_SEC) << " s" << endl;
    cout << "Number of towns in file: " << nb_towns << endl;
    cout << "Bounding box: (" << xmin<< "," << ymin << ")-("
	 << xmax << "," << ymax << ")" << endl;
    clock_t before_0 = clock() ;
    QuadTree<Point2D<string>>* carte(nullptr) ;
    Square s(xmin-0.1,ymin-0.1,max(xmax-xmin,ymax-ymin)+0.1) ;
    for (vector<Town>::iterator it_town = towns.begin();
    it_town != towns.end(); ++it_town)
	     {
          Point2D<string> localisation(it_town->x(),it_town->y(),it_town->name()) ;
          insert(carte,s,localisation) ;
         }
    clock_t after_0 = clock() ;


cout << "\n \n-----------------------------------------------QUESTION 6----------------------------------------------- \n \n" << endl ;

    cout << "The tree contains " << (*carte).nbLeaves() << " leaves" << endl ;
    cout << "The tree contains " << (*carte).nbNodes() << " nodes" << endl ;
    cout << "The tree contains " << (*carte).nbLeaves() << " sub-trees" << endl ;

cout << "\n \n-----------------------------------------------QUESTION 7----------------------------------------------- \n \n" << endl ;

bool villeExiste = false ;

string name;
vector<Town> ntowns ;
vector<Point2D<string>> villesProches ;
while (!villeExiste)
{
cout << "What town are you interested in ?" << endl ;
getline(cin, name) ;
ntowns = Town::towns_with_name(towns, name) ;
    if (ntowns.size() > 0)
    {
        villeExiste=true ;
    }
    else
    {
        cout << "This town does not exist. Pick another one" << endl ;
    }
}
Town villeRecherchee = ntowns.back() ;
cout << "Number of towns with this name: " << ntowns.size() << endl;



int numberNodesVisited = search(villesProches,carte,s,villeRecherchee.point()) ;

cout << villesProches.size() << endl ;
cout << "The closest town to " << name << " is " << (villesProches.back()).info() << endl ;
cout << "The number of nodes we had to visit to find the closest town to " << name << " was " << numberNodesVisited << endl ;

cout << "In comparaison, if we had done a linear search of the vector towns, we would have had to visit all " << towns.size() << " towns." << endl ;

cout << "\n \n-----------------------------------------------QUESTION 8----------------------------------------------- \n \n" << endl ;

int numberRand(100) ;
int numberTowns(towns.size()) ;
vector <Town> randomTowns ;
cout << "We randomly pick " << numberRand << " towns" << endl ;

for (int i=0 ; i < numberRand ; i++)
{
    int randomNumber = rand() % numberTowns ;
    randomTowns.push_back(towns[randomNumber]) ;
}


clock_t before_1 = clock() ;
for (int i=0 ; i < numberRand ; i++)
{
    villesProches.clear() ;
    Town randomTown = randomTowns[i] ;
    int a = search(villesProches,carte,s,randomTown.point()) ;
}
clock_t after_1 = clock() ;
float QuadTreeDuration = (float)(after_1-before_1)/CLOCKS_PER_SEC ;
cout << "On average, the quadtree search lasts "  << QuadTreeDuration/ (float)numberRand << " seconds" << endl ;



clock_t before_2 = clock() ;
float max_size(s.w*s.w) ;
for (int i=0 ; i < numberRand ; i++)
{
    villesProches.clear() ;
    Town randomTown = randomTowns[i] ;
    Town closestTown = linearSearch(towns,max_size,randomTown) ;
}
clock_t after_2 = clock() ;
double LinearDuration = (float)(after_2-before_2)/CLOCKS_PER_SEC ;
cout << "On average, the linear search lasts "  << LinearDuration/ (float)numberRand << " seconds" << endl ;

cout << "\nTherefore, on average, using quadtree is " << LinearDuration/QuadTreeDuration << " faster than using linear search" << endl ;

cout << "\n \n-----------------------------------------------QUESTION 9-----------------------------------------------\n \n" << endl ;

int numberRand_2(100) ;

float QuadtreeBuildTime = (float)(after_0-before_0)/CLOCKS_PER_SEC ;
int nombreTotal(0) ;
for (int i=0 ; i < numberRand_2 ; i++)
{
    float QuadtreeSearchTime(QuadtreeBuildTime) ;
    float LinearSearchTime(0) ;
    int nombreNecessaire(0) ;
    while (QuadtreeSearchTime > LinearSearchTime)
    {
        int j = rand() % numberTowns ;
        clock_t time0 = clock() ;

        int a = search(villesProches,carte,s,towns[j].point()) ;
        clock_t time1 = clock() ;
        QuadtreeSearchTime+=(float)(time1-time0)/CLOCKS_PER_SEC ;

        Town t = linearSearch(towns,max_size,towns[j]) ;
        clock_t time2 = clock() ;
        LinearSearchTime+=(float)(time2-time1)/CLOCKS_PER_SEC ;

        nombreNecessaire+=1 ;
    }
    nombreTotal += nombreNecessaire ;
}
cout << "On average, we need to make at least " << ceil((float)nombreTotal/ (float)numberRand_2) << " searches if we want to use quadtree search instead of linear search" << endl ;

/*
vector<Town> banlieueProche ;
banlieueProche = search(banlieueProche,carte,s,Point2D(48.86,2.3),1,nearest) ;
cout << (banlieueProche.pop_back()).name() << endl ;
*/

    ///// Operate on quadtree
    /////
    // Ask for a town to look for
 // Read whole line including spaces
    // Note that "cin >> name;" would read only the first word, stopping
    // at the first blank (space or tab)
    // Look for towns with this name

    // Display their coordinates





    /*
    for (vector<Town>::iterator it_ntown = ntowns.begin();
	 it_ntown != ntowns.end(); ++it_ntown)
	cout << "  (lat=" << it_ntown->lat()
	     << ",lon=" << it_ntown->lon() << ")" << endl;

    // Make sure rand() draws different random numbers each time the
    // program is run
    srand(clock());
    // Draw two random towns

    Town town1 = towns[rand() % towns.size()];
    Town town2 = towns[rand() % towns.size()];
    // Compute distance
    cout << "By the way, did you know that " << town1.name()
	 << " was " << town1.dist(town2)
	 << " km away from " << town2.name() << " ?" << endl;
    */
    return 0 ;
}

