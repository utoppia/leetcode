class Solution:
  def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    # heap
    heap = []
    for i in range(k):
      heapq.heappush(heap, (-nums[i], i))

    ans = [-heap[0][0]]
    for i in range(k, len(nums)):
      heapq.heappush(heap, (-nums[i], i))
      while heap and i - heap[0][1] >= k:
        heapq.heappop(heap)
      ans.append(-heap[0][0])
    return ans
