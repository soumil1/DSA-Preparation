class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        nums = set(nums)
        longest_sequence = 0

        for num in nums:
            # If num - 1 is not in the set, it means num is the start of a consecutive sequence.
            if num - 1 not in nums:
                current_sequence = 1
                next_num = num + 1

                # Count the length of the consecutive sequence starting from num.
                while next_num in nums:
                    current_sequence += 1
                    next_num += 1

                longest_sequence = max(longest_sequence, current_sequence)

        return longest_sequence
