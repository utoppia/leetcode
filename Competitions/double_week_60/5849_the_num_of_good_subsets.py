class Solution:
  def numberOfGoodSubsets(self, nums: List[int]) -> int:
    primes = [2,3,5,7,11,13,17,19,23,29]

    cnt = [0] * 31
    for num in nums:
      cnt[num] += 1
    
    cnt[1] = 2 ** cnt[1]
    
    MODULE = 10 ** 9 + 7
    ans = cnt[1]
    for k in primes:
      ans *= (cnt[k] + 1)

    s = ans
    ans -= cnt[1]

    p = s // (cnt[2] + 1)
    for i in [3,5,7,11,13]:
      ans += p // (cnt[i] + 1) * cnt[2 * i] 

    p = s // (cnt[3] + 1)
    for i in [5,7]:
      ans += p // (cnt[i] + 1) * cnt[3 * i]

    p = s // (cnt[2] + 1) 
    for i in [5,7,11,13]:
      for j in [5,7]:
        if j !=i:
          ans += p // (cnt[i]+1) // (cnt[3]+1) // (cnt[j]+1) * cnt[2*i] * cnt[3*j]

    p = s // ((cnt[2] + 1) * (cnt[3] + 1) * (cnt[5] + 1))
    ans += p * (cnt[30])


    return int(ans % MODULE)

