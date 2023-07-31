// Question asked in Amazon Samsung Intuit Accolite
// Finde DFS Traversal of the Graph (GeeksForGeeks POTD - dated 01 August, 2023)

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

#include <vector>

class Solution {
    public:
    void dfs(int vertex, std::vector<int> &vis, std::vector<int> &ans, std::vector<int> adj[])
    {
        vis[vertex] = true;
        ans.push_back(vertex);
        for (int x : adj[vertex])
        {
            if (!vis[x])
                dfs(x, vis, ans, adj);
        }
    }

    std::vector<int>
        dfsOfGraph(int V, std::vector<int> adj[])
    {
        if (V == 0)
            return {}; // Handle the case when the graph has no vertices.

        std::vector<int> vis(V, false); // Create a boolean vector to track visited vertices.
        std::vector<int> ans;           // Create a vector to store the DFS traversal sequence.

        dfs(0, vis, ans, adj);
        return ans; // dfs traversal sequence returned
    }
};