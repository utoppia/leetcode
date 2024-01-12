class Solution:
  def licenseKeyFormatting(self, s: str, k: int) -> str:
    s = "".join(s.split('-'))
    s = s.upper()
    m = len(s) % k
    if m > 0:
      ret = [s[0:m]]
      s = s[m:]
    else:
      ret = []
    i = 0
    while i < len(s):
      ret.append(s[i:i+k])
      i += k

    return "-".join(ret)
