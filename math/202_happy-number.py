
class Solution:
  def isHappy(self, n: int) -> bool:

    def check(n: int, dk: Set) -> bool:
      if n == 1:
        return True
      if n in dk:
        return False

      dk.add(n)

      m = 0
      while n:
        m += (n % 10) ** 2
        n //= 10

      return check(m, dk)

    dk = set()
    return check(n, dk)
