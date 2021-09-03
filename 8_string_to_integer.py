class Solution:
  def myAtoi(self, s: str) -> int:
    s = s.lstrip()
    minus = False
    if not s:
      return 0
    if s[0] == '-':
      minus = True
    if s[0] == '-' or s[0] == '+':
      s = s[1:]

    val = 0

    for ch in s:
      if val > (1 << 31):
        break
      k = ord(ch) - ord('0')
      if k >= 0 and k <= 9:
        val = val * 10 + k
      else:
        break

    if minus:
      val *= -1
    
    if val < -(1 << 31):
      val = -(1 << 31)
    if val >= (1 << 31):
      val = (1 << 31) - 1
    return val

