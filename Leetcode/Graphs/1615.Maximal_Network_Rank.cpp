class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> count(n, 0);
        vector<vector<int>> direct(n, vector<int>(n, 0));

        // Iterating through each road and updating counts, edges
        for (const auto &road : roads)
        {
            count[road[0]]++;
            count[road[1]]++;
            direct[road[0]][road[1]] = 1;
            direct[road[1]][road[0]] = 1;
        }

        int rank = 0;
        // Iterate through all pair of nodes and calculate maximal network
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // check direct connection for i and j
                int currentRank = count[i] + count[j] - direct[i][j];
                // update rank with max value
                rank = max(rank, currentRank);
            }
        }

        return rank;
    }
};
