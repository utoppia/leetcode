class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    return sorted(list(collections.Counter(s).items())) == sorted(list(collections.Counter(t).items()))
