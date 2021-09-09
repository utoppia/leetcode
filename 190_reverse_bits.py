class Solution:
  def reverseBits(self, n: int) -> int:
    a = []
    while n or len(a) < 32:
      a.append(n % 2)
      n //= 2
    ans = 0
    for i in a:
      ans = ans * 2 + i
    return ans
