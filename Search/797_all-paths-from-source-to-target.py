class Solution:
  def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

    def dfs(u: int, path: List[int]) -> None:
      nonlocal ans, graph, visited, des
      if u == des:
        ans.append(path)
        return

      for v in graph[u]:
        if not visited[v]:
          visited[v] = True
          dfs(v, path + [v])
          visited[v] = False

    des = len(graph) - 1
    ans = []
    visited = [False] * (des + 1)
    visited[0] = True

    dfs(0, [0])
    return ans
