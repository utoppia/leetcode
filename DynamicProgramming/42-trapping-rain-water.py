from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:

        st = [(0, height[0])]

        ans = pre = 0
        n = len(height)

        for i in range(1, n):
            while st and st[-1][1] <= height[i]:
                j, h = st.pop(-1)
                ans += (h - pre) * (i - j - 1)
                pre = h
            if st:
                ans += (height[i] - pre) * (i - st[-1][0] - 1)
            st.append((i, height[i]))
            pre = height[i]

        return ans
