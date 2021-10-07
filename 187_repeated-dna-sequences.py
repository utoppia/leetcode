class Solution:
  def findRepeatedDnaSequences(self, s: str) -> List[str]:
    ans , S = [], {}
    for i in range(0,len(s)):
      if i + 10 > len(s): break
      if s[i:i+10] in S:
        ans.append(s[i:i+10])
      else :
        S[s[i:i+10]] = 0
    ans = list(set(ans))
    return ans

