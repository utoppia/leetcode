class Solution:
  def avoidFlood(self, rains: List[int]) -> List[int]:
    # heap

    n = len(rains)
    nxt = [-1] * n
    rain_dates = {}
    for i in range(n-1, -1, -1):
      if rains[i]:
        if rains[i] in rain_dates:
          nxt[i] = rain_dates[rains[i]]
        rain_dates[rains[i]] = i

    print(nxt)
    ans = [-1] * len(rains)
    pool = {}
    heap = []

    for i in range(len(rains)):
      if rains[i]:
        if rains[i] in pool:
          return []
        pool[rains[i]] = 1
        if nxt[i] != -1:
          heapq.heappush(heap, (nxt[i], rains[i]))

      else:
        if heap:
          _, p = heapq.heappop(heap)
          del pool[p]
          ans[i] = p
        else:
          ans[i] = 1

    return ans


