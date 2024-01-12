class Solution:
  def lengthOfLongestSubstring(self, s: str) -> int:
    dic = {}
    ans = 0
    p = -1
    for i in range(len(s)):
      if s[i] not in dic:
        ans = max(ans, i-p)
      else:
        ans = max(ans, min(i-dic[s[i]], i-p))
        p = max(p, dic[s[i]])
      dic[s[i]] = i
    return ans
