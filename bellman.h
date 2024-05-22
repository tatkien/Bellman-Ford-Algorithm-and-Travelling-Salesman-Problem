/* There is some library and some related fuctions to implement the Bellman-Ford algorithm
*/

#ifndef BELLMAN_H
#define BELLMAN_H



#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

void BF(int graph[][20], int num_vertices, char start_vertex, int value_arr[],int prev_arr[]);
string BF_Path(int graph[][20], int num_vertices, char start_vertex, char end_vertex);
void print_path(string path);
#endif