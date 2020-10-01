#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

const int INF = std::numeric_limits<int>::max();
#define points pair<int, int>

using namespace std;

void dijkstra(vector<vector<int>> &a, vector<vector<int>> &w, vector<long long> &dist, vector<int> &path, int m){
    dist[m] = 0;
    priority_queue<points, vector<points>, greater<points>> q;
    q.emplace(0, m);
    while(! q.empty()){
        int u = q.top().second;
        q.pop();
        for(auto it=begin(a[u]); it!=end(a[u]); it++){
            if(dist[*it] > dist[u]+w[u][*it] && *it != path[u]){
                dist[*it] = dist[u] + w[u][*it];
                path[*it] = u;
                q.emplace(dist[*it], *it);
            }
        }
    }
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adj_list(v+1);
    vector<vector<int>> weight(v+1, vector<int>(v+1));
    vector<long long> dist(v+1, INF);
    vector<int> path(v+1);
    int m, n, w;
    for(int i=0; i<e; i++){
        cin>>m>>n>>w;
        adj_list[m].push_back(n);
        weight[m][n] = w;
    }
    cin>>m>>n;
    dijkstra(adj_list, weight, dist, path, m);
    if(dist[n] == INF)
        dist[n] = -1;
    cout<<dist[n];
    return 0;
}
