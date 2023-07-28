class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        leftpos, rightpos = -1, -1
        l, r = 0, len(nums)-1
        
        while l <= r:   
            mid = (r+l) // 2
            if nums[mid] == target: 
                while mid-1 >= 0 and nums[mid-1] == target:
                    mid -= 1
                leftpos = mid
                while mid+1 <= len(nums)-1 and nums[mid+1] == target:
                    mid += 1
                rightpos = mid
                break                
            if nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1

        return [leftpos, rightpos]