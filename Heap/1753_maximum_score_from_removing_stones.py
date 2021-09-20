from heapq import heappush, heappop
class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
      # simulation
      # heap
      score = 0
      queue = []
      heappush(queue, -a)
      heappush(queue, -b)
      heappush(queue, -c)

      while len(queue) > 1:
        u = heappop(queue)+1
        v = heappop(queue)+1
        score += 1
        if u:
          heappush(queue, u)
        if v:
          heappush(queue, v)

      return score

