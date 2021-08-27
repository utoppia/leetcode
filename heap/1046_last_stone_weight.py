from heapq import heappush, heappop
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        queue = []
        # init the heap
        for stone in stones:
            heappush(queue, -stone)

        while len(queue) >= 2:
            u = -heappop(queue)
            v = -heappop(queue)
            if u > v:
                heappush(queue, v-u)

        if queue:
            return -queue[0]
        else:
            return 0
