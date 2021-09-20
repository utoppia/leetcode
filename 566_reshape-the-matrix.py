class Solution:
  def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
    r1, c1 = len(mat), len(mat[0])
    
    if r * c != r1 * c1:
      return mat
    ret = []
    i1, j1 = 0, 0
    for i in range(0, r):
      temp = []
      for j in range(0, c):
        if j1 == c1:
          i1 += 1
          j1 = 0
        temp.append(mat[i1][j1])
        j1 += 1
      ret.append(temp)
    return ret
