#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c = 0;

bool explore(vector<vector<int>> &a, vector<int> &visited, vector<int> &rec_stack, int v){
    rec_stack[v] = 1;
    visited[v] = 1;
    for(auto it=a[v].begin(); it!=a[v].end(); it++){
        if(!visited[*it] && explore(a, visited, rec_stack, *it))
            return true;
        else if(rec_stack[*it])
            return true;
    }
    rec_stack[v] = 0;
    return false;
}

void dfs(vector<vector<int>> &a, vector<int> &visited, int v){
    vector<int> rec_stack(v+1);
    for(int i=1; i<=v; i++){
        if(! visited[i] && explore(a, visited, rec_stack, i)){
            c = 1;
            break;
        }
    }
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adjacency_list(v+1);
    vector<int> visited(v+1);
    for(int i=0; i<e; i++){
        int m, n;
        cin>>m>>n;
        adjacency_list[m].push_back(n);
    }
    dfs(adjacency_list, visited, v);
    if(c)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
