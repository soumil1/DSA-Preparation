// Question asked in Amazon Microsoft Flipkart Samsung Ola Cabs Adobe SAP Labs
// Find BFS (Breadth First Search) of the graph starting from 0 (GeeksForGeeks POTD - dated 31 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;    

// Driver Code Ends

class Solution{
    public:
        // Function to return Breadth First Traversal of given graph.
        vector<int> bfsOfGraph(int V, vector<int> adj[])
        {
            // Code here
            int vertices[V] = {0}; // make all false at first
            vertices[0] = 1;       // make 0 true and push in queue
            queue<int> q;
            q.push(0);
            vector<int> bfs;
            while (!q.empty())
            {
                int n = q.front(); // n=0
                q.pop();
                bfs.push_back(n);      // bfs=0
                for (auto it : adj[n]) // adj[0]=1 2 3
                {
                    if (!vertices[it]) // if 1 is visited then dont visit it again
                    {
                        vertices[it] = 1; // mark it true
                        q.push(it);       // and push it in queue
                    }
                }
            }
            return bfs; // finally return bfs
        }
};