class Solution:
  def coinChange(self, coins: List[int], amount: int) -> int:

    dp = [-1] * (amount + 1)
    dp[0] =0

    for a in coins:
      for i in range(1, amount + 1):
        if i - a >= 0 and dp[i - a] != -1:
          if dp[i] == -1:
            dp[i] = dp[i-a] + 1
          else:
            dp[i] = min(dp[i], dp[i-a] + 1)

    return dp[amount]

