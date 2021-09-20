from heapq import heappush, heappop
class Solution:
  def minStoneSum(self, piles: List[int], k: int) -> int:
    # In every step, we should choose the pile with most stones
    # heap
    queue = []
    for pile in piles:
      heappush(queue, -pile)

    for _ in range(k):
      val = -heappop(queue)
      val -= val // 2
      heappush(queue, -val)

    return -sum(queue)
