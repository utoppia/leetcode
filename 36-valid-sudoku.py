class Solution:
  def isValidSudoku(self, board: List[List[str]]) -> bool:
    def valid(pan: List[str]) -> bool:
      isCheck = [False] * 10
      for ch in pan:
        if ch != '.' and 0 < int(ch) < 10:
          p = int(ch)
          if isCheck[p]:
            return False
          else:
            isCheck[p] = True
      return True

    for i in range(9):
      if not valid(board[i]):
        return False

      tmp = [board[j][i] for j in range(9)]
      if not valid(tmp):
        return False

    for i in range(0,9,3):
      for j in range(0, 9, 3):
        tmp = board[i][j:j+3] + board[i+1][j:j+3] + board[i+2][j:j+3]
        if not valid(tmp):
          return False

    return True
