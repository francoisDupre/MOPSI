#include "questions.h"

std::map<string,int> frequenceNom(vector<Town> towns)
{
    std::map<string,int> frequence ;
    for (vector<Town>::iterator it=towns.begin() ;
    it != towns.end(); ++it)
    {
        frequence[it->name()]++ ;
    }
    return frequence ;
}

void histogrammeNom(vector<Town> towns)
{
    std::map<string,int> frequence = frequenceNom(towns) ;
    vector<int> histogramme(10) ;
    for (std::map<string,int>::iterator it1=frequence.begin() ;
    it1 != frequence.end(); ++it1)
    {
        histogramme[it1->second]++ ;
    }
    for (int i=1 ; i<10 ; i++)
    {
        std::cout << "Le nombre de communes dont le nom est utilise par "
        << i << " villes differentes vaut "
        << histogramme[i] << std::endl ;
    }
}

std::map<Point2D,int> frequenceCoordonnees(vector<Town> towns)
{
    std::map<Point2D,int> frequence ;
    for (vector<Town>::iterator it=towns.begin() ;
    it != towns.end(); ++it)
    {
        frequence[it->point()]++ ;
    }
    return frequence ;
}


void histogrammeCoordonnees(vector <Town> towns)
{
    std::map<Point2D,int> frequence = frequenceCoordonnees(towns) ;
    vector<int> histogramme(20) ;
    for (std::map<Point2D,int>::iterator it1=frequence.begin() ;
    it1 != frequence.end(); ++it1)
    {
        histogramme[it1->second]++ ;
    }
    for (int i=1 ; i<10 ; i++)
    {
        std::cout << "Le nombre de communes qui ont les memes coordoonnees que "
        << i << " villes differentes vaut "
        << histogramme[i] << std::endl ;
    }
}

std::pair<std::set<Town>,std::set<Town>> villesVoisines(vector<Town> towns)
{
    std::map<string,int> frequence_nom = frequenceNom(towns) ;
    std::map<Point2D,int> frequence_coordonnees = frequenceCoordonnees(towns) ;
    std::set<Town> homonymes ;
    std::set<Town> homotopes ;
    for (vector<Town>::iterator it=towns.begin() ;
    it != towns.end() ; ++it)
    {
        if (frequence_nom[it->name()] >= 2)
        {
            homonymes.insert(*it) ;
        }
        if (frequence_coordonnees[it->point()] >= 2)
        {
            homotopes.insert(*it) ;
        }

    }
    return std::make_pair(homonymes,homotopes) ;
}

vector<Town> villesIsotoponymes(vector<Town> towns)
{
    std::pair<std::set<Town>,std::set<Town>> villesProches = villesVoisines(towns) ;
    std::set<Town> villesHomonymes = villesProches.first ;
    std::set<Town> villesHomotopes = villesProches.second ;
    vector<Town> isotoponymes(villesHomotopes.size()) ;
    vector<Town>::iterator it = set_intersection(villesHomonymes.begin(),villesHomonymes.end(),
    villesHomotopes.begin(),villesHomotopes.end(),isotoponymes.begin()) ;
    isotoponymes.resize(it-isotoponymes.begin()) ;
    return isotoponymes ;
}

vector<Town> villesErreur(vector<Town> towns)
{
    vector<Town> isotoponymes = villesIsotoponymes(towns) ; // Villes pré-sélectionnées
    vector<Town> villesProches ; // Ensemble des villes qui conviendraient
    for (vector<Town>::iterator it = isotoponymes.begin() ;
    it != isotoponymes.end() ; it++)
    { // On parcourt l'ensemble des villes. Soit *it=v1
        vector<Town> memeNom = Town::towns_with_name(isotoponymes,it->name()) ;
        vector<Town> memeCoordonnees = Town::towns_with_lat_lon(isotoponymes,it->lat(),it->lon()) ;
        for (vector<Town>::iterator it1 = memeNom.begin() ; it1 != memeNom.end() ; it1++)
        { // emsemble des villes v3 qui ont le même nom que v1
            for (vector<Town>::iterator it2 = memeCoordonnees.begin() ; it2 != memeCoordonnees.end() ; it2++)
                    { // ensemble des villes v2 qui ont les mêmes coordonnées que v1
                        if (!(*it1 == *it) && !(*it2 == *it))
                        {
                        Town villeFictive(it2->name(),it1->lat(),it1->lon()) ;
                        vector<Town>::iterator it3 = find(isotoponymes.begin(),isotoponymes.end(),villeFictive) ;
                        if (it3 != isotoponymes.end())
                        { // Si on trouve une ville v4 différente de v1 qui a les mêmes coordonnées que v3 et le même nom que v2
                            villesProches.push_back(*it) ;
                            it2 = memeCoordonnees.end()-1 ;
                            it1 = memeNom.end()-1 ;
                            // On arrête la recherche et on insère v1 dans le vecteur.
                        }
                        }
                    }
        }
    }
    return villesProches ;
}

