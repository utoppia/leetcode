import heapq
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self._queue = []
        self._index = 0
        self.K = k

        for val in nums:
            self._insert(val)

    def _insert(self, val: int):
        if self._index < self.K:
            heapq.heappush(self._queue, val)
            self._index += 1
        elif self._queue[0] < val:
            heapq.heappop(self._queue)
            heapq.heappush(self._queue, val)


    def add(self, val: int) -> int:
        self._insert(val)
        return self._queue[0]



# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
