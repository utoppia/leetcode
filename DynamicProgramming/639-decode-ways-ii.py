class Solution:
  def numDecodings(self, s: str) -> int:
    MOD = 10 ** 9 + 7
    s = " " + s
    n = len(s)
    dp = [0] * n
    dp[0] = 1
    if s[1] == '*':
      dp[1] = 9
    elif s[1] == '0':
      return 0
    else:
      dp[1] = 1

    for i in range(2, n):
      if s[i] == '0':
        if s[i-1] == '*':
          dp[i] = dp[i-2] * 2
        elif s[i-1] == '1' or s[i-1] == '2':
          dp[i] = dp[i-2]
        else:
          return 0
      elif s[i] == '*':
        dp[i] = dp[i-1] * 9
        if s[i-1] == '1':
          dp[i] += dp[i-2] * 9
        if s[i-1] == '2':
          dp[i] += dp[i-2] * 6
        if s[i-1] == '*':
          dp[i] += dp[i-2] * 15
      else:
        dp[i] = dp[i-1]
        if s[i-1] == '1':
          dp[i] += dp[i-2]
        elif s[i-1] == '2':
          if int(s[i]) <= 6:
            dp[i] += dp[i-2]
        elif s[i-1] == '*':
          dp[i] += dp[i-2]
          if int(s[i]) <= 6:
            dp[i] += dp[i-2]

      dp[i] = dp[i] % MOD

    return dp[n-1]

