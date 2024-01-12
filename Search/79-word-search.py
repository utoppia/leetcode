class Solution:
  def exist(self, board: List[List[str]], word: str) -> bool:

    def dfs(x: int, y: int, word: str) -> bool:
      nonlocal n, m, board
      if board[x][y] != word[0]:
        return False
      
      if len(word) == 1:
        return True

      board[x][y] = '#'
      for u, v in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
        if 0 <= u < n and 0 <= v < m:
          if dfs(u, v, word[1:]):
            return True
      board[x][y] = word[0]

      return False

    n, m = len(board), len(board[0])

    for x in range(n):
      for y in range(m):
        if dfs(x, y, word):
          return True

    return False
