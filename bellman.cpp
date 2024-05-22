//There is file to implement the Bellman-Ford algorithm. The file is bellman.cpp
#include "bellman.h"
/*Here is the implementation of the SPFA algorithm for efficient Bellman-Ford algorithm
SPFA is more efficent than the Bellman-Ford algorithm, but in worst case, it is the same as the Bellman-Ford algorithm with O(V*E) time complexity
Worst case of SPFA is when there is a negative cycle in the graph, in this case, the algorithm will loop forever
So want to detect that, we must count number of round a vertex reduce shortest value. If it's greater than or equal n, then graph have negative cycle
The reason of that: A shortes path can contain at most n vertices (n - 1 edges)
SPFA is more efficient because it's only do if value of shortest path at that vertex reduce*/
/*Why we use queue data structures, but not other data structures ?
Because we want to ensures that vertices are processed in the order they are discovered (when have a new shortest path to them) 
and queue satisfied that, with FIFO*/

//Below function is implement 1 round of Bellman-Ford algorithm
void BF(int graph[][20], int num_vertices, char start_vertex, int value_arr[],int prev_arr[]){
    value_arr[start_vertex-'A']=0;
    int temp[num_vertices] = {0};
    for(int i = 0 ; i < num_vertices; i++){
        temp[i]=value_arr[i];
    }
    for(int u = 0 ; u < num_vertices; u++){
        if(temp[u]==-1)    continue;
        for(int i = 0; i<num_vertices; i++){
            //If the value of the vertex is greater than the sum of the value of the current vertex and the edge
            if(graph[u][i]!=0 && (static_cast<long long>(temp[u])+static_cast<long long>(graph[u][i])<static_cast<long long>(value_arr[i]) || value_arr[i]==-1)){
                value_arr[i] = temp[u]+graph[u][i];
                //Set the previous vertex of the vertex is the current vertex
                prev_arr[i] = u;
            }
        }
    }
}
string BF_Path(int graph[][20], int num_vertices, char start_vertex, char end_vertex){
    //Declare the value array and previous array
    int value_arr[num_vertices];
    int prev_arr[num_vertices];
    fill(value_arr,value_arr+num_vertices,-1);//We see that value_arr[i]=-1 like value_arr[i]=INFINITY (because testcase don't have negative weight)
    fill(prev_arr,prev_arr+num_vertices,-1);
    //Set the value of the start vertex to 0
    value_arr[start_vertex-'A'] = 0;
    //Relax all the edges for num_vertices-1 times to get the shortest path
    for(int i = 0; i<num_vertices-1; i++){
        int checkrelax[num_vertices] = {0};
        for(int u = 0; u<num_vertices; u++)
            checkrelax[u]=value_arr[u];
        BF(graph,num_vertices,start_vertex,value_arr,prev_arr);
        bool change = false;
        for(int u = 0; u<num_vertices; u++){
            if(checkrelax[u]!=value_arr[u]){
                change = true;
                break;
            }
        }
        if(!change){
            break;
        }
        //Above code help Bellman-Ford efficient because loop stop if don't have any change 
    }
    //Detect negative cycle, this loop won't do anything in this assignment, because all edges are positive
    for(int i = 0; i < num_vertices;i++){
        for(int u = 0; u<num_vertices; u++){
            if(graph[i][u]!=0 && static_cast<long long>(value_arr[i])+static_cast<long long>(graph[i][u])<static_cast<long long>(value_arr[u])){
                cout << "Graph have negative cycle\n";
                return "";
            }
        }
    }
    char tmp = end_vertex;
    //Declare a string to store the path
    string path = "";
    //Push the end vertex to the path
    path+=end_vertex;
    //While the end vertex is not the start vertex, keep push the previous vertex to the path
    while(end_vertex!=start_vertex && prev_arr[end_vertex-'A']!=-1){
        end_vertex = char(prev_arr[end_vertex-'A']+'A');
        path=path + " " + end_vertex;
    }
    if(end_vertex!=start_vertex){
        cout<<"There is no path from "<<start_vertex<<" to "<<tmp<<endl;
        return "";
    }
    //Reverse the path to get the correct order
    reverse(path.begin(),path.end());
    return path;
}
void print_path(string path){
    if(path==""){
        return;
    }
    //Print the path
    cout << path << '\n';
}