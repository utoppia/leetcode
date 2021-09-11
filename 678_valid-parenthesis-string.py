class Solution:
  def checkValidString(self, s: str) -> bool:
    t1, t2 = [], []
    for i, ch in enumerate(s):
      if ch == '(':
        t1.append(i)
      if ch == '*':
        t2.append(i)
      if ch == ')':
        if t1:
          t1.pop(-1)
        elif t2:
          t2.pop(-1)
        else:
          return False
    while t1:
      p = t1.pop(-1)
      if not t2:
        return False
      else:
        q = t2.pop(-1)
        if p > q:
          return False

    return True
