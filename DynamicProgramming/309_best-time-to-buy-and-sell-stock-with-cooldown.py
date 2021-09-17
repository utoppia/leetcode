class Solution:
  def maxProfit(self, prices: List[int]) -> int:
    n = len(prices)
    dp = [[0,0,0] for _ in range(n)]

    # dp[i][0] has a stock
    # dp[i][1] without stock but cooldowned
    # dp[i][2] without stock and not cooldown

    dp[0][0] = - prices[0]

    for i in range(1, n):
      dp[i][0] = max(dp[i-1][2] - prices[i], dp[i-1][0], -prices[i])
      dp[i][1] = max(dp[i-1][0] + prices[i], 0)
      dp[i][2] = max(dp[i-1][1], dp[i-1][2])

    return max(dp[n-1][1:])

