class Solution:
  def minSteps(self, n: int) -> int:

    is_prime = [True] * 100
    is_prime[0] = is_prime[1] = False

    is_prime[2] = True
    for i in range(2, 100):
      if is_prime[i]:
        j = i * i
        while j < 100:
          is_prime[j] = False
          j += i
    prime = [i for i in range(100) if is_prime[i]]
    
    ans = 0

    for p in prime:
      while n % p == 0:
        ans += p
        n //= p
      if n == 1:
        break

    if n > 1:
      ans += n
    
    return ans
