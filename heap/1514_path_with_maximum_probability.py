class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
      # Dijkstra Algorithm
      # max-heap

      adj = [[] for _ in range(n)]
      for i in range(len(edges)):
        adj[edges[i][0]].append((edges[i][1], succProb[i]))
        adj[edges[i][1]].append((edges[i][0], succProb[i]))

      pro = [0] * n
      visited = [False] * n

      # init
      heap = [(-1, start)]
      pro[start] = 1

      while heap:
        p, u = heap[0]
        if visited[u]:
          heapq.heappop(heap)

        visited[u] = True

        for v, q in adj[u]:
          if not visited[v] and pro[v] < -p * q:
            pro[v] = -p * q
            heapq.heappush(heap, (-pro[v], v))

      return pro[end]
