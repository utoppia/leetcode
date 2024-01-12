class Solution:
  def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
    # graph and min-heap
    edges = [[] for _ in range(n + 1)]
    for u, v, w in times:
      edges[u].append((v, w))
    ans = [-1] * (n + 1)
    ans[k] = 0
    heap = [(0, k)]
    while heap:
      if heap[0][0] > ans[heap[0][1]]:
        heapq.heappop(heap)
        continue

      time, u = heapq.heappop(heap)
      for v, w in edges[u]:
        if ans[v] == -1 or ans[v] > time + w:
          ans[v] = time + w
          heapq.heappush(heap, (ans[v], v))
    if min(ans[1:]) == -1:
      return -1
    else:
      return max(ans)


