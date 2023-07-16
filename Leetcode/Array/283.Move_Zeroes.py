class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pointer = 0     # index of first zero
        move = 0  # index of first non-zero
        for i in range(0, len(nums)): # move pointer to first zero
            if(nums[move] == 0): # if move is zero, move it to the end
                move = move + 1 # move to next non-zero
            else: # if move is non-zero, swap it with pointer
                temp = nums[pointer] # swap
                nums[pointer] = nums[move] 
                nums[move] = temp 
                pointer += 1 # move pointer to next zero
                move += 1 # move move to next non-zero
