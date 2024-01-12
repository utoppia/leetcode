class Solution:
  def getRow(self, rowIndex: int) -> List[int]:

    ans = [1]

    for _ in range(rowIndex):
      tmp = [1]
      for j in range(1, len(ans)):
        tmp.append(ans[j] + ans[j-1])
      tmp.append(1)

      ans = tmp
    return ans
