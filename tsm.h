//There is a file define some library and function to implement the TSM problem. The file is tsm.h
#ifndef TSM_H
#define TSM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

#define INF 1e5//Medium large integer for indicate that if there is no edge between two vertices

string Traveling(int graph[][20],int num_vertices,char start_vertex);

#endif