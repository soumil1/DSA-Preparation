# Question asked in 
# Finding Long Drive i.e. to help Geek find the longest distance he can travel starting from each city in the 'query' array (GeeksForGeeks Job A Thon - dated 21 July, 2023)

from typing import List

class Solution:
    def longDrive(self, n: int, edges: List[List[int]], q: int, query: List[int]) -> List[int]:
        # Create an adjacency list to represent the tree structure
        adj_list = [[] for _ in range(n + 1)]
        for u, v, weight in edges:
            adj_list[u].append((v, weight))
            adj_list[v].append((u, weight))

        memo = {}
        def dfs(node, parent):
            if (node, parent) in memo:
                return memo[(node, parent)]
            max_dist = 0
            for neighbor, weight in adj_list[node]:
                if neighbor != parent:
                    max_dist = max(max_dist, dfs(neighbor, node) + weight)
            memo[(node, parent)] = max_dist
            return max_dist

        result = []
        for start_city in query:
            max_distance = dfs(start_city, 0)
            result.append(max_distance)

        return result
