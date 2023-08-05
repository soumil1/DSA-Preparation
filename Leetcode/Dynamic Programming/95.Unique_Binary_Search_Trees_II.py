class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def dfs(nums):
            if not nums:
                return [None]

            ans = []

            for i in range(len(nums)):
                leftTrees = dfs(nums[:i])
                rightTrees = dfs(nums[i+1:])
                for l in leftTrees:
                    for r in rightTrees:
                        root = TreeNode(nums[i])
                        root.left = l
                        root.right = r
                        ans.append(root)
            return ans

        nums = list(range(1, n+1))

        return dfs(nums)
