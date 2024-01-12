class Solution:
  def thirdMax(self, nums: List[int]) -> int:
    a = -10000000000000
    b=c=a
    for n in nums:
      if n > a:
        c,b,a=b,a,n
      elif n == a:
        c,b,a=c,b,a
      elif n > b:
        c,b,a=b,n,a
      elif n == b:
        c,b,a=c,b,a
      elif n >= c:
        c,b,a = n,b,a
            
    if c!=-10000000000000:
      return c
    else:
      return a
    

