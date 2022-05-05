#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<vector<int>> &adj_list, int a, int b)
{

    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
}

bool bfsCheck(vector<vector<int>> &adj_list, vector<int>& color, int s) {

    queue<int> q;
    q.push(s);
    color[s] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        int curr_color = color[curr];

        for (int u : adj_list[curr])
        {
            if (color[u] == -1)
            {
                color[u] = !curr_color;//(curr_color == 0 ? 1 : 0);
                q.push(u);
            }
            else if (color[u] == curr_color)
            {
                return false;
            }
        }

        q.pop();
    }
    return true;

}


bool isBipertiteBFS(vector<vector<int>> &adj_list, int v)
{

    vector<int> color(v, -1);

    for(int i = 0; i<v; i++) {
        if(color[i] == -1) {
            if(!bfsCheck(adj_list, color, i)) {
                return false;
            }
        }
    }
    return true;

}




bool dfsCheck(vector<vector<int>> &adj_list, vector<int>& color, int s) {
    for(int u : adj_list[s]) {
        if(color[u] == -1) {
            color[u] = !color[s];
            if(!dfsCheck(adj_list, color, u)){
                return false;
            }
        } else if( color[u] == color[s] ) {
            return false;
        }
    }

    return true;
}


bool isBipertiteDFS(vector<vector<int>> &adj_list, int v)
{

    vector<int> color(v, -1);

    for(int i = 0; i<v; i++) {
        if(color[i] == -1) {
            color[i] = 0;
            if(!dfsCheck(adj_list, color, i)) {
                return false;
            }
        }
    }
    return true;

}


void disp_adj_list(vector<vector<int>> &adj_list)
{
    for (auto &list : adj_list)
    {
        for (int x : list)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{

    int v = 8;
    vector<vector<int>> adj_list(v);

    add_edge(adj_list, 0, 1);
    add_edge(adj_list, 1, 2);
    add_edge(adj_list, 2, 3);
    add_edge(adj_list, 3, 4);
    add_edge(adj_list, 4, 5);
    add_edge(adj_list, 5, 6);
    add_edge(adj_list, 5, 1);
    add_edge(adj_list, 4, 7);

    // disp_adj_list(adj_list);
    
    cout << "\n";

    cout << "IsBipertite: " << isBipertiteDFS(adj_list, v);
    return 0;
}