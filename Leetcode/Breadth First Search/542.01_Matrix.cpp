class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Initializing everything to 0 
        vector<vector<int>> ans(m, vector<int>(n, 0));
        unordered_set<pair<int, int>, PairHash> visited; // Use custom hash function

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    visited.insert({i, j});
                }
            }
        }

        int distance = 0;

        while (!q.empty()) {
            int qSize = q.size();
            for (int k = 0; k < qSize; ++k) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if (mat[i][j] == 1) {
                    ans[i][j] = distance;
                }
                
                for (const auto& d : directions) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && visited.find({ni, nj}) == visited.end()) {
                        q.push({ni, nj});
                        visited.insert({ni, nj});
                    }
                }
            }
            ++distance;
        }

        return ans;
    }

private:
    struct PairHash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
};
