from heapq import heappush, heappop
class Solution:
  def nthUglyNumber(self, n: int) -> int:
    # heap and set
    queue = [1]
    cur = None
    s = set([1])
    for _ in range(n):
      cur = heappop(queue)
      if 2 * cur not in s:
        s.add(2 * cur)
        heappush(queue, 2 * cur)
      if 3 * cur not in s:
        s.add(3 * cur)
        heappush(queue, 3 * cur)
      if 5 * cur not in s:
        s.add(5 * cur)
        heappush(queue, 5 * cur)
    return cur

