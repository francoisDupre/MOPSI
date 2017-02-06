#pragma once

#include <iostream>
#include <string>
using std::string ;
#include <set>
#include <vector>
using std::vector ;
#include <utility>
#include <map>
#include <algorithm>

#include "town.h"

// Construct a map which contains the frequency of a name (number of towns that use that name)
std::map<string,int> frequenceNom(vector<Town> towns) ;

// Build an histogram with name frequencies.
void histogrammeNom(vector<Town> towns) ;

// Construct a map which contains the frequency of a coordinate (number of towns that use that coordinate)
std::map<Point2D,int> frequenceCoordonnees(vector<Town> towns) ;

// Build an histogram with coordinate frequencies.
void histogrammeCoordonnees(vector <Town> towns) ;

// Returns a pair :
// the first instance is a set of towns who share their name with
// one (or several) other town(s) ;
//  the second instance is a set of towns who share their coordinates with
// one (or several) other town(s) ;
std::pair<std::set<Town>,std::set<Town>> villesVoisines(vector<Town> towns) ;

// Returns a vector which contains towns which have both an homonym and
// an "homotop"
vector<Town> villesIsotoponymes(vector<Town> towns) ;

// Returns a vector which contains towns which contains towns who
// verify the condition in question 4.
vector<Town> villesErreur(vector<Town> towns) ;
