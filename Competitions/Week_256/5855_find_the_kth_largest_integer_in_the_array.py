class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
      # heap
      heap = []
      index = 0
      for num in nums:
        if index < k:
          heapq.heappush(heap, int(num))
          index += 1
        elif heap[0] < int(num):
          heapq.heappop(heap)
          heapq.heappush(heap, int(num))
      return str(heap[0])

