class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        # monotonic stack
        # simillar with leetcode 402

        # stack 'st' stores the answer
        st = []

        # n is the length of nums
        n = len(nums)

        for i in range(n):
            digit = nums[i]
            while st and len(st) + n - i - 1 >= k and st[-1] > digit:
                st.pop()

            if len(st) < k:
                st.append(digit)

        return st
