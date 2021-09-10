class Solution:
  def findIntegers(self, n: int) -> int: 
    dp = [0] * 31
    dp[0], dp[1] = 1, 1
    for i in range(2, 31):
      dp[i] = dp[i-1] + dp[i-2]

    val = 1 << 29
    ans = 0
    node = 0
    for i in range(29, -1, -1):
      if n & val: # has right nodes
        n -= val
        ans += dp[i+1]
        if node == 1: # has two nodes with value '1'
          break
        node = 1
      else:
        node = 0

      if i == 0:
        ans += 1
      val >>= 1
    return ans

