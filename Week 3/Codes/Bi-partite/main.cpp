#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 21345678
int f = 1;

void explore(vector<vector<int>> &a, vector<int> &dist, vector<int> &color, int v){
    queue<int> order;
    dist[v] = 0;
    color[v] = 1;
    order.push(v);
    while(! order.empty()){
        int u = order.front();
        order.pop();
        for(auto it=a[u].begin(); it!=a[u].end(); it++){
            if(dist[*it] == INF){
                order.push(*it);
                color[*it] = (! color[u]);
                dist[*it] = dist[u] + 1;
            }
            else{
                if(color[*it] == color[u])
                    f=0;
            }
        }
    }
}

void bfs(vector<vector<int>> &a, vector<int> &dist, vector<int> &color, int v){
    for(int i=1; i<=v; i++){
        if(dist[i] == INF)
            explore(a, dist, color, i);
    }
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adj_list(v+1);
    vector<int> dist(v+1, INF);
    vector<int> color(v+1, INF);
    int m, n;
    for(int i=0; i<e; i++){
        cin>>m>>n;
        adj_list[m].push_back(n);
        adj_list[n].push_back(m);
    }
    bfs(adj_list, dist, color, v);
    if(f)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
