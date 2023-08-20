class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = vector<int>();
        }
        
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(m, 0);
        for (int i = 0; i < m; ++i) {
            groupGraph[i] = vector<int>();
        }
        
        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                
                if (group[i] != group[prev]) {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];
                    
                    groupGraph[prevItemGroup].push_back(currItemGroup);
                    groupIndegree[currItemGroup]++;
                }
            }
        }
        
        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);
        
        unordered_map<int, vector<int>> groupToItemsInOrder;
        for (int item : itemOrder) {
            int itemGroup = group[item];
            groupToItemsInOrder[itemGroup].push_back(item);
        }
        
        vector<int> answerList;
        for (int groupIndex : groupOrder) {
            answerList.insert(answerList.end(), groupToItemsInOrder[groupIndex].begin(), groupToItemsInOrder[groupIndex].end());
        }
        
        return answerList;
    }
    
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> que;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        
        vector<int> result;
        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            result.push_back(curr);
            
            for (int v : adj[curr]) {
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return result.size() == adj.size() ? result : vector<int>();
    }
};
