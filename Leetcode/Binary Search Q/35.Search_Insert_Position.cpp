#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid; // Target found, return its index.
            } else if (nums[mid] < target) {
                start = mid + 1; // Target should be in the right half.
            } else {
                end = mid - 1; // Target should be in the left half.
            }
        }

        return start; // Target not found, return the index where it should be inserted.
    }
};