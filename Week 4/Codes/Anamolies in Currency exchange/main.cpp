#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int inf = numeric_limits<int>::max();

int bellman_cycle(vector<vector<int>> &a, vector<vector<int>> &w){
    vector<long> dist(a.size(), inf);
    dist[0] = 0;
    for(int i=0; i<a.size(); i++){
        for(int s=0; s<a.size(); s++){
            for(int k=0; k<a[s].size(); k++){
                int d = a[s][k];
                if(dist[d] > dist[s] + w[s][d]){
                    dist[d] = dist[s] + w[s][d];
                    if(i == a.size() - 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int v, e;
    cin>>v>>e;
    vector<vector<int>> adj_list(v);
    vector<vector<int>> weights(v, vector<int>(v));
    int m, n, w;
    for(int i=0; i<e; i++){
        cin>>m>>n>>w;
        adj_list[m-1].push_back(n-1);
        weights[m-1][n-1] = w;
    }
    cout<<bellman_cycle(adj_list, weights);
    return 0;
}
