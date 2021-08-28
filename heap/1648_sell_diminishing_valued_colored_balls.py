class Solution:
  def maxProfit(self, inventory: List[int], orders: int) -> int:
    # math
    # heap
    MODULER = 10 ** 9 + 7
    heap = [(0, 1)]
    for value, cnt in collections.Counter(inventory).items():
      heapq.heappush(heap, (-value, cnt))
    ans = 0

    while orders:
      u = heapq.heappop(heap)
      v = heapq.heappop(heap)

      if orders >= u[1] * (v[0] - u[0]):
        ans += u[1] * (u[0] + v[0] - 1) * (u[0] - v[0]) // 2
        orders -= u[1] * (v[0] - u[0])
        heapq.heappush(heap, (v[0], v[1]+u[1]))
      else:
        cur = -u[0]
        p = orders // u[1]
        ans += u[1] * (2 * cur - p + 1) * p // 2 + (orders % u[1]) * (cur - p)
        orders = 0
    return ans % MODULER

