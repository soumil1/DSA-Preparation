class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)  # Hashmap, count each character
        maxHeap = [[-count, char] for char, count in count.items()]  
        heapq.heapify(maxHeap)  # O(n)

        previous = None
        result = ""
        while maxHeap or previous:
            if previous and not maxHeap: 
                return ""
            neg_count, char = heapq.heappop(maxHeap) 
            result += char
            neg_count += 1

            if previous:
                heapq.heappush(maxHeap, previous)  
                previous = None

            if neg_count < 0: 
                previous = [neg_count, char]

        return result
