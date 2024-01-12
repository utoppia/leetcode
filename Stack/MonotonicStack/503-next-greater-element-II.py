class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ans = [-1] * len(nums)
        st = []
        for _ in range(2):
            for i in range(len(nums)-1, -1, -1):
                while st and st[-1] <= nums[i]:
                    st.pop()

                if st:
                    ans[i] = st[-1]
                st.append(nums[i])

        return ans
