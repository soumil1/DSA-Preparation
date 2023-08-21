class Solution
{
    public:
    vector<int> geeksJourney(vector<int>& geeksTown, int n, 
                             vector<int>& journey, int m, 
                             vector<vector<int>>& queries, int q)
    {
        // code here
         vector<int> result;
        vector<pair<int, int>> subarrayIndices; // To store the indices of geeksTown subarrays

        for (int i = 0; i <= m - n; ++i) {
            bool match = true;
            for (int j = 0; j < n; ++j) {
                if (geeksTown[j] != journey[i + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                subarrayIndices.push_back(make_pair(i, i + n - 1));
            }
        }

        for (int i = 0; i < q; ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            int count = 0;

            for (const auto& indices : subarrayIndices) {
                if (indices.first >= left && indices.second <= right) {
                    ++count;
                }
            }

            result.push_back(count);
        }

        return result;
    }
};