class Solution:
  def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
    def cmp(a: List[int], b: List[int]) -> (int, List[int]):
      if a[1] < b[0]:
        return (-1, None)

      if a[0] > b[1]:
        return (1, None)

      if a[0] <= b[0]:
        if a[1] >= b[1]:
          return (1, b)
        else:
          return (-1, [b[0], a[1]])
      else:
        if b[1] >= a[1]:
          return (-1, a)
        else:
          return (1, [a[0], b[1]])

    i = j = 0
    n = len(firstList)
    m = len(secondList)
    ans = []
    while i < n and j < m:
      flag, c = cmp(firstList[i], secondList[j])
      if c:
        ans.append(c)
      if flag == 1:
        j += 1
      else:
        i += 1
    return ans
