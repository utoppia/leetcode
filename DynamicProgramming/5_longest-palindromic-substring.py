class Solution:
  def longestPalindrome(self, s: str) -> str:

    def find(l:int, r:int) -> [int, int]:
      nonlocal s, n
      while l >= 0 and r < n and s[l] == s[r]:
        l -= 1
        r += 1
      return l + 1, r - 1

    n = len(s)
    ans = 0
    x, y = 0, 0
    for i in range(n-1):
      l, r = find(i, i)
      if r - l  > ans:
        ans = r - l
        x, y = l, r
      l, r = find(i, i+1)
      if r - l > ans:
        x, y = l, r
        ans = r - l
    return s[x:y+1]
