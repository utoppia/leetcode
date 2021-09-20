class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        # monotonic stack 
        # binary search

        def binary_search(st: List[int], nums: List[int], val: int) -> int:
            l, r = 0, len(st) - 1
            ans = 10 ** 10 # magic number, be careful!!
            while l <= r:
                mid = (l + r) // 2
                if nums[st[mid]] <= val:
                    ans = min(ans, st[mid])
                    r = mid - 1
                else:
                    l = mid + 1
            return ans if ans != 10 ** 10 else None

        ans = 0
        st = []
        for i in range(len(nums)):
            pre = binary_search(st, nums, nums[i])
            if pre != None:
                ans = max(ans, i - pre)

            if not st or nums[st[-1]] > nums[i]:
                st.append(i)
        return ans


