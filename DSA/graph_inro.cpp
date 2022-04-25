/**
 * 
 *  - Contents :
 *                  - making of adjecency list (adj_list)
 *                          (directed and undirected graphs)
 *                  - display the adj_list
 *                  - bfs (Breadth First Search) traversal for both continues and discontinues graphs
 *                  - dfs
 *                  - topological sort using DFS and BFS
 *                  - cycle detection
 *                  - cycle detection in directed graph (using dfs)
 *                  - All vertex Distance(minimum) from source using BFS (BFS will give the min. dist)
 * 
 *                  - MST (using PRIMS ALGO)
 * 
 * **/

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj_list, int u, int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
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

// ----------------------------- normal bfs -----------------------------------

void bfs(vector<vector<int>> &adj_list, int s)
{

    vector<bool> visited(adj_list.size(), false);
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int curr = q.front();
        for (int num : adj_list[curr])
        {
            if (!visited[num])
            {
                visited[num] = true;
                q.push(num);
            }
        }
        cout << curr << " ";
        q.pop();
    }
}
// -----------------------------------------------------------------------------

//  -------------------------- bfs for discontinues graph ----------------------

void bfs(vector<vector<int>> &adj_list, int s, vector<bool> &visited)
{

    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int curr = q.front();
        for (int num : adj_list[curr])
        {
            if (!visited[num])
            {
                visited[num] = true;
                q.push(num);
            }
        }
        // cout << curr << " ";
        q.pop();
    }
}

void bfs_discontinues(vector<vector<int>> &adj_list)
{
    vector<bool> visited(adj_list.size(), false);

    int count = 0;

    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            count++;
            bfs(adj_list, i, visited);
        }
    }
    cout << "Total number of Discontinues graph: " << count;
}

// -----------------------------------------------------------------------------

// --------------------------------- dfs ---------------------------------------

void dfs(vector<vector<int>> &adj_list, int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";

    for (auto &u : adj_list[s])
    {
        if (!visited[u])
        {
            dfs(adj_list, u, visited);
        }
    }
}

void dfs_helper(vector<vector<int>> &adj_list)
{

    vector<bool> visited(adj_list.size(), false);

    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            dfs(adj_list, i, visited);
        }
    }
}

// -----------------------------------------------------------------------------



// ------------------------------- cycle detection (directed graphs) ------------------------------
bool dfs_parent(vector<vector<int>> &adj_list, int s, vector<bool> &visited, int parent)
{

    visited[s] = true;
    for (int u : adj_list[s])
    {
        if (!visited[u])
        {

            if (dfs_parent(adj_list, u, visited, s))
            {
                return true;
            }
        }
        else if (u != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> &adj_list)
{
    vector<bool> visited(adj_list.size(), false);

    for (int i = 0; i < adj_list.size(); i++)
    {

        if (!visited[i])
        {
            if (dfs_parent(adj_list, i, visited, -1))
            {
                return true;
            }
        }
    }
    return false;
}
// ------------------------------------------------------------------

void addDirectedEdge(vector<vector<int>> &adj_list, int u, int v)
{
    adj_list[u].push_back(v);
}

// ------------------------- topological order (bfs) ---------------------

void cal_indegre(vector<vector<int>> &adj_list, vector<int> &indegre)
{
    for (auto &it : adj_list)
    {
        for (int i : it)
        {
            indegre[i]++;
        }
    }
}

// - In ths order the node with the least indegree comes first and then rest
// - It is strictly applied on the DAG
//   means atleast one node will have indegre equal to 0
void topologicalOrder_bfs(vector<vector<int>> &adj_list)
{
    vector<int> indegre(adj_list.size(), 0);
    cal_indegre(adj_list, indegre);

    queue<int> q;

    for (int i = 0; i < indegre.size(); i++)
    {
        if (indegre[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int i : adj_list[u])
        {
            indegre[i]--; // reducing the indgre because we are poping out the parent from the queue
            if (indegre[i] == 0)
            {
                q.push(i);
            }
        }
    }
}
// ----------------------------------------------------------------------------------

// ---------------------------- topological order (dfs)------------------------------

void topo_dfs_helper(vector<vector<int>> &adj_list, int s, vector<bool> &visited, stack<int> &st)
{
    visited[s] = true;

    for (int i : adj_list[s])
    {
        if (!visited[i])
        {
            topo_dfs_helper(adj_list, i, visited, st);
        }
    }
    cout << s << " ";
    st.push(s);
}

void topologicalOrder_dfs(vector<vector<int>> &adj_list)
{
    vector<bool> visited(adj_list.size(), false);
    stack<int> st;

    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            topo_dfs_helper(adj_list, i, visited, st);
        }
    }
    cout << "\n";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

// ----------------------------------------------------------------------------------

// ---------------------- Cycle in Directed Grapph ----------------------------------
// - using dfs

bool helper(vector<vector<int>> &adj_list, vector<bool> &visited, vector<bool> &dfsVisited, int s)
{
    visited[s] = true, dfsVisited[s] = true;

    for (int i : adj_list[s])
    {
        if (!visited[i])
        {
            if (helper(adj_list, visited, dfsVisited, i))
            {
                return true;
            }
        }
        else if (visited[i] && dfsVisited[i])
        {
            return true;
        }
    }

    dfsVisited[s] = false;
    return false;
}

bool isCycleDirectedGraph(vector<vector<int>> &adj_list)
{
    vector<bool> visited(adj_list.size(), false);
    vector<bool> dfsVisited(adj_list.size(), false);

    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            if (helper(adj_list, visited, dfsVisited, i))
            {
                return true;
            }
        }
    }

    return false;
}

