from heapq import heappush, heappop
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # heap
        queue = []
        pos = 0
        for num in nums:
            if pos < k:
                heappush(queue, num)
                pos += 1
            elif queue[0] < num:
                heappop(queue)
                heappush(queue, num)
        return queue[0]
