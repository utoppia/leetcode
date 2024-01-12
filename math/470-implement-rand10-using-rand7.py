# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
  def rand10(self) -> int:
    a, b = 0, 0
    while True:
      a = rand7()
      b = rand7()
      if (a - 1) * 7 + b <= 40:
        break
    return 1 + ((a - 1) * 7 + b) % 10
