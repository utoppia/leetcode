class Solution:
  def solve(self, board: List[List[str]]) -> None:
    """
    Do not return anything, modify board in-place instead.
    """
    def update(i: int, j: int) -> None:
      dxy = [[1, 0], [-1, 0], [0, 1], [0, -1]]
      flag = True
      path = []
      queue = [(i, j)]
      nonlocal visited
      nonlocal board
      visited[i][j] = True
      while queue:
        i, j = queue.pop(0)
        path.append((i, j))
        for dx, dy in dxy:
          u = i + dx
          v = j + dy
          if u < 0 or u >= n or v < 0 or v >= m:
            flag = False
            continue
          if visited[u][v] or board[u][v] == 'X':
            continue
          visited[u][v] = True
          queue.append((u, v))
      if flag:
        for i, j in path:
          board[i][j] = 'X'

    n, m = len(board), len(board[0])

    visited = [[False] * m for _ in range(n)]

    for i in range(n):
      for j in range(m):
        if board[i][j] == 'O' and not visited[i][j]:
          update(i, j)
