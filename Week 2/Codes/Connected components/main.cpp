#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int c = 0;

void dfs_explore(vector<vector<int>> &a, vector<int> &visited, int v, stack<int> &o){
    visited[v] = 1;
    for(auto it = a[v].begin(); it!=a[v].end(); it++){
        if(!visited[*it])
            dfs_explore(a, visited, *it, o);
    }
    o.push(v);
}

void dfs(vector<vector<int>> &a, vector<int> &visited, int v, stack<int> &order){
    for(int i=1; i<=v; i++){
        if(! visited[i]){
            dfs_explore(a, visited, i, order);
        }
    }
}

int calculate_components(vector<vector<int>> &a, vector<int> &visited, int v, stack<int> &o){
    for(unsigned int i=0; i<visited.size(); i++)
        visited[i] = 0;

    while(! o.empty()){
        int v = o.top();
        o.pop();

        if(! visited[v]){
            stack<int> sub_stack;
            dfs_explore(a, visited, v, o);
            c++;
        }
    }
    return c;
}

int main()
{
    stack<int> order;
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adj_list(v+1), adj_rev(v+1);
    vector<int> visited(v+1);
    for(int i=0; i<e; i++){
        int m, n;
        cin>>m>>n;
        adj_list[m].push_back(n);
        adj_rev[n].push_back(m);
    }
    dfs(adj_list, visited, v, order);
    cout<<calculate_components(adj_rev, visited, v, order);
    return 0;
}
