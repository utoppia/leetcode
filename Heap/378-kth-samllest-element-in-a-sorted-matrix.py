from heapq import heappush, heappop
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        # heap
        # O(n^2 log n)
        queue = []
        for row in matrix:
            for ele in row:
                heappush(queue, ele)

        ans = 0
        for _ in range(k):
            ans = heappop(queue)
        return ans
