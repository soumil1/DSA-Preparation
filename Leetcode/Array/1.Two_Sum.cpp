class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int k = 0;k<nums.size();k++) {
            if(mpp.find(target - nums[k]) != mpp.end()) {
                ans.push_back(mpp[target-nums[k]]);
                ans.push_back(k);
                return ans;
            }
            mpp[nums[k]] = k;
        }
        return ans;
    }
};