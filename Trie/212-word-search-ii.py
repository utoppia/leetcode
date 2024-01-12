class Trie:
  def __init__(self) -> None:
    self.children = defaultdict(Trie)
    self.word = ""

  def insert(self, word: str) -> None:
    cur = self
    for c in word:
      cur = cur.children[c]
    cur.word = word

class Solution:
  def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
    trie = Trie()
    for word in words:
      trie.insert(word)

    def dfs(node: 'Trie', i: int, j: int) -> None:
      nonlocal board, n, m, ans
      if board[i][j] not in node.children:
        return

      ch = board[i][j]
      node = node.children[ch]

      if node.word != "":
        ans.add(node.word)

      board[i][j] = '#'
      for x, y in [[i+1, j], [i-1,j], [i, j+1], [i, j-1]]:
        if 0 <= x < n and 0 <= y < m:
          dfs(node, x, y)
      board[i][j] = ch

    ans = set([])
    n, m = len(board), len(board[0])

    for i in range(n):
      for j in range(m):
        dfs(trie, i, j)

    return list(ans)


