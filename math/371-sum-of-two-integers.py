class Solution:
  def getSum(self, a: int, b: int) -> int:

    MASK = (1 << 32)
    MAX_INT = (1 << 31) - 1
    MASK2 = MAX_INT + 1

    while b != 0:
      carry = (a & b) << 1
      a = (a ^ b) % MASK
      b = carry % MASK

    if a & MASK2:
      return ~((a ^ MASK2) ^ MAX_INT)
    else:
      return a
