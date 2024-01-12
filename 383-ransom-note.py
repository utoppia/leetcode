class Solution:
  def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    return all([ch in (dic:= collections.Counter(magazine)) and cnt <= dic[ch] for ch, cnt in collections.Counter(ransomNote).items()])
