#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

const int inf = numeric_limits<int>::max();
#define cost_place pair<float, int>

double prims(vector<vector<int>> &a, vector<vector<double>> &dist, int v){
    vector<double> cost(v, inf);
    vector<bool> inmst(v, false);
    vector<int> parent(v, -1);
    cost[0] = 0;
    priority_queue<cost_place, vector<cost_place>, greater<cost_place>> q;
    q.emplace(0, 0);
    double total_cost = 0;
    while(! q.empty()){
        int s = q.top().second;
        q.pop();
        inmst[s] = true;
        for(auto it=a[s].begin(); it!=a[s].end(); it++){
            if(inmst[*it] == false && cost[*it] > dist[s][*it]){
                cost[*it] = dist[s][*it];
                parent[*it] = s;
                q.emplace(cost[*it], *it);
            }
        }
    }
    for(int i=0; i<v; i++)
        total_cost += cost[i];
    return total_cost;
}

int main()
{
    int v;
    cin>>v;
    vector<pair<int, int>> points;
    vector<vector<int>> adj_list(v);
    for(int i=0; i<v; i++){
        int m, n;
        cin>>m>>n;
        points.emplace_back(m, n);
    }
    vector<vector<double>> dist(v, vector<double>(v));
    for(int i=0; i<v; i++){
        for(int j=v-1; j>=0; j--){
            if(i == j)
                continue;
            adj_list[i].push_back(j);
        }
    }

    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            dist[i][j] = sqrt(pow(points[i].first-points[j].first, 2) + pow(points[i].second-points[j].second, 2));
    double res = prims(adj_list, dist, v);
    cout<<setprecision(10)<<res;
    return 0;
}
