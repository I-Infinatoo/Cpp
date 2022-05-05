#include <bits/stdc++.h>
using namespace std;

void ff()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}


// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
//     vector<vector<vector<int>>> adj_list(vertices);
//     for(int i =0; i<edges; i++) {
//         adj_list[vec[i][0]].push_back( {vec[i][1], vec[i][2]} );
//         adj_list[vec[i][1]].push_back( {vec[i][0], vec[i][2]} );
//     }

//     // for(auto it : adj_list) {
//     //     for(auto i : it) {
//     //         cout << "[";
//     //         for(int val : i) {
//     //             cout << val << " ";
//     //         }
//     //         cout << "] ";
//     //     }
//     //     cout << "\n";
//     // }

//     vector<bool>fin(vertices, false);
//     vector<int>dist(vertices, INT_MAX);

//     queue< int > q;
 
//     q.push(source);
//     dist[source] = 0;

//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();

//         //         for(int i : fin) {
//         //             cout << i << " ";
//         //         } cout << "\n";
//         // cout << "u:" << u << ":\n";
        
//         for(auto it : adj_list[u]) {
//             int v = it[0];
//             int v_dist = it[1];

//             if(!fin[v]) {
                
//                 // cout << " v:" << v << " v_dist:" << v_dist << "(" << dist[v] << ", " << dist[u] + v_dist << ")\n";
//                 dist[v] = min(dist[v], dist[u] + v_dist);
                
//             }

//         }
//         fin[u] = true;
//                 // for(int i : dist) {
//                 //     cout << i << " ";
//                 // } cout << "\n";


//         int i =0;
//         while(i<vertices) {
//             int min_v = (min_element(dist.begin()+i, dist.end()) - dist.begin());
//             if(!fin[min_v]) {
//                 q.push(min_v);
//                 // cout << "fin[" << min_v << "]\n";
//                 break;
//             }
//             i++;
//         }

//     }

//     return dist;
// }

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    vector<vector<vector<int>>> adj_list(vertices);
    for(int i =0; i<edges; i++) {
        adj_list[vec[i][0]].push_back( {vec[i][1], vec[i][2]} );
        adj_list[vec[i][1]].push_back( {vec[i][0], vec[i][2]} );
    }
    vector<int>dist(vertices, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

    pq.push({0, source});
    dist[source]=0;
    
    while(!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;

        for(auto it : adj_list[u]) {

            int v = it[0], w = it[1];
            if(w + weight < dist[v]) {
                dist[v] = weight + w;
                pq.push({dist[v], v});
            }
        }

        pq.pop();
    }

    return dist;
}


int main()
{
    ff();

    int t;
    cin >> t;

    while (t--)
    {
        int n, e;
        cin >> n >> e;

        vector<vector<int>> edges(e, vector<int>(3));
        for (int i = 0; i < e; i++)
        {
            cin >> edges[i][0];
            cin >> edges[i][1];
            cin >> edges[i][2];
        }

        vector<int> ans = dijkstra(edges, n, e, 0);

        for(int i : ans) {
            cout << i << " ";
        }
        cout << "\n";

    }
    return 0;
}