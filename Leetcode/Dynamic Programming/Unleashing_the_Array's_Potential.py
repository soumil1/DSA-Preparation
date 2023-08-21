from typing import List

class Solution:
    def maxValue(self, n: int, arr: List[int]) -> int:
        max_geek_value = 0
        
        max_right = [0] * n
        max_right[n - 1] = arr[n - 1]
        
        for i in range(n - 2, -1, -1):
            max_right[i] = max(max_right[i + 1], arr[i])
        
        max_left = arr[0]
        
        for i in range(1, n - 1):
            geek_value = (max_left - arr[i]) * max_right[i + 1]
            max_geek_value = max(max_geek_value, geek_value)
            max_left = max(max_left, arr[i])
        
        return max(max_geek_value, 0)