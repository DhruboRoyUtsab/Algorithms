#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int V;
    vector<int> *adj;
    
    bool DFS(int v,vector<bool> &visited,vector<bool> &recStack){
        visited[v] =true;
        recStack[v] = true;

        for(int neighbor: adj[v]){
            if(!visited[neighbor] && DFS(neighbor,visited,recStack)){
                return true;

            }
            else if(recStack[neighbor]){
                return true;
            }
        }
        recStack[v] = false;
        return false;
    }

    public:
    Graph(int V){
        this-> V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool hasCycle(){
        vector<bool> visited(V,false);
        vector<bool> recStack(V,false);

        for(int i = 0;i<V;i++){
            if(!visited[i] && DFS(i,visited,recStack)){
                return true;
            }

        }
        return false;

    }
};

int main(){
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);

    if(g.hasCycle()){
        cout << "Graph contains a cycle" << endl;
    }
    else{
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
    
} 