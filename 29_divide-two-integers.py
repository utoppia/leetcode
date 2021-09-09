class Solution:
  def divide(self, dividend: int, divisor: int) -> int:
    ans = 0
    flag = 0
    if dividend < 0:
      flag ^= 1
      dividend = - dividend
    if divisor < 0:
      flag ^= 1
      divisor = - divisor

    def find_best(dividend: int, divisor: int) -> int:
      if dividend < divisor:
        return 0
      if dividend == divisor:
        return 1
      cur = 1
      p = divisor
      while dividend >= p + p:
        cur += cur
        p += p
      return cur + find_best(dividend - p, divisor)

    ans = find_best(dividend, divisor)

    if flag:
      ans = - ans

    if ans < - 2 ** 31 or ans >= 2 ** 31:
      ans = 2 ** 31 - 1
    return ans
