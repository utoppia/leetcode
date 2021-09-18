class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    S = set(wordDict)
    n = len(s)
    dp = [False] * n

    for i in range(n):
      j = i
      while j >= 0:
        if (j==0 or dp[j-1]) and s[j:i+1] in S:
          dp[i] = True
          break
        j -= 1
    
    return dp[n-1]
