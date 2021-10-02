class Solution:
  def toHex(self, num: int) -> str:
    nMax = 0xffffffff
    if num < 0:
      num = num & nMax
    return str(hex(num))[2:]
