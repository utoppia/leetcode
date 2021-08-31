class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
      # sort and heap
      n = len(capital)
      projects = [(capital[i], -profits[i]) for i in range(n)]
      projects.sort()

      cnt = 0
      heap = []
      pos = 0
      while cnt < k:
        while pos < n and projects[pos][0] <= w:
          heapq.heappush(heap, projects[pos][1])
          pos += 1

        cnt += 1
        if heap:
          w -= heapq.heappop(heap)
        else:
          break
      return w

