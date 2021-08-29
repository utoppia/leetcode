class Solution:
    def minSetSize(self, arr: List[int]) -> int:
      # heap
      # we always choose the value with maximum count 
      # in every steps
      heap = []
      n = len(arr)
      for cnt in collections.Counter(arr).values():
        heapq.heappush(heap, -cnt)

      cur, ans = 0, 0
      while 2 * cur < n:
        cur -= heapq.heappop(heap)
        ans += 1
      return ans
