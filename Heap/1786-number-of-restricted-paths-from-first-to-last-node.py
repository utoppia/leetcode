class Solution:
  def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
    # Dijkstra Algorithm
    # heap

    adj = [[] for _ in range(n+1)]
    for u, v, val in edges:
      adj[u].append((v, val))
      adj[v].append((u, val))

    dis = self.shortestPath(adj, n)

    MODULER = 10 ** 9 + 7
    
    heap = [(0, n)]
    ans = [0] * (n + 1)
    visited = [False] * (n + 1)
    ans[n] = 1
    visited[n] = True

    while heap:
      cnt, u = heap[0]
      heapq.heappop(heap)

      for v, _ in adj[u]:
        if dis[u] < dis[v]:
          ans[v] += ans[u]
        if not visited[v]:
          heapq.heappush(heap, (dis[v], v))
          visited[v] = True

    return ans[1] % MODULER


  def shortestPath(self, adj: List[List[int]], start: int) -> List[int]:
    path = [-1] * len(adj)

    # init
    heap = [(0, start)]
    visited = [False] * len(adj)
    path[start] = 0

    while heap:
      val, u = heapq.heappop(heap)
      if visited[u]:
        continue

      visited[u] = True
      for v, dis in adj[u]:
        if path[v] == -1 or  dis + val < path[v]:
          
          path[v] = dis + val
          heapq.heappush(heap, (path[v], v))
    return path
