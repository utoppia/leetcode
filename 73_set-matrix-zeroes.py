class Solution:
  def setZeroes(self, matrix: List[List[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """

    n, m = len(matrix), len(matrix[0])
    h_flag = v_flag = False

    for i in range(n):
      for j in range(m):
        if matrix[i][j] == 0:
          matrix[i][0] = 0
          matrix[0][j] = 0

          if i == 0:
            h_flag = True
          if j == 0:
            v_flag = True

    for i in range(1, n):
      if matrix[i][0] == 0:
        for j in range(m):
          matrix[i][j] = 0

    for j in range(1, m):
      if matrix[0][j] == 0:
        for i in range(n):
          matrix[i][j] = 0

    if h_flag:
      for j in range(m):
        matrix[0][j] = 0

    if v_flag:
      for i in range(n):
        matrix[i][0] = 0

      
