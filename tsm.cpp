/*Description: There is a file contains function findHamiltonian Path with dynamic programming
to efficient for solving Travelling Salesman Problem
It's efficient instead of backtracking only, I use dp 2 dimensional-array to store value shortest Hamiltonian path 
Worst case: O(2^26 * 26^2) << O(26!)*/
#include "tsm.h"
//Below function is used to find shortest Hamilton path from start_vertex
int findHamiltonianCircuit(int curr, int mask, int graph[][20],vector<vector<int>>&dp,vector<vector<int>>&prev, char start_vertex,const int num_vertices){
    //If the mask is equal to 2^n-1, return the value of the edge from the current vertex to the start vertex
    if(mask == (1<<num_vertices)-1){
        if(graph[curr][start_vertex-'A'] != 0) {
            return graph[curr][start_vertex-'A'];
        } else {
            return INF; // or some other value indicating that the path is not valid
        }
    }
    //If the value of the current vertex and mask is not -1, return the value of the current vertex and mask
    if(dp[curr][mask]!=-1){
        return dp[curr][mask];
    }
    //Declare a variable to store the value of the shortest path
    int ans = INF;
    for(int i = 0; i<num_vertices; i++){
        //If the vertex has not visited and there is an edge from the current vertex to the vertex
        if(!((1<<i) & mask) && graph[curr][i]!=0){
            //Below code mean that we update mask by adding the vertex i to the mask
            int nextpath = findHamiltonianCircuit(i,mask|(1<<i),graph,dp,prev,start_vertex,num_vertices);
            int temp = nextpath == INF || INT_MAX - graph[curr][i] < nextpath ? INT_MAX : graph[curr][i] + nextpath;//Recursive call
            if(temp<ans){//New shortest path is found
                ans = temp;
                prev[curr][mask] = i;
            }
        }
    }
    return dp[curr][mask] = ans;
} 

void print_tsmpath(int curr, int mask, vector<vector<int>>& prev, string& res, const int num_vertices) {
    //Iteration to update string path
    while(mask!=(1<<num_vertices)-1){
        res = res + (char)(curr+'A') + " ";
        int next = prev[curr][mask];
        mask |= (1<<next);
        curr = next;
    }
    res = res +  (char)(curr+'A') + " ";
}
//Below function is used to find the shortest path for Travelling Salesman Problem by using the Bellman-Ford algorithm
//and efficient by dynamic programming (because num_vertices has at most 26 vertices)
string Traveling(int graph[][20],int num_vertices,char start_vertex){
    //Declare a vector to store the value of the shortest path for dynamic programming. The value is -1 at the beginning to distinguish with INF for the shortest path
    //This vector is used to store the value of the shortest path from the current vertex to the start vertex use bitmask to store the visited vertices
    //Example: value_arr[2][5] is the value of the shortest path from vertex 2 to the start vertex with visited vertices are 1 and 2 (101)
    vector<vector<int>> value_arr(num_vertices,vector<int>(1<<num_vertices,-1));
    //Declare a vector to store the previous vertex
    vector<vector<int>> prev_arr(num_vertices,vector<int>(1<<num_vertices,-1));
    //Find all Hamilton path and calculate shortest path
    int shortest_path = findHamiltonianCircuit(start_vertex-'A',1<<(start_vertex-'A'),graph,value_arr,prev_arr,start_vertex,num_vertices);
    //Only print the path if there is a solution
    if(shortest_path >= INF){
        return "";
    }
    string res = "";
    //cout << "Shortest Path from start_vertex for TSM problem: "<<value_arr[start_vertex-'A'][1<<(start_vertex-'A')]<<endl;
    print_tsmpath(start_vertex - 'A',1<<(start_vertex-'A'),prev_arr,res,num_vertices);
    res+=start_vertex;
    return res;
}

/* int main(){
    int num_vertices = 26;
    cin>>num_vertices;
    int ** graph;
    graph = new int*[num_vertices];
    for(int i = 0 ; i<num_vertices; i++){
        graph[i] = new int[num_vertices];
        for(int j = 0; j<num_vertices; j++){
            cin>>graph[i][j];
        }
    }
    cout << num_vertices << "\n";
    char start_vertex;
    cin>>start_vertex;
    Travelling(graph,num_vertices,start_vertex);
    return 0;
} */