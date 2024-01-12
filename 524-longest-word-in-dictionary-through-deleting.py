class Solution:
  def findLongestWord(self, s: str, dictionary: List[str]) -> str:
    ans = ""
    for t in dictionary:
      i, j = 0, 0
      while i < len(s) and j < len(t):
        if s[i] == t[j]:
          j += 1
        i += 1
        if j == len(t):
          if len(t) > len(ans) or (len(t) == len(ans) and t < ans):
            ans = t
    return ans
