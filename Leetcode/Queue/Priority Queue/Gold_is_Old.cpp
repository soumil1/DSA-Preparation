// Question asked in
// Finding the maximum of experience point you can accumulate (GeeksForGeeks Weekly Contest - dated 23 July, 2023)

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    long long MaxXP(int n, int k, int initial_exp, vector<int> &exp_req, vector<int> &exp_gain)
    {
        vector<pair<int, int>> quests(n);
        for (int i = 0; i < n; i++)
        {
            quests[i] = make_pair(exp_req[i], exp_gain[i]);
        }
        sort(quests.begin(), quests.end());

        priority_queue<int> pq;
        long long current_exp = initial_exp;

        for (int i = 0; i < n; i++)
        {
            while (!pq.empty() && current_exp < quests[i].first && k > 0)
            {
                current_exp += pq.top();
                pq.pop();
                k--;
            }
            if (k == 0)
            {
                break;
            }
            if (current_exp >= quests[i].first)
            {
                pq.push(quests[i].second);
            }
        }
        while (!pq.empty() && k > 0)
        {
            current_exp += pq.top();
            pq.pop();
            k--;
        }
        return current_exp;
    }
};