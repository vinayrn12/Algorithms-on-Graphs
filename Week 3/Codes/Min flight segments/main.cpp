#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 21345678

void explore(vector<vector<int>> &a, vector<int> &dist, vector<int> &prev, int v){
    queue<int> order;
    dist[v] = 0;
    order.push(v);
    while(! order.empty()){
        int u = order.front();
        order.pop();
        for(auto it=a[u].begin(); it!=a[u].end(); it++){
            if(dist[*it] == INF){
                order.push(*it);
                dist[*it] = dist[u] + 1;
                prev[*it] = u;
            }
        }
    }
}

int compute_path(vector<int> &prev, int s, int d){
    int c =0;
    while(d != s){
        c++;
        if(d == 0)
            return -1;
        d = prev[d];
    }
    if(c)
        return c;
    else
        return (-1);
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adj_list(v+1);
    vector<int> dist(v+1, INF);
    vector<int> prev(v+1);
    int m, n;
    for(int i=0; i<e; i++){
        cin>>m>>n;
        adj_list[m].push_back(n);
        adj_list[n].push_back(m);
    }
    cin>>m>>n;
    explore(adj_list, dist, prev, m);
   // bfs(adj_list, dist, prev, v);
    int res;
    res = compute_path(prev, m, n);
    cout<<res;
    return 0;
}
