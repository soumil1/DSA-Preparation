// Using Floyd-Warshall Algorithm
// Question asked in
// Check if a graph with given adjacencies can be constructed satisfying conditions (GeeksForGeeks Contest 117 - dated 28 August, 2023)

// Driver Code Starts

import java.io.*;
import java.util.*;

// Driver Code Ends

class Solution 
{ 
    boolean graph(int N, int adj[][]) {
        int[][] dist = new int[N][N];
        
        // Initialize the distance matrix with the given adjacency matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = adj[i][j];
            }
        }
        
        // Floyd-Warshall algorithm to calculate shortest distances
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        // Check if the calculated shortest distances match the given distances
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] != adj[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
