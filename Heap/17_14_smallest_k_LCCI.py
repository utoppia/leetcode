class Solution:
  def smallestK(self, arr: List[int], k: int) -> List[int]:
    # max-heap
    if k == 0:
      return []
    heap = []
    index = 0
    for num in arr:
      if index < k:
        heapq.heappush(heap, -num)
        index += 1
      elif -heap[0] > num:
        heapq.heappop(heap)
        heapq.heappush(heap, -num)

    return [-val for val in heap]
