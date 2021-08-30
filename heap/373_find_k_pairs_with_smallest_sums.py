class Solution:
  def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
    # simulation
    # min-heap
    n = len(nums1)
    heap = []
    for a in nums2:
      heapq.heappush(heap, (nums1[0] + a, 0, a))

    ans = []
    index = 0
    while index < k and heap:
      _, i, a = heapq.heappop(heap)
      ans.append([nums1[i], a])
      index += 1
      if i + 1 < n:
        heapq.heappush(nums1[i+1] + a, i+1, a)
    return ans
