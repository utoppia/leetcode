class Solution:
  def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
    # heap
    prices = []
    for i in range(len(wage)):
      prices.append((wage[i]/quality[i], wage[i], quality[i]))
    prices.sort()

    heap = []
    for i in range(k-1):
      heapq.heappush(heap, -prices[i][2])
    total = -sum(heap)

    ans = float('inf')

    for i in range(k-1, len(wage)):
      _, w, q = prices[i]
      ans = min(ans, w * (total + q) / q)
      if heap and -heap[0] > q:
        total += heapq.heappop(heap)
        total += q
        heapq.heappush(heap, -q)

    return ans
