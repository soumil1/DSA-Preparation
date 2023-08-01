class Solution:
    def helper(self, index, n, l, k, ans):
        if k == 0:
            # formed a combination of size k, so append 1 to the ans
            ans.append(l.copy())
        for j in range(index, n+1):
            # generate combinations with elements from index to n
            if k != 0:
                self.helper(j+1, n, l+[j], k-1, ans)

    def combine(self, n: int, k: int) -> List[List[int]]:
        l = []
        ans = []
        self.helper(1, n, l, k, ans)
        return ans
