class Solution:
  def minimumEffortPath(self, heights: List[List[int]]) -> int:
    # dijkstra and heap optimal
    directions = [[1,0], [0, 1], [-1, 0], [0, -1]]
    n, m = len(heights), len(heights[0])
    efforts = [[-1] * m for _ in range(n)]
    efforts[0][0] = 0
    heap = [(0, 0, 0)]
    visted = {}
    while heap:
      val, u, v = heap[0]
      if (u, v) in visted:
        heapq.heappop(heap)
        continue

      heapq.heappop(heap)
      visted[(u,v)] = 1
      for dx, dy in directions:
        if (x := u + dx) >=0 and (y := v + dy) >= 0 and x < n and y < m:
          if (x, y) in visted:
            continue
          d = max(efforts[u][v], abs(heights[u][v] - heights[x][y]))
          if efforts[x][y] == -1 or d < efforts[x][y]:
            efforts[x][y] = d
            heapq.heappush(heap, (d, x, y))

    return efforts[n-1][m-1]
