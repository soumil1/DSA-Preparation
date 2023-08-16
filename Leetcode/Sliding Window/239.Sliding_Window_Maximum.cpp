class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<int> q; // indices
        int l = 0, r = 0;

        while (r < nums.size()) {
            // pop smaller val from q
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);

            // remove left val from window
            if (l > q.front()) {
                q.pop_front();
            }

            if ((r - l) >= k - 1) {
                output.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }

        return output;
    }
};