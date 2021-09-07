class Solution:
  def balancedStringSplit(self, s: str) -> int:
    ans = 0
    n = len(s)
    if n == 0:
      return 0

    def check(ch: str) -> int:
      return 1 if ch == 'L' else -1

    cur = check(s[0])
    i = 1
    while i < n:
      cur += check(s[i])
      if cur == 0:
        ans += 1
      i += 1
    return ans
