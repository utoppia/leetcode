class Solution:
  def fractionToDecimal(self, n: int, d: int) -> str:
    isFushu = (n < 0) ^ (d < 0)
    if n < 0 : n = -n
    if d < 0 : d = -d
    if n == 0: return str(0)
    ans = str(n//d) 
    n = n % d
    pos = 0
    mp = {}
    s = ""
    while True:
      if n == 0: break
      if n in mp:
        s = s[:mp[n]] + "(" + s[mp[n]:] + ")"
        break
      mp[n] = pos
      s += str(n*10 // d)
      n = n*10 % d
      pos += 1
    if s:
      ans = ans + "." + s
    if isFushu: 
      ans = "-" + ans
    return ans

