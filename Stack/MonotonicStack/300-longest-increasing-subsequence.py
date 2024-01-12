class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:

    if not nums:
      return 0

    st = [nums[0]]

    n = len(nums)
    
    for i in range(1, n):
      j = bisect.bisect_right(st, nums[i])

      if nums[i] == st[j-1]:
        continue

      if j == len(st):
        st.append(nums[i])
      else:
        if st[j] > nums[i]:
          st[j] = nums[i]

    return len(st)
      
