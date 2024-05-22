#include "bellman.h"
#include "tsm.h"
int pathlength(int G[][20], int n , const string res){
    int i = 0;
    int ans = 0;
    const int k = res.length();
    while(i<k-1){
        cout << i << " " << i+2 << '\n';
        ans+=G[res[i]-'A'][res[i+2]-'A'];
        i+=2;
    }
   //return ans;
}
int main(){
    //Declare a graph with 20 vertices (constraints: Maximum number of vertices is 20)
    int num_vertices = 20;
    cin>>num_vertices;
    //Declare a graph with int 2 pointers instead of vector
    int graph[num_vertices][20];
    //Input the weight of the edges
    for(int i = 0 ; i<num_vertices; i++){
        for(int j = 0; j<num_vertices; j++){
            cin>>graph[i][j];
        }
    }
    //Initialize start and end vertices
    char start_vertex;
    char end_vertex;
    cin>>start_vertex/* >>end_vertex */;
    //Call the Bellman-Ford algorithm
    /* string path = BF_Path(graph,num_vertices,start_vertex,end_vertex);
    print_path(path); */
    //Here for Travelling Salesman Problem test function
    string temp = Traveling(graph,num_vertices,start_vertex);
    cout << temp << "\n";
    cout << pathlength(graph,num_vertices,temp) <<  "\n";
    return 0;
}