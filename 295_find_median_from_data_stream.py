import heapq
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self._q1 = []
        self._q2 = []
        self._index = 0


    def addNum(self, num: int) -> None:
        if self._index == 0:
            heapq.heappush(self._q1, -num)
            self._index += 1
            return
        
        if num <= -self._q1[0]:
            a = -heapq.heappop(self._q1)
            heapq.heappush(self._q1, -num)
            heapq.heappush(self._q2, a)
        else:
            heapq.heappush(self._q2, num)
        if len(self._q2) > len(self._q1):
            heapq.heappush(self._q1, -heapq.heappop(self._q2))
        self._index += 1

    def findMedian(self) -> float:
        if self._index % 2 == 1:
            return -self._q1[0]
        else:
            return (-self._q1[0] + self._q2[0]) / 2



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
