#include <iostream>
#include <vector>

using namespace std;
int c = 0;

void add_edge(vector<vector<int>> &a, int m, int n){
    a[m].push_back(n);
    a[n].push_back(m);
}

void explore(vector<vector<int>> &a, vector<int> &visited, int v){
    //path[v] = c;
    visited[v] = 1;
    for(unsigned int i=0; i<a[v].size(); i++){
        if(! visited[a[v][i]])
            explore(a, visited, a[v][i]);
    }
}

void dfs(vector<vector<int>> &a, vector<int> &visited, int v){
    for(int i=1; i<=v; i++){
        if(! visited[i]){
            explore(a, visited, i);
            c += 1;
        }
    }
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<int> visited(v+1);
    for(int i=1; i<=v; i++)
        visited[i] = 0;
    vector<vector<int>> adjacency_list(v+1);
    int n, m;
    for(int i=0; i<e; i++){
        cin>>m>>n;
        add_edge(adjacency_list, m, n);
    }
    dfs(adjacency_list, visited, v);
    cout<<c;
    return 0;
}
