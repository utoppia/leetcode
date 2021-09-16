class Solution:
  def backspaceCompare(self, s: str, t: str) -> bool:
    def allpy(s: str) -> str:
      t = ''
      for ch in s:
        if ch == '#':
          t = t[:-1]
        else:
          t = t + ch
      return t

    return allpy(s) == allpy(t)
