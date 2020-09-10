#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

list<int> topo;

void explore(vector<vector<int>> &a, vector<int> &visited, int v){
    visited[v] = 1;
    for(auto it = a[v].begin(); it!=a[v].end(); it++){
        if(!visited[*it])
            explore(a, visited, *it);
    }
    topo.push_front(v);
}

void dfs(vector<vector<int>> &a, vector<int> &visited, int v){
    for(int i=1; i<=v; i++){
        if(! visited[i])
            explore(a, visited, i);
    }
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adj_list(v+1);
    vector<int> visited(v+1);
    for(int i=0; i<e; i++){
        int m, n;
        cin>>m>>n;
        adj_list[m].push_back(n);
    }
    dfs(adj_list, visited, v);
    for(auto it=topo.begin(); it!=topo.end(); it++)
        cout<<*it<<" ";
    return 0;
}
