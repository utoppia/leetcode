class Solution:
  def findNumberOfLIS(self, nums: List[int]) -> int:

    if not nums:
      return 0

    d = []
    st = []
    cnt = []
    
    for v in nums:
      i = bisect.bisect_left(d, v)

      c = 1
      if i > 0:
        # bisect can only solve increasing llist 
        # and I can not find a configure variable or something
        j = len(st[i-1]) - bisect.bisect_left(st[i-1][::-1], v)

        c = cnt[i - 1][-1] - cnt[i - 1][j]

      if i == len(d):
        st.append([v])
        d.append(v)
        cnt.append([0, c])
      else:
        st[i].append(v)
        d[i] = v
        cnt[i].append(cnt[i][-1] + c)

    return cnt[-1][-1]
      
