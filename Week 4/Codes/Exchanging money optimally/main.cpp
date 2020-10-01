#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

const int inf = numeric_limits<int>::max();

void bellman_cycle(vector<vector<int>> &a, vector<vector<int>> &w, int source, vector<bool> &short_path, vector<bool> &is_reachable, vector<long> &dist){
    queue<int> q;
    dist[source] = 0;
    is_reachable[source] = true;
    for(unsigned int i=1; i<a.size(); i++){
        for(unsigned int s=1; s<a.size(); s++){
            for(unsigned int k=0; k<a[s].size(); k++){
                int d = a[s][k];
                if(dist[d] > dist[s] + w[s][d] && dist[s] != inf){
                    dist[d] = dist[s] + w[s][d];
                    is_reachable[d] = true;
                    if(i == a.size()-1)
                        q.push(d);
                }
            }
        }
    }

    //bfs to check infinite loop
    vector<int> visited(a.size());
    while(! q.empty()){
        int v = q.front();
        q.pop();
        short_path[v] = false;
        visited[v] = true;
        for(unsigned int i=0; i<a[v].size(); i++){
            int t = a[v][i];
            if(! visited[t])
                q.push(t);
        }
    }
    dist[source] = 0;
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adj_list(v+1);
    vector<vector<int>> weights(v+1, vector<int>(v+1));
    vector<long> dist(v+1, inf);
    int m, n, w;
    for(int i=0; i<e; i++){
        cin>>m>>n>>w;
        adj_list[m].push_back(n);
        weights[m][n] = w;
    }
    cin>>m;
    vector<bool> short_path(v+1, true);
    vector<bool> is_reachable(v+1, false);
    bellman_cycle(adj_list, weights, m, short_path, is_reachable, dist);
    for(int i=1; i<=v; i++){
        if(! is_reachable[i])
            cout<<"*"<<endl;
        else if(! short_path[i])
            cout<<"-"<<endl;
        else
            cout<<dist[i]<<endl;
    }
    return 0;
}
