class Solution:
  @lru_cache
  def generateParenthesis(self, n: int) -> List[str]:
    # (a)b
    if n == 0:
      return [""]
    ans = []
    for i in range(n):
      for left in self.generateParenthesis(i):
        for right in self.generateParenthesis(n-1-i):
          ans.append("({}){}".format(left, right))
    return ans