// ----------------------------------------------------------------------------------

// ------------------------- allVertexDistFromSource --------------------------------
//  - using bfs

//  - since it not for the weihted graph : therefore we are considering the minimum number of edges
void allVertexShortestDistFromSource(vector<vector<int>> &adj_list, int s)
{

    vector<int> dist(adj_list.size(), INT_MAX);
    vector<bool> visited(adj_list.size(), false);
    queue<int> q;

    visited[s] = true;
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i : adj_list[u])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
                dist[i] = dist[u] + 1; // adding `1` to the source dist. to form current dist
            }
        }
    }

    for (int i : dist)
    {
        cout << i << " ";
    }
    cout << "\n";
}

// ----------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------
//  -   shortest path in DAG can be found using topological sort of the DAG
//      as topo will give us the node which is less dependent on the other nodes
//      and by calculating their dist., we can further calc the dist. of other nodes
// ----------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------
//  -   MST (Minimum Spanning Tree) =>  ~ weightd
//                                      ~ connected
//                                      ~ undirected
//                                      ~ for n vertex : (n-1) edges should be there only

//  -   Algorithm used is PRIMS ALGO. it is a greedy algo

//  `   Find the minimum edge which connects the MST to the remaining vertex
// ----------------------------------------------------------------------------------



/**
 * 
 *  Aim: Find the MST with minimum total edge cost
 * 
 ***/

// -    Prims algo, is divided into 3 parts:    1. intialization
//                                              2. select the minimum dist of vertex which is not the part of mset
//                                              3. Update its immediate naughbur with min. weight




/**
 * 
 * Aim: Single source shortest path (Dijkstra algo)
 * 
**/



int main()
{

    // int v = 8;
    // vector<vector<int>> adj_list(v);

    // // --------------------------- with cycle -----------------------
    // addEdge(adj_list, 0, 1);
    // addEdge(adj_list, 0, 2);
    // addEdge(adj_list, 1, 2);
    // addEdge(adj_list, 1, 3);
    // addEdge(adj_list, 2, 3);
    // addEdge(adj_list, 2, 4);
    // addEdge(adj_list, 3, 4);

    // addEdge(adj_list, 5, 6);
    // addEdge(adj_list, 5, 7);
    // addEdge(adj_list, 6, 7);

    // addEdge(adj_list, 0, 1);
    // addEdge(adj_list, 1, 2);
    // addEdge(adj_list, 0, 3);
    // addEdge(adj_list, 3, 7);
    // addEdge(adj_list, 3, 4);
    // addEdge(adj_list, 4, 7);
    // addEdge(adj_list, 7, 6);
    // addEdge(adj_list, 4, 6);
    // addEdge(adj_list, 4, 5);
    // addEdge(adj_list, 5, 6);
    // --------------------------------------------------------------

    // ----------------------- Directed graph -----------------------

    // int v = 6;
    // vector<vector<int>> adj_list(v);

    // addDirectedEdge(adj_list, 0, 1);
    // addDirectedEdge(adj_list, 0, 4);
    // addDirectedEdge(adj_list, 1, 2);
    // addDirectedEdge(adj_list, 2, 3);
    // addDirectedEdge(adj_list, 5, 3);
    // addDirectedEdge(adj_list, 4, 5);
    // addDirectedEdge(adj_list, 4, 2);

    // addDirectedEdge(adj_list, 0, 1);
    // addDirectedEdge(adj_list, 1, 2);
    // addDirectedEdge(adj_list, 1, 4);
    // addDirectedEdge(adj_list, 4, 3);
    // addDirectedEdge(adj_list, 2, 3);
    // addDirectedEdge(adj_list, 5, 0);
    // addDirectedEdge(adj_list, 5, 6);
    // addDirectedEdge(adj_list, 6, 7);
    // addDirectedEdge(adj_list, 7, 5);

    // --------------------------------------------------------------

    // -------------------------- without cycle----------------------
    // addEdge(adj_list, 1, 2);
    // addEdge(adj_list, 2, 3);
    // addEdge(adj_list, 3, 4);
    // --------------------------------------------------------------

    // disp_adj_list(adj_list);

    // cout << "BFS:\n";
    // bfs(adj_list, 4);

    // cout << "BFS(Discontinue Graph):\n";
    // bfs_discontinues(adj_list);

    // dfs_helper(adj_list);

    // cout << "Is cycle: " << isCycle(adj_list);

    // topologicalOrder_bfs(adj_list);
    // topologicalOrder_dfs(adj_list);


    // cout << isCycleDirectedGraph(adj_list);

    // allVertexShortestDistFromSource(adj_list, 7);

    return 0;
}